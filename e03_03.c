// a-z、0-9の展開
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 256

void arrinit(char []);
void expand(char [], char []);

int main(){
  // int i;
  char s[MAX], t[MAX];
  arrinit(s);
  arrinit(t);
  // fgets(s, sizeof(s), stdin);
  // for(i=0;i<=strlen(s);i++){
  //   printf("%d ", s[i]);
  // }
  // printf("\n");

  expand(s, t);

  // printf("\n");

  printf("s : %s", s);
  printf("t : %s", t);

  return 0;
}

//a-z, 0-9の展開
void expand(char s[], char t[]){
  int i, j, k, len;
  char bef, aft;
  len = strlen(s);
  for(i=j=0; i<=len-1; i++, j++){
    if(s[i]=='-'){
      bef = s[i-1];
      aft = s[i+1];
      if(i==0 || i==len){ //最初or最後の文字
        // printf("1");
        t[j] = s[i];
      }else if(bef<aft && bef>='a' && bef<='z' && aft>='a' && aft<='z'){
        // printf("2");
        // a-zのような形を確認
        for(k=1; k<aft-bef; k++, j++){
          t[j] = bef + k;
        }
        j--; //インクリメントを戻す
      }else if(bef<aft && bef>='0' && bef<='9' && aft>='0' && aft<='9'){
        // printf("3");
        // 0-9のような形を確認
        for(k=1; k<aft-bef; k++, j++){
          t[j] = bef + k;
        }
        j--;//インクリメントを戻す
      }else{
        // printf("4");
        t[j] = s[i];
      }
    }else{ //一般の文字
      // printf("5");
      t[j] = s[i];
    }
  }
}

// 配列初期化
void arrinit(char t[]){
  int i;
  for(i=0; i<MAX; i++){
    t[i] = '\0';
  }
}
