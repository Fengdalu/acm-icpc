#include <bits/stdc++.h>


using namespace std;
typedef long long LL;
#define cmin(x, y) x = min(x, y)
#define AA first
#define BB second
#define MP make_pair
#define SZ size
#define PB push_back
#define PII pair<int, int>

const int N = 2e5+10;
vector<PII> g[N];
int a[N], add[N];
int ans[N];


int dfs(int u, set< pair<LL, int> > &s, LL pre, int fa) {
  s.insert(MP(pre, u));
  auto p = s.lower_bound(MP(pre - a[u], -1));
  if(p != s.end()) add[p->second]--;

  int tot = 0, sub = 0;
  for(auto &t : g[u]) {
    tot += dfs(t.AA, s, pre + t.BB, u);
    sub += add[t.AA];
    add[u] += add[t.AA];
  }
  ans[u] = tot + sub;
  s.erase(MP(pre, u));
  return tot + 1;
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
  for(int i = 1; i < n; i++) {
    int p, v; scanf("%d%d", &p, &v);
    g[p - 1].PB(MP(i, v));
  }
  set<pair<LL, int> >s;
  dfs(0, s, 0, -1);
  for(int i = 0; i < n; i++) printf("%d ", ans[i]);
  return 0;
}
