#include <stdio.h>
#define IN  1
#define OUT 0

int main() {
  int c, state;
  int nl, nw, nc;

  state = OUT;
  nl = nw = nc = 0;
  while((c = getchar()) != '\n'){
    ++nc; //文字数カウント
    if(c == '\n')
      ++nl; //行数カウント
    if(c == ' ' || c == '\n' || c=='\t')
      state = OUT;
    else if(state == OUT){
      state = IN;
      ++nw; //単語数カウント
    }
  }
  printf("%d %d %d\n", nl, nw, nc);

  return 0;
}
