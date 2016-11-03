#include <bits/stdc++.h>

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  std::vector<int> a(n);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);

  int J = 0;
  int ans = 0, L, R;
  int cur = 0;
  int tot = 0;
  for(int i = 0; i < n; i++) {
    while(J < n && cur + (!a[J]) <= k) {
      cur += !a[J];
      tot++;
      J++;
    }
    if(tot > ans) {
      L = i; R = J;
      ans = tot;
    }
    cur -= (!a[i]);
    tot--;
  }
  printf("%d\n", ans);
  for(int i = L; i < R; i++) a[i] = 1;
  for(int i = 0; i < n; i++) printf("%d ", a[i]);
  return 0;
}
