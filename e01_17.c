//80���ȏ�̍s����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX   256
#define PSIZE 80

//�z�񏉊���
void arrinit(char []);

int main(){
  FILE *fp1;
  char *fname1 = "./input.txt";
  int c;
  int i=0;
  char t[MAX];
  arrinit(t);

  // �t�@�C���I�[�v���E�ǂݍ��ݗp
  fp1 = fopen(fname1, "r");
  if(fp1 == NULL) {
    printf("%s file not open!\n", fname1);
    return -1;
  }

  // 80���ȏ�̍s��T��
  while((c=fgetc(fp1)) != EOF){
    //���s��������
    if(c=='\n'){
      if(i>=PSIZE){
        printf("i=%d, %s\n", i, t);
      }
      i = 0;
      arrinit(t);
    }
    // ���s�ȊO���J�E���g
    else{
      t[i] = c;
      i++;
    }
  }

  // �t�@�C���N���[�Y
  fclose(fp1);

  return 0;
}

void arrinit(char t[]){
  int i;
  for(i=0; i<MAX; i++){
    t[i] = '\0';
  }
}
