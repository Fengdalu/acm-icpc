#include <bits/stdc++.h>

using namespace std;
#define AA first
#define BB second
#define MP make_pair
#define SZ size()
#define cmax(x, y) x = max(x, y)
#define OP begin()
#define ED end()
typedef long long LL;

const int N = 3000;
int n, s, t, a[N];
LL f[N];

template<typename T> T gcd(T a, T b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

int main() {
//  freopen("a.in", "r", stdin);
  while(~scanf("%d%d%d", &n, &s, &t)) {
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    for(int i = 0; i < n; i++) a[i] = s - 1 - a[i];
    sort(a, a + n);
    for(int i = 0; i < n; i++) {
      int cur = a[i];
      multiset<int> S;
      for(int i = 0; i < n; i++) S.insert(a[i]);
      LL tot = 0;
      while(S.SZ) {
          auto p = S.upper_bound(cur);
          if(p == S.OP) p = S.ED;
          p--;
          LL ad;
          if(*p > cur) {
            ad = cur + s - *p;
          } else {
            ad = cur - *p;
          }
          ad += t;
          cur = (1LL * cur + s - ad % s) % s;
          tot += ad;
          S.erase(p);
      }
      f[i] = tot;
    }

    LL mx = f[0];
    LL fz = 0, fm = s;
    for(int i = 0; i < n - 1; i++) {
      LL sz = a[i + 1] - a[i];
      fz += 1LL * (f[i] + f[i] + sz - 1) * sz / 2;
      cmax(mx, f[i] + sz - 1);
    }
    LL sz = s - a[n - 1] + a[0];
    fz += 1LL * (f[n - 1] + f[n - 1] + sz - 1) * sz / 2;
    cmax(mx, f[n - 1] + sz - 1);

    LL g = __gcd(fm, fz);
    if(g) fm /= g, fz /= g;
    printf("%lld\n%lld\n%lld/%lld\n", *min_element(f, f + n), mx, fz, fm);
  }
  return 0;
}
