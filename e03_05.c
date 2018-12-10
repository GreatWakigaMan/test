// atoiﾂて堋芝�ﾂ再�
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 16

void arrinit(char []);
void reverse(char []);
void itob(int, char [], int);

int main(){
  int n = 65535;
  int b = 16;
  char s[MAX];
  arrinit(s);

  itob(n, s, b);
  printf("n : %d\ns : %s\n", n, s);

  return 0;
}

// 配列初期化
void arrinit(char t[]){
  int i;
  for(i=0; i<MAX; i++){
    t[i] = '\0';
  }
}

// 配列反転
void reverse(char s[]){
  int c, i, j;
  for(i=0, j=strlen(s)-1; i<j; i++, j--){
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

// 数字→b進数文字列変換
void itob(int n, char s[], int b){
  int i, sign;
  if((sign=n)<0){
    n = -n;
  }
  i = 0;
  do{
    if(n%b+'0'<='9'){
      s[i++] = n % b + '0';
    }
    else{
      s[i++] = n % b + '0' + ('A' - '9' - 1);
    }
  } while((n /= b) > 0);
  if(sign<0){
    s[i++] = '-';
  }
  s[i] = '\0';
  reverse(s);
}
