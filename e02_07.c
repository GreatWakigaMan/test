// x��p�Ԗڂ���n�r�b�g��y�̉E�[�ɃZ�b�g���ďo��
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned getbits(unsigned, int, int);
unsigned setbits(unsigned, int, int, unsigned);
int bitslen(unsigned);
unsigned invert(unsigned, int, int);

int main(){
  unsigned x = 145;
  unsigned inv;
  int p = 3;
  int n = 4;

  inv = invert(x, p, n);
  printf("x = %d\ny = %d\n", x, inv);

  return 0;
}

// 2�r�b�g�����`�F�b�N
int bitslen(unsigned x){
  int count, d = 1;
  for(count=1; ; count++){
    d *= 2;
    if(x<d){
      break;
    }
  }
  // printf("i = %d\n", count);
  return count;
}

// x��p�Ԗڂ���n�r�b�g���擾
unsigned getbits(unsigned x, int p, int n){
  unsigned xpn;
  xpn = (x >> (p-1)) & ~(~0 << n);
  // printf("g = %d\n", xpn);
  return xpn;
}

// x��p�Ԗڂ���n�r�b�g��y�̉E�[�ɃZ�b�g
unsigned setbits(unsigned x, int p, int n, unsigned y){
  unsigned xpn;
  int len;
  // x��p�Ԗڂ���n�r�b�g
  xpn = getbits(x, p, n);
  // xpn���������邩�`�F�b�N
  len = bitslen(xpn);
  // printf("k = %d\n", (y << len));
  // y�����グ����xps���Z�b�g
  return xpn | (y << len);
}

// x��p�Ԗڂ���n�r�b�g�𔽓]
unsigned invert(unsigned x, int p, int n){
  unsigned inv=0;
  int i;
  // x��p�Ԗڂ���n�r�b�g��ׂ�
  inv = x >> (p+n-1);
  // printf("inv = %d\n\n", inv);
  // inv�ɔ��]�r�b�g��������
  for(i=p+n-1; i>=p; i--){
    inv = setbits(~x, i, 1, inv);
    // printf("inv = %d\n", inv);
  }
  // inv��x�̐擪�r�b�g��������
  for(i=p-1; i>=1; i--){
    inv = setbits(x, i, 1, inv);
    // printf("inv = %d\n", inv);
  }
  return inv;
}
