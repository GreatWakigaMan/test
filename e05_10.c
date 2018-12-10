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

//push: ����l�X�^�b�N�Ƀv�b�V��
void push(int n){
  if(sp<MAXVAL){
    val[sp++] = n;
  }
  else{
    printf("error: stack full, can't push %d\n", n);
  }
}

//pop: �X�^�b�N�����ԏ�̒l���|�b�v
int pop(void){
  if (sp>0){
    return val[--sp];
  }
  else{
    printf("error: stack empty\n");
    return 0;
  }
}

// getop: �l�̎擾
int getop(char *s){
	// �����������Ă��邩�ۂ�����������Ηǂ�
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
