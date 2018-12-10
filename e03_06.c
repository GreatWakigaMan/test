// atoi‚Ì©ì
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 64

void arrinit(char []);
void reverse(char []);
void itoa_(int, char [], int);

int main(){
  int n = -125;
  int f = 8;
  char s[MAX];
  int c;
  arrinit(s);

  itoa_(n, s, f);
  printf("n : %d\ns : %s\n", n, s);

  printf("    ");
  for(c=0; c<f; c++){
    printf("~");
  }

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
void itoa_(int n, char s[], int f){
  int i, j, sign;
  int len;
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
  len = strlen(s);
  for(j=0; j<f-len; j++){
    s[i++] = ' ';
  }
  s[i] = '\0';
  reverse(s);
}
