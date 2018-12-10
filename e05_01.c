#include <stdio.h>
#include <ctype.h>
#define SIZE 100
#define BUFSIZE 100

int getch(void);
void ungetch(int);

int main(void)
{
  int n, array[SIZE], getint(int *);
  int i;

  for(n=0; n<SIZE && (getint(&array[n]))!=EOF;n++);

  for (i = 0; i < n; i++) {
    printf("%d\n", array[i]);
  }

  return 0;
}

// 入力から次の整数を取り出して*pnに入れる
int getint(int *pn){
  int c, sign;

  // 空白を飛ばす
  while(isspace(c = getch()));

  // 数字ではない
  if(!(isdigit(c) || c == EOF || c == '+' || c == '-')){
    ungetch(c);
    return 0;
  }

  // 符号チェック
  sign = (c == '-') ? -1 : 1;
  if(c == '+' || c == '-'){
    c = getch();
    if(!isdigit(c)){
      while(isspace(c = getch()));
    }
  }

  // 数字だけを拾う
  for(*pn = 0; isdigit(c); c = getch()){
    *pn = 10 * *pn + (c - '0');
  }
  *pn *= sign;
  if(c != EOF){
    ungetch(c);
  }
  return c;
}

char buf[BUFSIZE];
int bufp = 0;

int getch(void){
  return (bufp>0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
  if(bufp>=BUFSIZE){
    printf("ungetch: too many characters\n");
  }
  else{
    buf[bufp++] = c;
  }
}
