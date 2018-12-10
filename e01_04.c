#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tgmath.h>
#include <time.h>

int main() {
  double cel;
  printf("input celsius temp: ");
  scanf("%lf", &cel);

  double far = 1.8 * cel + 32;
  printf("fahrenheit temp is %.2f.\n", far);
  // printf("input number is %d.", n);

  return 0;
}
