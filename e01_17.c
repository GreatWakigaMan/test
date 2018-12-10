//80字以上の行を印字
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX   256
#define PSIZE 80

//配列初期化
void arrinit(char []);

int main(){
  FILE *fp1;
  char *fname1 = "./input.txt";
  int c;
  int i=0;
  char t[MAX];
  arrinit(t);

  // ファイルオープン・読み込み用
  fp1 = fopen(fname1, "r");
  if(fp1 == NULL) {
    printf("%s file not open!\n", fname1);
    return -1;
  }

  // 80字以上の行を探す
  while((c=fgetc(fp1)) != EOF){
    //改行を見つけた
    if(c=='\n'){
      if(i>=PSIZE){
        printf("i=%d, %s\n", i, t);
      }
      i = 0;
      arrinit(t);
    }
    // 改行以外をカウント
    else{
      t[i] = c;
      i++;
    }
  }

  // ファイルクローズ
  fclose(fp1);

  return 0;
}

void arrinit(char t[]){
  int i;
  for(i=0; i<MAX; i++){
    t[i] = '\0';
  }
}
