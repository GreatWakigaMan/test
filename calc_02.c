#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

//push: f��l�X�^�b�N�Ƀv�b�V��
void push(double f){
  if(sp<MAXVAL){
    val[sp++] = f;
  }
  else{
    printf("error: stack full, can't push %g\n", f);
  }
}

//pop: �X�^�b�N�����ԏ�̒l���|�b�v
double pop(void){
  if (sp>0){
    return val[--sp];
  }
  else{
    printf("error: stack empty\n");
    return 0.0;
  }
}
