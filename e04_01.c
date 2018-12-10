// s[]においてtが一番最後に現れる位置を返す
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <tgmath.h>
#define MAX 64

int strrindex(char [], char);

int main() {
  char s[MAX] = "hollywood zakoshi show";
  char t = 'l';
  int index;

  index = strrindex(s, t);
  printf("s : %s\n", s);
  printf("t : %c\n", t);
  printf("%dth\n", index);

  return 0;
}

// s[]で最後に現れるtの位置
int strrindex(char s[], char t){
  int r, len, i;
  len = strlen(s);

  for(i=len-1; i>=0; i--){
    if(s[i]==t){
      r = i;
      break;
    }
  }
  return r+1; // 配列番号から文字番号に合わせる
}
