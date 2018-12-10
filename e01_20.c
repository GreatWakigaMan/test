//タブをタブストップまでの空白に置き換える
#include <stdio.h>
#include <stdlib.h>
#define MAX 256
#define TS  5   //タブストップの文字数

// void del_digit(char [], int);
// void ins_digit(char [], int, char);

int main(){
  FILE *fp1, *fp2;
  char *fname1 = "./input.txt";
  char *fname2 = "./output.txt";
  int c;
  int spcount;
  int i, j;
  i = j = 0;

  // ファイルオープン・読み込み用
  fp1 = fopen(fname1, "r");
  if(fp1 == NULL) {
    printf("%s file not open!\n", fname1);
    return -1;
  }

  // ファイルオープン・書き込み用
  fp2 = fopen(fname2, "w");
  if(fp2 == NULL) {
    printf("%s file not open!\n", fname2);
    return -1;
  }

  // while((c=fgetc(fp1))!=EOF)
  // printf("%d ", c);

  // 抽出
  while((c=fgetc(fp1)) != EOF){
    i++;
    if(c==9){
      spcount = TS - i % TS;
      i = i + spcount;
      for(j=0; j<spcount; j++){
        fprintf(fp2, "%c", ' ');
      }
    }
    else if(c=='\n'){
      i = 0;
      fprintf(fp2, "%c", c);
    }
    else{
      fprintf(fp2, "%c", c);
    }
  }

  // ファイルクローズ
  fclose(fp1);
  fclose(fp2);

  return 0;
}

// //配列tのj番目の要素を削除
// void del_digit(char t[], int j){
//   while(t[j]!=EOF){
//     t[j] = t[j+1];
//     j++;
//   }
//   t[j] = EOF;
// }
//
// //配列tのj番目に文字cを挿入
// void ins_digit(char t[], int j, char c){
//   int k;
//   for(k=MAX-1; k>j; k--){
//     t[k] = t[k-1];
//   }
//   t[k] = c;
// }
