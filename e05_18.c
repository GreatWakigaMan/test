#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAXTOKEN 100

enum {NAME, PARENS, BRACKETS};

void dcl(void);
void dirdcl(void);
void errproc(void);

int gettoken(void);
int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];
int errchk;

int main(void){
	errchk = 0;
	while(gettoken() != EOF){
		strcpy(datatype, token);
		out[0] = '\0';
		dcl();
		if(tokentype != '\n' && errchk==0){
			printf("syntax error\n");
			errproc();
		}
		if(errchk==0){
			printf("%s: %s %s\n", name, out, datatype);
		}
	}
	return 0;
}

// 宣言子解析
void dcl(void){
	int ns;
	
	// 「*」を数える
	for(ns=0; gettoken()=='*'; ){
		ns++;
	}
	dirdcl();
	while(ns-->0){
		strcat(out, " pointer to");
	}
}

// 直接宣言子解析
void dirdcl(void){
	int type;
	
	if(tokentype == '('){
		dcl();
		if(tokentype != ')'){
			if(errchk==0){
				printf("error: missing )\n");
				errproc();
			
			}
		}
	}
	else if(tokentype == NAME){
		strcpy(name, token);
	}
	else{
		if(errchk==0){
			printf("error: expected name or (dcl)\n");
			errproc();
		}
	}
	while((type=gettoken()) == PARENS || type == BRACKETS){
		if(type == PARENS){
			strcat(out, " function returning");
		}
		else{
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
	}
}

// トークン取得
int gettoken(void){
	int c, getch(void);
	void ungetch(int);
	char *p = token;
	
	// 空白を飛ばす
	while((c = getch()) == ' ' || c == '\t');
	if(c=='('){
		if((c = getch()) == ')'){
			strcpy(token, "()");
			return tokentype = PARENS;
		}
		else{
			ungetch(c);
			return tokentype = '(';
		}
	}
	else if(c=='['){
		for(*p++ = c; (*p++ = getch()) != ']';);
		*p = '\0';
		return tokentype = BRACKETS;
	}
	else if(isalpha(c)){
		for(*p++ = c; isalnum(c = getch());){
			*p++ = c;
		}
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	}
	else{
		return tokentype = c;
	}
}

#define BUFSIZE 1000

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

// エラー処理
void errproc(void){
	int c;
	while(getch()!=EOF);
	tokentype = '\n';
	errchk = 1;
}
