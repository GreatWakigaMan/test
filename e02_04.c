// s2中の文字をs1から除去
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

void squeeze(char [], char[]);
void del_digit(char [], int);
void arrinit(char []);

int main() {
  char s1[MAX], s2[MAX] = "abcd";
  int i;

  scanf("%s", s1);
  squeeze(s1, s2);
  for(i=0; i<strlen(s1)-1; i++){
    printf("%c", s1[i]);
  }

  return 0;
}

// sからtに含まれる文字をすべて取り除く
void squeeze(char s1[], char s2[]){
  int i, j;
  int count1, count2;
  i = strlen(s2); // s2の長さ
  for(count1=0; count1<=i; count1++){
    j = strlen(s1); // s1の長さ
    for(count2=0; count2<=j; count2++){
      // s1のcount2文字目とs2のcount1文字目が一致していたら削除
      if(s1[count2]==s2[count1]){
        del_digit(s1, count2);
        count2--;
      }
    }
  }
}

//配列tのj番目の要素を削除
void del_digit(char t[], int j){
  while(t[j]!=EOF){
    t[j] = t[j+1];
    j++;
  }
  t[j] = EOF;
}

//配列の初期化
void arrinit(char t[]){
  int i;
  for(i=0; i<MAX; i++){
    t[i] = '\0';
  }
}
