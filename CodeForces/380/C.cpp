#include <bits/stdc++.h>

#define PII std::pair<int, int>
typedef long long LL;
const int N = 2e5+1000;
PII c0[N], c[N];
int g[N];
int n, k, s, t;

LL check(int w) {
  LL tot = 0;
  for(int i = 0; i <= k; i++) {
    LL dis = g[i + 1] - g[i];
    if(dis * 2LL <= w) { tot += 1LL * dis; }
    else if(w < dis) return 3e9;
    else {
      LL p = w - dis;
      tot += 1LL * p + 2LL * (dis - p);
    }
  }
  return tot;
}

int main() {
  scanf("%d%d%d%d", &n, &k, &s, &t);
  for(int i = 0; i < n; i++) scanf("%d%d", &c0[i].first, &c0[i].second);
  for(int i = 0; i < k; i++) scanf("%d", &g[i + 1]);
  g[k + 1] = s;
  std::sort(g, g + k + 2);
  std::sort(c0, c0 + n);
  int cnt = 1;
  c[0] = c0[0];
  for(int i = 1; i < n; i++) {
    if(c0[i].second > c[cnt - 1].second) c[cnt++] = c0[i];
  }

  n = cnt;
  int l = 0, r = cnt - 1;
  while(l < r) {
    int mid = (l + r) >> 1;
    if(check(c[mid].second) <= t) r = mid;
    else l = mid + 1;
  }
  if(check(c[l].second) <= t) printf("%d\n", c[l].first);
  else printf("-1");
  return 0;
}
