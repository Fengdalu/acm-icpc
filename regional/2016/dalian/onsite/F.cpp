#include <bits/stdc++.h>

const int mod = 1e9 + 7;
typedef long long ll;
const int N = 1e6;
std::vector<ll> pre(N);

ll cal(ll x) {
  return (x) * (2ll + 2ll + x - 1) / 2ll;
}

ll qpow(ll x, ll p) {
  ll ans = 1;
  while(p) {
    if(p & 1) ans = (ans * x) % mod;
    p >>= 1;
    x = (x * x) % mod;
  }
  return ans;
}

ll sub(int l, int r) {
  return pre[r] * qpow(pre[l - 1], mod - 2) % mod;
}

int main() {
  pre[0] = 1;
  for(int i = 1; i < N; i++)
    pre[i] = (1ll * pre[i - 1] * (i)) % mod;

  int T; scanf("%d", &T);
  while(T--) {
    ll tot; scanf("%lld", &tot);
    if(tot == 1) {puts("1"); continue;}
    ll l = 1, r = tot;
    while(l < r) {
      ll mid = (l + r + 1) >> 1;
      if(cal(mid) <= tot) l = mid;
      else r = mid - 1;
    }
    int op = 2, ed = 2 + l - 1; 
    ll p = tot - cal(l);
    op += p / l;
    ed += p / l;
    if(p % l) {
      int mid = ed - p % l;
      int mid1 = ed - p % l + 1;
      mid1 ++;
      ed ++;
      printf("%lld\n", sub(op, mid) * sub(mid1, ed) % mod);
    }
    else printf("%lld\n", sub(op, ed));
  }
  return 0;
}
