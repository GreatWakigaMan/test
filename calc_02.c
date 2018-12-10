#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

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
