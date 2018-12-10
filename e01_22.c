//n文字までにある最後の非ブランク文字の後で折り返す
#include <stdio.h>
#include <stdlib.h>
#define N   20

void del_digit(char [], int);

int main(){
  FILE *fp1, *fp2;
  char *fname1 = "./input.txt";
  char *fname2 = "./output.txt";
  int c;
  int i=0;
  // char t[N];

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

  // 改行処理・これだと非ブランクに対応できない
  while((c=fgetc(fp1)) != EOF){
    if(!(i==0) && i%N==0){
      fprintf(fp2, "\n");
    }
    i++;
    fprintf(fp2, "%c", c);
  }

  // ファイルクローズ
  fclose(fp1);
  fclose(fp2);

  return 0;
}

//配列tのj番目の要素を削除
void del_digit(char t[], int j){
  while(t[j]!=EOF){
    t[j] = t[j+1];
    j++;
  }
  t[j] = EOF;
}
