#include <bits/stdc++.h>


typedef long long ll;
ll depth(ll x) {
  ll result = 0;
  while(x) {
    result++; 
    x >>= 1;
  }
  return result;
}
ll lca(ll x, ll y) {
  if(depth(x) < depth(y)) std::swap(x, y);
  int dt = depth(x) - depth(y);
  while(dt--) x = x >> 1;
  while(x != y) {
    x >>= 1; 
    y >>= 1;
  }
  return x;
}

int main() {
  int q; 
  scanf("%d", &q);
  std::map<ll, ll> f;
  while(q--) {
    int op;
    scanf("%d", &op);
    if(op == 1) {
      ll u, v, fa, w;
      scanf("%I64d%I64d%I64d", &u, &v, &w);
      fa = lca(u, v);
      while(u) { f[u] += w; u >>= 1; }
      while(v) { f[v] += w; v >>= 1; }
      while(fa) { f[fa] -= 2 * w; fa >>= 1; }
    }
    else {
      ll u, v, fa;
      scanf("%I64d%I64d", &u, &v);
      fa = lca(u, v);
      ll ans = 0;
      while(u) { ans += f[u]; u >>= 1; }
      while(v) { ans += f[v]; v >>= 1; }
      while(fa){ ans -= 2ll * f[fa]; fa >>= 1; }
      printf("%I64d\n", ans);
    }
  }
  return 0;
}
