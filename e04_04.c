//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);
double cpy(void);
int getop(char []);
int getch(void);
void ungetch(int);

int main() {
  int type;
  double op1, op2;
  char s[MAXOP] = {};
  double val[26] = {};

  while((type=getop(s))!=EOF){
    switch(type){
      case NUMBER:{
        push(atof(s));
        break;
      }
      case '+':{
        push(pop() + pop());
        break;
      }
      case '*':{
        push(pop() * pop());
        break;
      }
      case '-':{
        op2 = pop();
        push(pop() - op2);
        break;
      }
      case '/':{
        op2 = pop();
        if(op2 != 0.0){
          push(pop() / op2);
        }
        else{
          printf("error: zero divisor\n");
        }
        break;
      }
      case '%':{
        op2 = pop();
        push(fmod(pop(), op2));
        break;
      }
      case '\n':{
        printf("\t%.8g\n", pop());
        break;
      }
      case '#':{ // 複製
        push(cpy());
        break;
      }
      case '@':{ // 交換
        op1 = pop();
        op2 = pop();
        push(op1);
        push(op2);
        break;
      }
      default:{
        printf("error: unknown command %s\n", s);
        break;
      }
    }
  }
  return 0;
}



//本来ここ以降はソースを分けるべき

#define MAXVAL 100

int sp = 0;
double val[MAXVAL] = {};

//push: fを値スタックにプッシュ
void push(double f){
  if(sp<MAXVAL){
    val[sp++] = f;
  }
  else{
    printf("error: stack full, can't push %g\n", f);
  }
}

//pop: スタックから一番上の値をポップ
double pop(void){
  if (sp>0){
    return val[--sp];
  }
  else{
    printf("error: stack empty\n");
    return 0.0;
  }
}

//cpy: スタックから一番上の値を複製
double cpy(void){
  if (sp>0){
    return val[sp-1];
  }
  else{
    printf("error: stack empty\n");
    return 0.0;
  }
}

// getop
int getop(char s[]){
  int i, c;
  while((s[0] = c = getch()) == ' ' || c == '\t'); //空白を飛ばす
  s[1] = '\0';
  i = 0;
  if(c == '-'){
    if(isdigit(c = getch())){
      s[i] = '-';
    }
    ungetch(c);
  }
  if(!isdigit(c) && c!='.'){
    return c;
  }
  if(isdigit(c)){
    while(isdigit(s[++i] = c = getch()));
  }
  if(c=='.'){
    while(isdigit(s[++i] = c = getch()));
  }
  s[i] = '\0';
  if(c != EOF){
    ungetch(c);
  }
  return NUMBER;
}



//本来ここ以降はソースを分けるべき

#define BUFSIZE 100

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
