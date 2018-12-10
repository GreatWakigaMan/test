// xのnビットローテーション
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

// xのnビットローテーション
unsigned rightrot(unsigned x, int n){
  unsigned rot=0;
  unsigned xpn;
  int len;
  len = bitslen(x);
  // 下位nビットを取得
  xpn = getbits(x, 1, n);
  // 上位のgetしていないビットをgetbitsに突っ込む
  rot = setbits(x, n+1, len-n, xpn);
  return rot;
}
