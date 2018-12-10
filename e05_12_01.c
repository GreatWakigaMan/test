// detabをｍ行目からタブストップ数ｎで動作させる
// コマンドライン引数から+m -nの形で入力
// 日本語が怪しすぎて題意不明
#include<stdio.h>
#include<stdlib.h>

void detab(int, int);

int main(int argc, char *argv[]){
	int tablin=1;				// 動作する行数(既定値:1)
	int tabstop=4;			// タブストップ字数(既定値:4)
	int inputchk;				// 入力チェック
	int mchk=0;					// +mの回数チェック
	int nchk=0;					// -nの回数チェック
	
	// 引数チェック
	if(argc==1){
		inputchk = 1;
	}
	else if(argc<=3){
		inputchk = 1;
		while(*++argv){
			if(**argv=='+'){
				tablin = atoi(*argv);
				mchk++;
			}
			else if(**argv=='-'){
				tabstop = -1 * atoi(*argv);
				nchk++;
			}
			// m, nが2回以上入力されることを防ぐ
			if(mchk>1||nchk>1){
				inputchk = 0;
				break;
			}
		}
	}
	else{
		inputchk = 0;
	}
	printf("m: %d, n: %d\n\n", tablin, tabstop);
	
	// 引数が誤っていたら終了
	if(inputchk==0){
		printf("Usage: e05_12_01 +m -n\n");
		printf("m: line\n");
		printf("n: tabstop\n");
		return 0;
	}
	// 正しければdetab処理
	else{
		detab(tablin, tabstop);
		return 0;
	}
}

void detab(int tablin, int tabstop){
	int lin=1; // 読み込み行数
	int spnum, chr=0, blanknum=0;
	char c;
	
	// 処理
	while((c=getchar())!=EOF){
		// tabを読んだとき
		if(c=='\t'){
			if(tablin<=lin){
				spnum = tabstop - chr % tabstop;
				while(spnum>0){
					printf(" ");
					blanknum++;
					spnum--;
				}
				chr = 0;
			}
			else{
				printf("%c", c);
				chr = 0;
			}
		}
		// 改行を読んだとき
		else if(c=='\n'){
			lin++;
			chr = 0;
			printf("%c", c);
		}
		// その他を読んだとき
		else{
			chr++;
			printf("%c", c);
		}
	}
	
	printf("/n/nblanknum : %d\n", blanknum);
}
