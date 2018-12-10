#include <stdio.h>

int main() {
  int c;

  // for(nc=0; getchar() != '\n'; ++nc){
  while((c=getchar()) != '\n'){
    if(c=='\t'){
      printf("\\t");
    }
    if(c=='\b'){
      printf("\\b");
    }
    if(c=='\\'){
      printf("\\\\");
    }
    else{
      putchar(c);
    }
  }

  return 0;
}
