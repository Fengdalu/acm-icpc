#include <bits/stdc++.h>

using namespace std;
#define AA first
#define BB second
#define MP make_pair
#define SZ size()
#define PII pair<int, int>
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
typedef long long LL;

const int N = 1e6;
LL dp[N];
PII a[N];

int cmp(PII a, PII b) {
  return 1LL * a.BB * b.AA > 1LL * b.BB * a.AA;
}

int main() {
  int n, s; scanf("%d%d", &n, &s);
  for(int i = 0; i < n; i++) {
    scanf("%d%d", &a[i].AA, &a[i].BB);
  }
  sort(a, a + n, cmp);
  int mx = a[0].AA;
  for(int i = 0; i < n; i++) cmax(mx, a[i].AA);
  mx *= a[0].AA;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j + a[i].AA <= mx; j++) cmax(dp[j + a[i].AA], dp[j] + a[i].BB);
  }
  LL ans = dp[min(s, mx)];
  for(int i = 0; i <= min(mx, s); i++) {
    LL left = s - i;
    cmax(ans, (1LL * left / a[0].AA) * a[0].BB + dp[i]);
  }
  printf("%I64d\n", ans);
  return 0;
}
