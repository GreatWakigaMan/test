#include <stdio.h>
#define swap(t,x,y) t a; t b; a=x; b=y; x=b; y=a;

int main(void){
  double x = 8.9;
  double y = 10.7;

  swap(int, x, y);

  printf("x = %f\n", x);
  printf("y = %f\n", y);

  return 0;
}
