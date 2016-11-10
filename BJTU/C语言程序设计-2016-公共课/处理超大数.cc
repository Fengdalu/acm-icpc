#include <stdio.h>

int main() {
  int a, b; scanf("%d%d", &a, &b);

  a %= 1000;
  int ans = 1;
  while(b) {
    if(b & 1) ans = (ans * a) % 1000;
    b >>= 1;
    a = (a * a) % 1000;
  }
  printf("%d\n", ans);
  return 0;
}
