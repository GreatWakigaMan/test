#include <stdio.h>

int main() {
  int c;
  long b=0, t=0, e=1;

  // for(nc=0; getchar() != '\n'; ++nc){
  while((c=getchar()) != '\n'){
    if(c==' '){
      ++b;
    }
    if(c=='\t'){
      ++t;
    }
    if(c=='\n'){
      ++e;
    }
  }
  printf("Blank : %ld\n", b);
  printf("Tab   : %ld\n", t);
  printf("Enter : %ld\n", e);

  return 0;
}
