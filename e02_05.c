// s2’†‚Ì”CˆÓ‚Ì•¶š‚ªs1’†‰½•¶š–Ú‚Éo‚é‚©H
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
        printf("%c : %d•¶š–Ú\n", s2[i], index[i]+1);
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

// s2‚Ì”CˆÓ‚Ì•¶š‚ªs1‚Ì‰½”Ô–Ú‚ÉŒ»‚ê‚é‚©
int any(char s1[], char s2[], int index[]){
  int i, j;
  int count1, count2;
  int flag = -1;
  i = strlen(s2); // s2‚Ì’·‚³
  for(count1=0; count1<=i; count1++){
    j = strlen(s1); // s1‚Ì’·‚³
    for(count2=0; count2<=j; count2++){
      // s1‚Ìcount2•¶š–Ú‚Æs2‚Ìcount1•¶š–Ú‚ªˆê’v‚µ‚Ä‚¢‚½‚ç•Û‘¶
      if(s1[count2]==s2[count1]){
        index[count1] = count2;
        flag = 0;
        break;
      }
    }
  }
  return flag;
}

//”z—ñt‚Ìj”Ô–Ú‚Ì—v‘f‚ğíœ
void del_digit(char t[], int j){
  while(t[j]!=EOF){
    t[j] = t[j+1];
    j++;
  }
  t[j] = EOF;
}

//”z—ñ‚Ì‰Šú‰»
void arrinit(char t[]){
  int i;
  for(i=0; i<MAX; i++){
    t[i] = '\0';
  }
}
