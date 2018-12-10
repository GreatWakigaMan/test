//�^�u���^�u�X�g�b�v�܂ł̋󔒂ɒu��������
#include <stdio.h>
#include <stdlib.h>
#define MAX 256
#define TS  5   //�^�u�X�g�b�v�̕�����

// void del_digit(char [], int);
// void ins_digit(char [], int, char);

int main(){
  FILE *fp1, *fp2;
  char *fname1 = "./input.txt";
  char *fname2 = "./output.txt";
  int c;
  int spcount;
  int i, j;
  i = j = 0;

  // �t�@�C���I�[�v���E�ǂݍ��ݗp
  fp1 = fopen(fname1, "r");
  if(fp1 == NULL) {
    printf("%s file not open!\n", fname1);
    return -1;
  }

  // �t�@�C���I�[�v���E�������ݗp
  fp2 = fopen(fname2, "w");
  if(fp2 == NULL) {
    printf("%s file not open!\n", fname2);
    return -1;
  }

  // while((c=fgetc(fp1))!=EOF)
  // printf("%d ", c);

  // ���o
  while((c=fgetc(fp1)) != EOF){
    i++;
    if(c==9){
      spcount = TS - i % TS;
      i = i + spcount;
      for(j=0; j<spcount; j++){
        fprintf(fp2, "%c", ' ');
      }
    }
    else if(c=='\n'){
      i = 0;
      fprintf(fp2, "%c", c);
    }
    else{
      fprintf(fp2, "%c", c);
    }
  }

  // �t�@�C���N���[�Y
  fclose(fp1);
  fclose(fp2);

  return 0;
}

// //�z��t��j�Ԗڂ̗v�f���폜
// void del_digit(char t[], int j){
//   while(t[j]!=EOF){
//     t[j] = t[j+1];
//     j++;
//   }
//   t[j] = EOF;
// }
//
// //�z��t��j�Ԗڂɕ���c��}��
// void ins_digit(char t[], int j, char c){
//   int k;
//   for(k=MAX-1; k>j; k--){
//     t[k] = t[k-1];
//   }
//   t[k] = c;
// }
