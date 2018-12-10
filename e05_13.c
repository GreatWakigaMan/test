// 入力の最後のn行を出力する関数tail
// コマンドライン引数から-nの形で行数指定
// e05_13<hoge.txt -n
#include<stdio.h>
#include<stdlib.h>
#define MAXCHAR 100			// 一行の最大文字数
#define MAXLINE 100			// 最大行数

void tail(int);

int main(int argc, char *argv[]){
	int n=10;
	int inputchk;
	
	// 引数チェック
	if(argc==1){
		inputchk = 1;
	}
	else if(argc==2){
		// 第一引数が"-"で始まってる？
		if(**++argv=='-'){
			n = -1 * atoi(*argv);
			if(n==0){
				inputchk = 0;
			}
			else{
				inputchk = 1;
			}
		}
		else{
			inputchk = 0;
		}
	}
	else{
		inputchk = 0;
	}
	
	// 入力が不正確であればエラーを返す
	if(inputchk==0){
		printf("Usage: e05_13 -n\n");
		printf("n: line\n");
	}
	// 正しければtailを実行
	else{
		printf("n: %d\n", n);
		tail(n);
	}
}

void tail(int n){
	char c;															// 読み取った文字
	char data[MAXLINE+1][MAXCHAR+1]={};	// データ格納
	int lin=1;													// 現在の行数
	int chr=0;													// 一行内の現在の文字数
	int i;															// ループ用
	int act;														// 実際に動作させる行数
	// ファイル末尾までデータ読み込み
	while((c=getchar())!=EOF){
		chr++;
		if(chr<MAXCHAR){
			*(*(data+lin)+chr-1) = c;
		}
		else{
			printf("Too many char.\n");
			return;
		}
		// 改行処理
		if(c=='\n'){
			chr = 0;
			lin++;
			if(lin>MAXLINE){
				printf("Too many line.\n");
				return;
			}
		}
	}
	// 末尾からn行戻ったact行目を探す
	if(lin<n){
		n = lin;
	}
	act = lin - n + 1;
	// act行目から末尾までを出力
	for(i=act; i<lin+1; i++){
		printf("%s", *(data+i));
	}
}
