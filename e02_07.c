// xのp番目からnビットをyの右端にセットして出力
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

// xのp番目からnビットを反転
unsigned invert(unsigned x, int p, int n){
  unsigned inv=0;
  int i;
  // xのp番目からnビットを潰す
  inv = x >> (p+n-1);
  // printf("inv = %d\n\n", inv);
  // invに反転ビットを加える
  for(i=p+n-1; i>=p; i--){
    inv = setbits(~x, i, 1, inv);
    // printf("inv = %d\n", inv);
  }
  // invにxの先頭ビットを加える
  for(i=p-1; i>=1; i--){
    inv = setbits(x, i, 1, inv);
    // printf("inv = %d\n", inv);
  }
  return inv;
}
