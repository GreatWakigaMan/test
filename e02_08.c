// x��n�r�b�g���[�e�[�V����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned getbits(unsigned, int, int);
unsigned setbits(unsigned, int, int, unsigned);
int bitslen(unsigned);
unsigned rightrot(unsigned, int);

int main(){
  unsigned x = 175;
  unsigned rot;
  int n = 4;

  rot = rightrot(x, n);
  printf("x = %d\ny = %d\n", x, rot);

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

// x��n�r�b�g���[�e�[�V����
unsigned rightrot(unsigned x, int n){
  unsigned rot=0;
  unsigned xpn;
  int len;
  len = bitslen(x);
  // ����n�r�b�g���擾
  xpn = getbits(x, 1, n);
  // ��ʂ�get���Ă��Ȃ��r�b�g��getbits�ɓ˂�����
  rot = setbits(x, n+1, len-n, xpn);
  return rot;
}
