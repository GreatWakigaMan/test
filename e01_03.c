#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tgmath.h>
#include <time.h>

int main() {
  double fahr, cel;
  int min, max, step;

  min = 0;
  max = 150;
  step = 10;

  printf("  fahr    cel\n");
  for(fahr=min; fahr<=max; fahr+=step){
    cel = (5.0 / 9.0) * (fahr - 32.0);
    printf("%6.1f %6.1f\n", fahr, cel);
  }

  return 0;
}
