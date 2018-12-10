#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define NUMBER '0'

void push(int);
int pop(void);
int getop(char *);

int main(int argc, char *argv[]){
	int type, arg=1, op;
	if(argc<4){
		printf("Usage: e05_10 num num op");
	}
	else{
		while(--argc){
			type = getop(argv[arg++]);
			switch(type){
			case NUMBER:
				push(atoi(argv[arg-1]));
				break;
			case '+':
				push(pop()+pop());
				break;
			case '-':
				op = pop();
				push(pop() - op);
				break;
			case 'x':
				push(pop()*pop());
				break;
			case '/':
				op = pop();
				if(op!=0){
					push(pop()/op);
				}
				else{
					printf("error: zero divisor.\n");
					return 0;
				}
				break;
			case '%':
				op = pop();
				push(fmod(pop(), op));
				break;
			default:
				printf("error: unknown command.\n");
				return 0;
			}
		}
		printf("%d\n", pop());
	}
}


#define MAXVAL 100

int sp = 0;
double val[MAXVAL] = {};

//push: ｎを値スタックにプッシュ
void push(int n){
  if(sp<MAXVAL){
    val[sp++] = n;
  }
  else{
    printf("error: stack full, can't push %d\n", n);
  }
}

//pop: スタックから一番上の値をポップ
int pop(void){
  if (sp>0){
    return val[--sp];
  }
  else{
    printf("error: stack empty\n");
    return 0;
  }
}

// getop: 値の取得
int getop(char *s){
	// 数字が入っているか否かだけ分かれば良い
	if(isdigit(*s)){
		return NUMBER;
	}
	else if(*s=='-' && isdigit(*(s+1))){
		return NUMBER;
	}
	else{
		return *s;
	}
}
