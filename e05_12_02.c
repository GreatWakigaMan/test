// entabをｍ行目からタブストップ数ｎで動作させる
// コマンドライン引数から+m -nの形で入力
// 日本語が怪しすぎて題意不明
#include<stdio.h>
#include<stdlib.h>

int tabnum = 0;
int spnum = 0;
void entab(int, int, int);

int main(int argc, char *argv[]){
	int tablin=1;				// 動作する行数(既定値:1)
	int tabstop=4;			// タブストップ字数(既定値:4)
	int inputchk;				// 入力チェック
	int mchk=0;					// +mの回数チェック
	int nchk=0;					// -nの回数チェック
	int chr=0;					// 行の文字数
	int space=0;				// 空白文字数
	int state_char=1;		// 0:空白 1:文字列
	int lin=1;					// 読み込み行数
	char c;
	
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
			else{
				inputchk = 0;
				break;
			}
			// m, nが2回以上入力されることを防ぐ
			if(mchk>1||nchk>1){
				inputchk = 0;
				break;
			}
			// 引数ミスを弾く
			if(tablin==0 || tabstop==0){
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
		while(1){
			c=getchar();
			if(c==' '){
				chr++;
				space++;
				state_char = 0;
			}
			// tabを読んだとき
			else if(c=='\t'){
				if(tablin>lin){
					printf("%c", c);
				}
				chr += tabstop - chr % tabstop;
				space += tabstop - chr % tabstop;
				state_char = 0;
			}
			// 改行を読んだとき
			else if(c=='\n'){
				if(tablin<=lin){
					if(state_char==0){
						entab(chr, space, tabstop);
					}
				}
				lin++;
				chr = 0;
				space = 0;
				state_char = 1;
				printf("%c", c);
			}
			// ファイル末尾
			else if(c==EOF){
				if(tablin<=lin){
					if(state_char==0){
						entab(chr, space, tabstop);
					}
				}
				break;
			}
			// 文字を読んだとき
			else{
				if(tablin<=lin){
					if(state_char==0){
						entab(chr, space, tabstop);
					}
				}
				chr++;
				space = 0;
				printf("%c", c);
	//			printf("%d", chr);
				state_char = 1;
			}
		}
		
		printf("\n\n");
		printf("tab   : %d\n", tabnum);
		printf("space : %d\n", spnum);
		
		return 0;
	}
}

// 空白から文字に入れ替わったとき、
// 行の文字数とスペースの数から最適なタブ・ブランクを挿入
void entab(int chr, int space, int tabstop){
	int st; // 空白開始時の行の文字数
	st = chr - space;
	if((tabstop-st%tabstop)>space){ // tabではオーバーなとき
		while(space>0){
			printf(" ");
			spnum++;
			space--;
		}
	}
	else{
		do{ // tabを一回以上は入れる
			printf("\t");
			tabnum++;
			space -= (tabstop-st%tabstop);
		}while(space>tabstop); // 二回目からはタブストップを残りスペースが上回れば入れる
		while(space>0){ // 残りはスペースで埋める
			printf(" ");
			spnum++;
			space--;
		}
	}
}

