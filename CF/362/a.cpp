#include <bits/stdc++.h>

int main() {
  int s, t, x;
  scanf("%d%d%d", &t, &s, &x);
  if((x == t) || (x >= t + s && (x - t) % s == 0) || (x >= t + s + 1 && (x - t - 1) % s == 0)) puts("YES");
  else puts("NO");
  return 0;
}
