// Ä‹Areverse
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

void reverse_rec(char [], char []);
int i=0;

int main(void){
  char s[MAX] = "tamago";
  char t[MAX] = {};

  reverse_rec(s, t);

  printf("%s\n", s);
  printf("%s\n", t);
}

void reverse_rec(char s[], char t[]){
  int n;

  n = strlen(s) - i;
  t[i] = s[n-1];

  if(i<strlen(s)-1){
    i++;
    reverse_rec(s, t);
  }
}
