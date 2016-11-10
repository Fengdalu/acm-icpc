#include <bits/stdc++.h>

const double PI = acos(-1.0);
int v[50];
int main() {
  int n, r;
  while(~scanf("%d%d", &n, &r)) {
    for(int i = 0; i < n; i++) scanf("%d", &v[i]);
    double tot = 0;
    for(int i = 0; i < n; i++)
      tot += sin(PI * 1.0 * v[i] / 180.0);
    printf("%.3f\n", r * r * tot / 2.0);
  }
  return 0;
}
