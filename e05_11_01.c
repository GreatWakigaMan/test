// tabを半角スペースにする
// 引数でタブストップ字数を入力
#include<stdio.h>
#include<stdlib.h>

void detab(int);

int main(int argc, char *argv[]){
	int tabstop;
	
	// 引数チェック
	if(argc==1){
		tabstop = 4;
	}
	else if(argc==2){
		tabstop = atoi(argv[1]);
		if(tabstop<1){
			printf("Usage: e05_11_01 tabstop\n");
			return 0;
		}
	}
	else{
		printf("Usage: e05_11_01 tabstop\n");
		return 0;
	}
	
	detab(tabstop);
	
	return 0;
}

void detab(int tabstop){
	int spnum, lin=0, blanknum=0;
	char c;
	
	// 処理
	while((c=getchar())!=EOF){
		// tabを読んだとき
		if(c=='\t'){
			spnum = tabstop - lin % tabstop;
			while(spnum>0){
				printf(" ");
				blanknum++;
				spnum--;
			}
			lin = 0;
		}
		// 改行を読んだとき
		else if(c=='\n'){
			lin = 0;
			printf("%c", c);
		}
		// その他を読んだとき
		else{
			lin++;
			printf("%c", c);
		}
	}
	
	printf("\n\n");
	printf("blanknum : %d\n", blanknum);
}
