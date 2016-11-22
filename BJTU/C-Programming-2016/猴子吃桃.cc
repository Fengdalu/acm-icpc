#include <stdio.h>

int main() {
  typedef unsigned long long ll;
  ll a[2][2], b[2][2];
  a[0][0] = 2;
  a[0][1] = 2;
  a[1][0] = 0;
  a[1][1] = 1;

  ll g[2] = {1, 1};
  ll t[2];

  int n; scanf("%d", &n);
  n--;
  int i, j, k;
  while(n) {
    if(n & 1) {
      for(i = 0; i < 2; i++) t[i] = 0;
      for(i = 0; i < 2; i++) for(j = 0; j < 2; j++) t[i] += a[i][j] * g[j];
      for(i = 0; i < 2; i++) g[i] = t[i];
    }
    n >>= 1;
    for(i = 0; i < 2; i++) for(j = 0; j < 2; j++) b[i][j] = 0;
    for(i = 0; i < 2; i++) for(j = 0; j < 2; j++) for(k = 0; k < 2; k++)
      b[i][j] += a[i][k] * a[k][j];

    for(i = 0; i < 2; i++) for(j = 0; j < 2; j++) a[i][j] = b[i][j];
  }
  printf("%lld\n", g[0]);
  return 0;
}
