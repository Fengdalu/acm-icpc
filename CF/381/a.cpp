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

int main() {
  LL n, a, b, c;
  cin >> n >> a >> b >> c;
  n = 4 - n % 4;
  if(n == 4) n = 0;
  LL ans;
  if(n == 3) {
    ans = c;
    cmin(ans, 3 * a);
    cmin(ans, b + a);
  }
  else if(n == 2) {
    ans = b;
    cmin(ans, c * 2LL);
    cmin(ans, 2 * a);
  }
  else if(n == 1) {
    ans = a;
    cmin(ans, b + c);
    cmin(ans, 3 * c);
  }
  else if(n == 0) ans = 0;
  printf("%I64d\n", ans);
  return 0;
}
