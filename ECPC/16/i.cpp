#include <bits/stdc++.h>

const int N = 2e5+100;
typedef long long ll;
struct node {double x, c;};
double sqr(double x) { return x * x; }
node a[N];

int operator < (const node &a, const node &b) {
  if(a.x == b.x) return a.c > b.c;
  return a.x < b.x;
}

int main() {
  freopen("walk.in", "r", stdin);
  int T;
  scanf("%d", &T);
  while(T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    int cnt = 0;

    for(int i = 0; i < n; i++) {
      double x, y, r;
      scanf("%lf%lf%lf", &x, &y, &r);
      if(m < r) continue;
      double L = m - r;

      if(L < abs(y)) continue;
      double ll = x - sqrt(sqr(L) - sqr(y));
      double rr = x + sqrt(sqr(L) - sqr(y));
      a[cnt++] = node{ll, int(r)};
      a[cnt++] = node{rr, int(-r)};
    }
    std::sort(a, a + cnt);
    ll cur = 0;
    ll mx = 0;
    for(int i = 0; i < cnt; i++) {
      if(a[i].c > 0) cur += a[i].c;
      mx = std::max(mx, cur);
      if(a[i].c < 0) cur += a[i].c;
    }
    printf("%I64d\n", mx);
  }
  return 0;
}
close
