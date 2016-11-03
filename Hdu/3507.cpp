#include <bits/stdc++.h>

const int N = 5e5+100;
typedef long long ll;

struct node { ll x, y, id; };
ll sqr(ll x) { return x * x; }
int main() {
  std::vector<ll> sum(N, 0);
  std::vector<ll> dp(N, 0);
  std::vector<node> q(N);
  int n, m; 
  while(~scanf("%d%d", &n, &m)) {
    for(int i = 0; i < n; i++)  scanf("%d", &sum[i + 1]);
    for(int i = 1; i <= n; i++) sum[i] += sum[i - 1];
    int l = 0, r = 0;
    q[l] = node{0, 0, 0};
    for(int i = 1; i <= n; i++) {
      while(l + 1 <= r && (q[l + 1].y - q[l].y) <= (q[l + 1].x - q[l].x) * 2ll * sum[i]) l++; 
      int id = q[l].id;
      dp[i] = dp[id] + sqr(sum[i] - sum[id]) + m;
      node now{sum[i], dp[i] + sqr(sum[i]), i};
      q[++r] = now;
      while(r - l > 1 && (q[r].y - q[r - 1].y) * (q[r - 1].x - q[r - 2].x) <= (q[r].x - q[r - 1].x) * (q[r - 1].y - q[r - 2].y))  {
        std::swap(q[r], q[r - 1]); r--; }
    }
    printf("%lld\n", dp[n]);
  }
  return 0;
}

