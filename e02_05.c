// s2中の任意の文字がs1中何文字目に出るか？
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

int any(char [], char [], int []);
void del_digit(char [], int);
void arrinit(char []);

int main() {
  char s1[MAX], s2[MAX] = "abcd";
  int i;
  int index[MAX];
  int flag;

  scanf("%s", s1);
  flag = any(s1, s2, index);
  if(flag==0){
    for(i=0; i<strlen(s2); i++){
      if(index[i]+1>0 && index[i]<strlen(s1)){
        printf("%c : %d文字目\n", s2[i], index[i]+1);
      }
      else{
        printf("%c : no match.\n", s2[i]);
      }
    }
  }
  else{
    printf("no match.");
  }

  return 0;
}

// s2の任意の文字がs1の何番目に現れるか
int any(char s1[], char s2[], int index[]){
  int i, j;
  int count1, count2;
  int flag = -1;
  i = strlen(s2); // s2の長さ
  for(count1=0; count1<=i; count1++){
    j = strlen(s1); // s1の長さ
    for(count2=0; count2<=j; count2++){
      // s1のcount2文字目とs2のcount1文字目が一致していたら保存
      if(s1[count2]==s2[count1]){
        index[count1] = count2;
        flag = 0;
        break;
      }
    }
  }
  return flag;
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
