#include <stdio.h>

int main() {
  int c;

  c = getchar();
  while(c != '\n'){
    printf("%d", c != '\n');
    // putchar(c);
    c = getchar();
  }

  return 0;
}
