// atoi‚Ì©ì
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 8

void arrinit(char []);
void reverse(char []);
void it0a(int, char []);

int main(){
  int n = -16777216;
  char s[MAX];
  arrinit(s);

  it0a(n, s);
  printf("n : %d\ns : %s\n", n, s);

  return 0;
}

// ”z—ñ‰Šú‰»
void arrinit(char t[]){
  int i;
  for(i=0; i<MAX; i++){
    t[i] = '\0';
  }
}

// ”z—ñ”½“]
void reverse(char s[]){
  int c, i, j;
  for(i=0, j=strlen(s)-1; i<j; i++, j--){
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

// ”š¨•¶š—ñ•ÏŠ·
void it0a(int n, char s[]){
  int i, sign;
  if((sign=n)<0){
    n = -n;
  }
  i = 0;
  do{
    s[i++] = n % 10 + '0';
  } while((n /= 10) > 0);
  if(sign<0){
    s[i++] = '-';
  }
  s[i] = '\0';
  reverse(s);
}
