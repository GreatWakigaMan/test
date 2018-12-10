#include <stdio.h>
#define IN  1
#define OUT 0

int main() {
  int c, state;

  state = OUT;
  while((c = getchar()) != '\n'){
    if(c == ' ' || c == '\n' || c == '\t'){
      state = OUT;
      printf("\n");
    }else{
      putchar(c);
      if(state == OUT)
        state = IN;
    }
  }

  return 0;
}
