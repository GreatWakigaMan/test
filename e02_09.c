// x=x&(x-1)���g����bitcount�̍�����(�����Ȃ�Ȃ�)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define LOOP 10000000
#define FLAG 1 // 1:������
               // 2:�I���W�i��

int bitcount(unsigned);

int main(){
  unsigned x = 15;
  int n;
  int i;

  clock_t start,end;
  start = clock();

  for(i=1; i<=LOOP; i++){
    n = bitcount(x);
  }
  printf("x = %d\n", x);
  printf("number of the \'1\' is %d\n", n);

  end = clock();
  printf("%.3f�b������܂���\n",(double)(end-start)/CLOCKS_PER_SEC);

  return 0;
}

// 1�̐��𐔂���
int bitcount(unsigned x){
  int n;
  switch (FLAG) {
    case 1: // 1:������
    while(x != 0){
      x &= (x - 1);
      n++;
    }
    case 2: // 2:�ᑬ��
    for(n=0; x!=0; x>>=1){
      if(x&01){
        n++;
      }
    }
  }
  return n;
}
