// タブ、改行を\n, \tに変換
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 256
#define FLAG 1  // 1 : 変換
                // 2 : 逆変換

void arrinit(char []);
void escape(char [], char []);
void escape_(char [], char []);

int main(){
  int i;
  char s[MAX], t[MAX];
  arrinit(s);
  arrinit(t);
  fgets(s, sizeof(s), stdin);
  for(i=0;i<=strlen(s);i++){
    printf("%d ", s[i]);
  }
  printf("\n");
  switch (FLAG) {
    case 1 :  escape(s, t);
              break;
    case 2 :  escape_(s, t);
              break;
  }

  printf("s : %s", s);
  printf("t : %s", t);

  return 0;
}

// タブ、改行 → \n, \t
void escape(char s[], char t[]){
  int i, j, len;
  len = strlen(s);
  for(i=0, j=0; i<len; i++, j++){
    switch(s[i]){
      case '\n' : t[j] = '\\';
                  t[++j] = 'n';
                  break;
      case '\t' : t[j] = '\\';
                  t[++j] = 't';
                  break;
      default : t[j] = s[i];
                break;
    }
  }
}

// \n, \t → タブ、改行
void escape_(char s[], char t[]){
  int i, j, len;
  len = strlen(s);
  for(i=0, j=0; i<len; i++, j++){
    if(s[i]=='\\'){
      switch(s[i+1]){
        case 'n' :  t[j] = '\n';
                    i++;
                    break;
        case 't' :  t[j] = '\t';
                    i++;
                    break;
        default : t[j] = s[i];
                  break;
      }
    }
    else{
      t[j] = s[i];
    }
  }
}

void arrinit(char t[]){
  int i;
  for(i=0; i<MAX; i++){
    t[i] = '\0';
  }
}
