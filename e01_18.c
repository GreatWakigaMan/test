//�u�����N�E�^�u�E�󔒍s���폜
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX   256

//�z�񏉊���
void arrinit(char []);

int main(){
  FILE *fp1, *fp2;
  char *fname1 = "./input.txt";
  char *fname2 = "./output.txt";
  int c;
  int i=0, j=0, flag=0; //�󔒍s�Ǘ��p
  char t[MAX];
  arrinit(t);

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

  // �����̋󔒂���ы󔒍s�폜
  while((c=fgetc(fp1)) != EOF){
    if(c=='\n'){
      // �󔒍s�łȂ��Ȃ�o��
      if(flag==1){
        fprintf(fp2, "%s\n", t);
      }
      // �����̋󔒍폜
      else{
        // ������̌�납��󔒁E�u�����N���폜
        for(j=i; j>=0; j++){
          if(t[j]==' ' || t[j]=='\t'){
            t[j] = '\0';
          }
          else{
            break;
          }
        }
        fprintf(fp2, "%s\n", t);
      }
      // ������
      flag = 0;
      i = 0;
      arrinit(t);
    }
    else if(c==' ' || c=='\t'){
      // �󔒂Ȃ�flag�𓮂����Ȃ�
      t[i] = c;
      i++;
    }
    else{
      // ���̑��̍s
      flag = 1;
      t[i] = c;
      i++;
    }
  }
  fprintf(fp2, "%s", t);

  // �t�@�C���N���[�Y
  fclose(fp1);
  fclose(fp2);

  return 0;
}

void arrinit(char t[]){
  int i;
  for(i=0; i<MAX; i++){
    t[i] = '\0';
  }
}
