#include <stdio.h>

int strend(char *, char *);

int main(void)
{
  char s[] = "germanium onsen";
  char t[] = "sen";
  int flag;

  printf("s = %s\n", s);
  printf("t = %s\n", t);

  flag = strend(s, t);

  printf("flag = %d", flag);

  return 0;
}

// �����񂓂̏I���ɂ�������΂P��Ԃ��A�Ȃ���΂O��Ԃ�
int strend(char *s, char *t){
  int flag = 1;
  int i=0;
  // s, t�̃A�h���X�𕶎��񖖔��܂ő���
  // ������i�����߂Ă���
  while(*s){
    s++;
  }
  s--;
  while(*t){
    i++;
    t++;
  }
  t--;

  // �����񖖔�����t�ɒH���āA*t�̐擪�܂ň�v���邩�ۂ����ׂ�
  // i�͕�����
  for(; i>0; i--){
    printf("*t = %c", *t);
    printf("\t*s = %c\n", *s);

    // ��v���Ă�����flag��1��������
    if(*t==*s){
      flag *= 1;
    }
    // ��v���Ȃ�������flag��0��������
    // �ꕶ���ł���v���Ȃ�������flag��0�ƂȂ�
    else{
      flag *= 0;
    }
    // ���̕�����
    t--;
    s--;
  }

  // �S�Ĉ�v�����1���A���Ȃ����0��Ԃ�
  if(flag==1){
    return 1;
  }
  else if(flag==0){
    return 0;
  }
  else{
    return -1;
  }
}
