#include <stdio.h>
#define L   10
#define IN  1
#define OUT 0

int main(){
  int i, j, wlen[L+1], c, word=0;

  for(i=0; i<L+1; ++i){
    wlen[i] = 0;
  }

  while((c = getchar()) != '\n'){
    //空白時処理
    if(c == ' ' || c == '\n' || c == '\t'){
      ++wlen[word];
      word = 0;
    }
    //文字が続いたときの処理
    else{
      ++word;
    }
  }
  ++wlen[word];

  for(i=1; i<L; ++i){
    printf("%d : ", i);
    for(j=1; j<=wlen[i]; j++){
      printf("l");
    }
    printf("\n");
  }
}
