#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int c, d;
  int sum = 0;

  while((c=getchar())!='\n'){
    sum = sum * 16; // 16倍して桁上げ
    // 0x or 0Xの例外処理
    if(c=='0'){
      d = getchar();
      if(d=='x' || d=='X');
      else{
        c = d;
      }
    }
    // atoi
    if(c>='0' && c<='9'){
      d = c - '0';
    }
    else if(c>='a' && c<='f'){
      d = c - 'a' + 10;
    }
    else if(c>='A' && c<='F'){
      d = c - 'A' + 10;
    }
    else{
      printf("input error.");
      return -1;
    }
    sum += d;
  }
  printf("%d", sum);

  return 0;
}
