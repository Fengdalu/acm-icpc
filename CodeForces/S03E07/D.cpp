#include <bits/stdc++.h>

const int N = 5e5+100;
int a[N];
int ind[N];
int vis[N];
std::vector<int> f[N];
int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) scanf("%d", a + i);
  std::fill(vis, vis + N, -1);
  int cnt = 0;
  for(int i = 1; i <= n; i++) if(vis[a[i]] == -1) {
    vis[a[i]] = cnt;
    ind[cnt] = i;
    cnt++;
  }
  for(int i = 1; i <= n; i++) f[vis[a[i]]].push_back(i);
  int q; scanf("%d", &q);
  while(q--) {
    int l1, r1, l2, r2;
    scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
    long long ans = 0;
    for(int i = 0; i < cnt; i++) {
      if(ind[i] > r1 || ind[i] > r2) break;
      int t1 = std::upper_bound(f[i].begin(), f[i].end(), r1)  - std::lower_bound(f[i].begin(), f[i].end(), l1);
      int t2 = std::upper_bound(f[i].begin(), f[i].end(), r2)  - std::lower_bound(f[i].begin(), f[i].end(), l2);
      ans += t1 * t2;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
