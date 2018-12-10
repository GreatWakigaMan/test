#include <stdio.h>

void strcat_(char *, char *);

int main(void)
{
  char s[] = "I am ";
  char t[] = "a cat.";

  printf("s = %s\n", s);
  printf("t = %s\n", t);

  strcat_(s, t);

  printf("s+t = %s", s);

  return 0;
}

void strcat_(char *s, char *t){
  while(*s){
    s++;
  }
  while((*s++ = *t++));
  *s++ = '\0';
}
