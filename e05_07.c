#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define ALLOCSIZE 10000

char *lineptr[] = {};

int readlines(char **, int, char *);
void writelines(char **, int);
void qsort(char **, int, int);

// 入力行をソートする
int main(void){
	int nlines; // 読み込みの入力行数
	char alloc[ALLOCSIZE] = {};
	
	if((nlines = readlines(lineptr, MAXLINES, alloc)) >= 0){
//		printf("nlines: %d\n", nlines);
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	}
	else{
		printf("error: input too big to sort\n");
		return -1;
	}
}

#define MAXLEN 1000
int getline_(char *, int);

// 入力行を読み込み
int readlines(char *lineptr[], int maxlines, char *alloc){
	int len, nlines, alloclen=0;
	char line_[MAXLEN];
	nlines = 0;
	while((len = getline_(line_, MAXLEN)) > 0){
		if(nlines >= maxlines && alloclen > ALLOCSIZE){
			return -1;
		}
		else{
			line_[len-1] = '\0';
			strcpy(&alloc[alloclen], line_);
			lineptr[nlines++] = &alloc[alloclen];
			alloclen += len;
		}
	}
	return nlines;
}

// 入力行を書き出し
void writelines(char *lineptr[], int nlines){
	while(nlines-->0){
		printf("%s\n", *lineptr++);
	}
}

int getline_(char *s, int lim){
	 int c, i;
	for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i){
		*(s+i) = c;
	}
	if(c=='\n'){
		*(s+i) = c;
		++i;
	}
	*(s+i) = '\0';
	
	return i;
};

// v[left], ..., v[right]を昇順にソートする
void qsort(char *v[], int left, int right){
	int i, last;
	void swap(char **, int, int);
	
	if(left >= right){
	return;
	}
	swap(v, left, (left+right)/2);
	last = left;
	for(i=left+1; i<= right; i++){
		if(strcmp(v[i], v[left]) < 0){
			swap(v, ++last, i);
		}
	}
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

// v[i], v[j]を交換する
void swap(char *v[], int i, int j){
	char *temp;
	
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
