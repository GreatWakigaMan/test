#include <stdio.h>
#include <ctype.h>
#define SIZE 100
#define BUFSIZE 100

int getch(void);
void ungetch(int);

int main(void)
{
  int n, getfloat(float *);
  float array[SIZE];
  int i;

  for(n=0; n<SIZE && (getfloat(&array[n]))!=EOF;n++);

  for (i = 0; i < n; i++) {
    printf("%f\n", array[i]);
  }

  return 0;
}

// ���͂��玟�̐��������o����*pn�ɓ����
int getfloat(float *pn){
  int c, sign;
  float f = 0, p = 0.1;

  // �󔒂��΂�
  while(isspace(c = getch()));

  // �����ł͂Ȃ�
  if(!(isdigit(c) || c==EOF || c=='+' || c=='-' || c=='.')){
    ungetch(c);
    return 0;
  }

  // �����`�F�b�N
  sign = (c == '-') ? -1 : 1;
  if(c=='+' || c=='-' || c=='.'){
    c = getch();
    if(!isdigit(c)){
      while(isspace(c = getch()));
    }
  }

  // �����������E��
  for(*pn = 0; isdigit(c); c = getch()){
    *pn = 10 * *pn + (c - '0');
  }
  if(c=='.'){
    printf("!\n");
    while(isdigit(c = getch())){
      f = f + (c - '0') * p;
      p *= 0.1;
    }
    printf("f = %f\n", *pn);
    *pn += f;
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
