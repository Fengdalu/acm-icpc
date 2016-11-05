#include <bits/stdc++.h>

int main() {
  int T; scanf("%d", &T);
  while(T--) {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) scanf("%d", &b[i]);
    std::sort(b.begin(), b.end(), std::greater<int>());
    int mx = a[0] * b[0];
    bool flag = false;
    std::sort(a.begin() + 1, a.end(), std::greater<int>());
    for(int i = 1; i < n; i++) {
      if(a[i] * b[n - i] >= mx) {
        flag = true;
        break;
      }
    }
    if(!flag) puts("YES");
    else puts("NO");
  }
  return 0;
}
