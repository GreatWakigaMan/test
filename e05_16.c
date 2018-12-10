#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAXLINES	5000
#define MAXLEN		100
#define ALLOCSIZE	10000
char *lineptr[] = {};

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

int readlines(char **, int, int, int);
void writelines(char **, int, int);
int getline_(char *, int, int, int);
void qsort_(void **, int, int, int (*)(void *, void *));
int numcmp(char *, char *);
char *alloc(int);

int main(int argc, char *argv[]){
	int nlines;
	int numeric = 0;
	int sorttype = 0;
	int fold = 0;
	int dorder = 0;
	int err = 0;
	
	// 第二引数以降のargvの一文字目をチェック
	while(--argc>0 && (*++argv)[0]=='-'){
		switch((*argv)[1]){
		case 'n':
			numeric = 1;
			break;
		case 'r':
			sorttype = 1;
			break;
		case 'f':
			fold = 1;
			break;
		case'd':
			dorder = 1;
			break;
		default:
			err = 1;
			break;
		}
	}
	if(err==1){
		printf("ex: e05_15 -r -n -f < hoge.txt\n");
		return -1;
	}
	printf("numeric : %d\nsorttype: %d\nfold    : %d\ndorder  : %d\n\n", numeric, sorttype, fold, dorder);
	
	printf("*** readlines ***\n");
	if((nlines = readlines(lineptr, MAXLINES, fold, dorder)) >= 0){
		qsort_((void **) lineptr, 0, nlines-1, (int (*)(void *, void *))(numeric ? numcmp : strcmp));
		printf("\n*** sortdatas ***\n");
		writelines(lineptr, nlines, sorttype);
		return 0;
	}
	else{
		printf("input too big to sort\n");
		return 1;
	}
}

int readlines(char *lineptr[], int maxlines, int fold, int dorder){
	int len, nlines;
	char *p, lin[MAXLEN];
	nlines = 0;
	while((len = getline_(lin, MAXLEN, fold, dorder)) > 0){
		if(nlines >= maxlines || (p = alloc(len)) == NULL){
			return -1;
		}
		else{
			lin[len-1] = '\0';
			strcpy(p, lin);
			lineptr[nlines++] = p;
			printf("%s\n", p);
 		}
	}
	return nlines;
}

void writelines(char *lineptr[], int nlines, int sorttype){
	if(sorttype==0){
		while(nlines-->0){
			printf("%s\n", *lineptr++);
		}
	}
	if(sorttype==1){
		int lin;
		lin = nlines;
		while(--lin>0){
			*lineptr++;
		}
		while(lin++<nlines){
			printf("%s\n", *lineptr--);
		}
	}
}

// 文字列ｓの長さ(＝文字数)を返す
int getline_(char *s, int lim, int fold, int dorder){
	 int c, i;
	for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i){
		if(dorder==0){
			if(fold==1){
				c = tolower(c);
			}
			*(s+i) = c;
		}
		// alphabet, num, blank以外を読み飛ばす
		else{
			if(isalnum(c) || isblank(c)){
				if(fold==1){
					c = tolower(c);
				}
				*(s+i) = c;
			}
			else{
				i--;
			}
		}
	}
	if(c=='\n'){
		*(s+i) = c;
		++i;
	}
	*(s+i) = '\0';
	
	return i;
};

// v[left]~v[right]を昇順ソートする
// compにはstrcmpもしくはnumcmpが入る
void qsort_(void *v[], int left, int right, int (*comp)(void *, void *)){
	int i, last;
	void swap(void *v[], int, int);
	
	if(left >= right){
		return;
	}
	swap(v, left, (left+right)/2);
	last = left;
	for(i=left+1; i<=right; i++){
		if((*comp)(v[i], v[left]) < 0){
			swap(v, ++last, i);
		}
	}
	swap(v, left, last);
	qsort_(v, left, last-1, comp);
	qsort_(v, last+1, right, comp);
}

// s1, s2を数値比較する
int numcmp(char *s1, char *s2){
	double v1, v2;
	
	v1 = atof(s1);
	v2 = atof(s2);
	if(v1<v2){
		return -1;
	}
	else if(v1>v2){
		return 1;
	}
	else{
		return 0;
	}
}

void swap(void *v[], int i, int j){
	void *temp;
	
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

char *alloc(int n){
	if(allocbuf + ALLOCSIZE - allocp >= n){
		allocp += n;
		return allocp - n;
	}
	else{
		return 0;
	}
}
