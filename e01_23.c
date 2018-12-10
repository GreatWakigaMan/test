//コメントを除去
#include <stdio.h>
#include <stdlib.h>
#define MAX 256

void del_digit(char [], int);

int main(){
  FILE *fp1, *fp2;
  char *fname1 = "./input.txt";
  char *fname2 = "./output.txt";
  int c, d;
  int i;
  int end;
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

  while((c=fgetc(fp1)) != EOF){
    if(c=='/'){
      d=fgetc(fp1);
      if(d=='/'){ // "//"の処理
        //行削除
        while(((c=fgetc(fp1)) != '\n') && ((c=fgetc(fp1)) != EOF));
        fprintf(fp2, "\n");
      }
      else if(d=='*'){ // "/*"の処理
        //コメント削除
        for(i=0; (c=fgetc(fp1))!=EOF; i++){
          end = 0;
          if(c=='*'){
            d=fgetc(fp1);
            if(d=='/'){
              end = 1;
            }
          }
          if(end==1){
            break;
          }
        }
      }
      else{ // "//", "/*"以外を出力
        fprintf(fp2, "%c%c", c, d);
      }
    }
    else{ // "/"以外を出力
      fprintf(fp2, "%c", c);
    }
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
