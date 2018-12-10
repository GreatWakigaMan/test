// xのp番目からnビットをyの右端にセットして出力
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned getbits(unsigned, int, int);
unsigned setbits(unsigned, int, int, unsigned);
int bitslen(unsigned);

int main(){
  unsigned x = 1023;
  unsigned y = 1023;
  unsigned n;
  n = setbits(x, 2, 6, y);

  printf("n = %d\n", n);

  return 0;
}

// 2ビット桁数チェック
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

// xのp番目からnビットを取得
unsigned getbits(unsigned x, int p, int n){
  unsigned xpn;
  xpn = (x >> (p-1)) & ~(~0 << n);
  // printf("g = %d\n", xpn);
  return xpn;
}

// xのp番目からnビットをyの右端にセット
unsigned setbits(unsigned x, int p, int n, unsigned y){
  unsigned xpn;
  int len;
  // xのp番目からnビット
  xpn = getbits(x, p, n);
  // xpnが何桁あるかチェック
  len = bitslen(xpn);
  // printf("k = %d\n", (y << len));
  // yを桁上げしてxpsをセット
  return xpn | (y << len);
}
