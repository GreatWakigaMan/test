#include <stdio.h>

void strncpy_(char *, char *, int);
void strncat_(char *, char *, int);
int strncmp_(char *, char *, int);

int main(void)
{
  printf("----------strncpy----------\n");
  char s1[] = "";
  char t1[] = "tamagoyaki tabetai";

  printf("s = %s\n", s1);
  printf("t = %s\n", t1);

  strncpy_(s1, t1, 6);

  printf("strncpy : %s\n", s1);

  printf("\n----------strncat----------\n");
  char s2[] = "tamagoyaki t";
  char t2[] = "abetaiyoooooooo";

  printf("s = %s\n", s2);
  printf("t = %s\n", t2);

  strncat_(s2, t2, 6);

  printf("strncat : %s\n", s2);

  printf("\n----------strncmp----------\n");
  char s3[] = "tamagoyaki999";
  char t3[] = "tamagoyaki999";
  int cmp;

  printf("s = %s\n", s3);
  printf("t = %s\n", t3);

  cmp = strncmp_(s3, t3, 15);

  printf("strncmp : %d\n", cmp);


  return 0;
}

// tの先頭の(最大)n文字をsにコピー
void strncpy_(char *s, char *t, int n){
  int i=0; // tの文字数
  while(*t){
    *s = *t;
    i++;
    s++;
    t++;
    if(n<i+1){
      break;
    }
  }
  *s++ = '\0';
}

// tの先頭の(最大)n文字をsの末尾にコピー
void strncat_(char *s, char *t, int n){
  int i=0; // tの文字数
  while(*s){
    s++;
  }
  while(*s++=*t++){
    i++;
    if(n<i+1){
      break;
    }
  }
  *s++ = '\0';
}

int strncmp_(char *s, char *t, int n){
  while(n>0){
    if(*s==*t);
    if(*s>*t){
      return 1;
    }
    if(*s<*t){
      return -1;
    }
    s++;
    t++;
    n--;
    if(*s=='\0' || *t=='\0'){
      return 0;
    }
  }
  return 0;
}
