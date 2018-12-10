//•¶Žš—ñ”½“]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

void reverse(char []);

int main(){
  char t[MAX];
  int i;
  for(i=0; i<MAX; i++){
    t[i] = '\0';
  }

  scanf("%s", t);
  reverse(t);
  printf("%s\n", t);

  return 0;
}

//•¶Žš—ñt‚Ì”½“]
void reverse(char t[]){
  int i, j;
  j = strlen(t)-1;
  char s[j];

  for(i=j; i>=0; i--){
    s[i] = t[j-i];
  }
  for(i=0; i<=j; i++){
    t[i] = s[i];
  }
}
