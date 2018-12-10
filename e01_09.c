#include <stdio.h>

int main() {
  int c=0;

  while(c != '\n'){
    c = getchar();
    if(c == ' '){
      putchar(c);
      c = getchar();
      while(c == ' '){
        c = getchar();
      }
    }
    putchar(c);
  }

  return 0;
}
