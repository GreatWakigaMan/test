// Ä‹Aitoa
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

void itoa_rec(int, char []);
int i=0;

int main(void){
  int n = -50;
  char s[MAX] = {};

  itoa_rec(n, s);

  printf("%d\n", n);
  printf("%s\n", s);
}

void itoa_rec(int n, char s[]){
  if(n<0){
    s[i++] = '-';
    n = -n;
  }
  if(n/10){
    itoa_rec(n/10, s);
  }
  s[i++] = n % 10 + '0';
}
