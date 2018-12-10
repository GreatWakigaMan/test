// 空白を最小のtab/blancで置き換える
// e01_21<hoge.txt として使用
#include<stdio.h>
#include<stdlib.h>
#define TABSTOP 4

int tabnum = 0;
int spnum = 0;
void entab(int, int, int);

int main(void){
	int lin=0; // 行の文字数
	int space=0; // 空白文字数
	int state_char=1; // 0:空白 1:文字列
	char c;
	
	// 処理
	while(1){
		c=getchar();
		if(c==' '){
			lin++;
			space++;
			state_char = 0;
		}
		// tabを読んだとき
		else if(c=='\t'){
			lin += TABSTOP - lin % TABSTOP;
			space += TABSTOP - lin % TABSTOP;
			state_char = 0;
		}
		// 改行を読んだとき
		else if(c=='\n'){
			if(state_char==0){
				entab(lin, space, TABSTOP);
			}
			lin = 0;
			space = 0;
			state_char = 1;
			printf("%c", c);
		}
		// ファイル末尾
		else if(c==EOF){
			if(state_char==0){
				entab(lin, space, TABSTOP);
			}
			break;
		}
		// 文字を読んだとき
		else{
			if(state_char==0){
				entab(lin, space, TABSTOP);
			}
			lin++;
			space = 0;
			printf("%c", c);
//			printf("%d", lin);
			state_char = 1;
		}
	}
	
	printf("\n\n");
	printf("tab   : %d\n", tabnum);
	printf("space : %d\n", spnum);
	
	return 0;
}

// 空白から文字に入れ替わったとき、
// 行の文字数とスペースの数から最適なタブ・ブランクを挿入
void entab(int lin, int space, int tabstop){
	int st; // 空白開始時の行の文字数
	st = lin - space;
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
			space -= tabstop;
		}while(space>tabstop); // 二回目からはタブストップを残りスペースが上回れば入れる
		while(space>0){ // 残りはスペースで埋める
			printf(" ");
			spnum++;
			space--;
		}
	}
}

