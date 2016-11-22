#include <bits/stdc++.h>

int main() {
  typedef std::pair<int, int> pii;
  std::map< std::pair<pii, pii>, int> f;
  int n;
  scanf("%d", &n);
  std::vector<int> x(n), y(n);
  for(int i = 0; i < n; i++) scanf("%d%d", &x[i], &y[i]);

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      if((x[j] > x[i]) || (x[j] == x[i] && y[j] > y[i])) {
        int a = x[j] - x[i], b = y[j] - y[i];
        int l = a, r = b;
        int q = std::__gcd(a, b);
        if(q) {a /= q; b /= q;}
        f[std::make_pair(std::make_pair(a, b), std::make_pair(l, r))]++;
      }
    }
  typedef long long ll;
  ll ans = 0;
  for(auto &cp : f) ans += 1ll * cp.second * (cp.second - 1) / 2;
  std::cout << ans / 2 << std::endl;
  return 0;
}
