//�R�����g�E���p�����Ή�
#include <stdio.h>
#include <stdlib.h>
#define MAX 1024

void del_digit(char [], int);

int main(){
  FILE *fp;
  char *fname = "./input.txt";
  int c;
  char t[MAX];
  char tmp=0;
  int i=0, j=0;

  // �t�@�C���I�[�v���E�ǂݍ���
  fp = fopen(fname, "r");
  if(fp == NULL) {
    printf("%s file not open!\n", fname);
    return -1;
  }

  // �J�b�R�������o
  while((c=fgetc(fp)) != EOF){
    putchar(c);
    if(c=='{' || c=='[' || c=='(' || c=='}' || c==']' || c==')'){
      t[i] = c;
      ++i;
    }
    else if(c==' '){
      t[i] = EOF;
    }
  }
  printf("\n%s\n", t);

  for(j=0; t[j]!=0; j++){
    printf("j=%d\n", j);
    //�ŏ��ɏo�Ă���J�b�R�����T��
    if(t[j]==')' || t[j]=='}' || t[j]==']'){
      switch(t[j]){
        case ')' : tmp = '('; break;
        case '}' : tmp = '{'; break;
        case ']' : tmp = '['; break;
      }
      //�J�b�R����Ƃ��̑O�̎����폜
      del_digit(t, j);
      if(t[j-1]==tmp){
        del_digit(t, j-1);
        j = j-2;
      }
      else{
        printf("syntax error.1\n");
        return 0;
      }
    }
    printf("%s\n", t);
  }

  //�`�F�b�N
  if(t[0]==0){
    printf("�����Ă�\n");
  }
  else{
    printf("rem = %s\n", t);
    printf("syntax error.2");
    return 0;
  }

  // �t�@�C���N���[�Y
  fclose(fp);

  return 0;
}

//�z��t��j�Ԗڂ̗v�f���폜
void del_digit(char t[], int j){
  int k;
  k = j;
  while(t[k]!=EOF){
    t[k] = t[k+1];
    k++;
  }
  t[k] = EOF;
}
