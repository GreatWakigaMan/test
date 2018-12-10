//ブランク・タブ・空白行を削除
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX   256

//配列初期化
void arrinit(char []);

int main(){
  FILE *fp1, *fp2;
  char *fname1 = "./input.txt";
  char *fname2 = "./output.txt";
  int c;
  int i=0, j=0, flag=0; //空白行管理用
  char t[MAX];
  arrinit(t);

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

  // 末尾の空白および空白行削除
  while((c=fgetc(fp1)) != EOF){
    if(c=='\n'){
      // 空白行でないなら出力
      if(flag==1){
        fprintf(fp2, "%s\n", t);
      }
      // 末尾の空白削除
      else{
        // 文字列の後ろから空白・ブランクを削除
        for(j=i; j>=0; j++){
          if(t[j]==' ' || t[j]=='\t'){
            t[j] = '\0';
          }
          else{
            break;
          }
        }
        fprintf(fp2, "%s\n", t);
      }
      // 初期化
      flag = 0;
      i = 0;
      arrinit(t);
    }
    else if(c==' ' || c=='\t'){
      // 空白ならflagを動かさない
      t[i] = c;
      i++;
    }
    else{
      // その他の行
      flag = 1;
      t[i] = c;
      i++;
    }
  }
  fprintf(fp2, "%s", t);

  // ファイルクローズ
  fclose(fp1);
  fclose(fp2);

  return 0;
}

void arrinit(char t[]){
  int i;
  for(i=0; i<MAX; i++){
    t[i] = '\0';
  }
}
