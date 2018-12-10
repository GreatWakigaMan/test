// if-elseを使わずに大文字→小文字変換
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lower(int);

int main(){
  int c;
  while((c=getchar()) != '\n'){
    c = lower(c);
    printf("%c", c);
  }
}

//大文字→小文字変換
int lower(int c){
  c = (c>='A')&&(c<='Z') ? c+32 : c;
  return c;
}
