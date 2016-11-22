#include <stdio.h>
#include <string.h>

#define N 1000000

int main() {
  double x;
  scanf("%lf", &x);
  if(x == 0) {puts("0.000"); return 0;}
  double a = x;
  int i;
  for(i = 0; i <= 1000; i++) {
    x = 0.5 * (x + a / x);
  }
  printf("%.3f\n", x);
  return 0;
}
