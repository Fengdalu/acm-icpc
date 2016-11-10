#include <bits/stdc++.h>

int main() {
  typedef long long ll;
  int n;
  while(~scanf("%d", &n)) {
    int ans = 0;
    for(int i = 0; i < n; i++) {
      ll x; scanf("%lld", &x);
      for(int j = 0; j < 32; j += 8) {
        if((x >> j & 255) == 97) ans++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
