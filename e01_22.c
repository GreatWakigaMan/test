//n�����܂łɂ���Ō�̔�u�����N�����̌�Ő܂�Ԃ�
#include <stdio.h>
#include <stdlib.h>
#define N   20

void del_digit(char [], int);

int main(){
  FILE *fp1, *fp2;
  char *fname1 = "./input.txt";
  char *fname2 = "./output.txt";
  int c;
  int i=0;
  // char t[N];

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

  // ���s�����E���ꂾ�Ɣ�u�����N�ɑΉ��ł��Ȃ�
  while((c=fgetc(fp1)) != EOF){
    if(!(i==0) && i%N==0){
      fprintf(fp2, "\n");
    }
    i++;
    fprintf(fp2, "%c", c);
  }

  // �t�@�C���N���[�Y
  fclose(fp1);
  fclose(fp2);

  return 0;
}

//�z��t��j�Ԗڂ̗v�f���폜
void del_digit(char t[], int j){
  while(t[j]!=EOF){
    t[j] = t[j+1];
    j++;
  }
  t[j] = EOF;
}
