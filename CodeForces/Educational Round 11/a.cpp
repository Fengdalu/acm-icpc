#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int>a(n);
  std::vector<int> ans;
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
  for(int i = 0; i < n - 1; i++) {
    ans.push_back(a[i]);
    if(std::__gcd(a[i], a[i + 1]) != 1) ans.push_back(1);
  }
  ans.push_back(a[n - 1]);
  printf("%d\n", ans.size() - a.size());
  for(int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
  return 0;
}
