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

const LL mod = 1e9+7;
LL f[22], fact[22], s;
int n;
LL qpow(LL a, LL b) {
  if(b == 0) return 1;
  if(b & 1) return a * qpow(a, b - 1) % mod;
  return qpow(a * a % mod, b >> 1) % mod;
}
LL C(LL a, LL b) {
  LL s = 1;
  for(LL i = a - b + 1; i <= a; i++) {
    s *= i % mod;
    s %= mod;
  }
  return s * qpow(fact[b], mod - 2) % mod;
}

int main() {
  scanf("%d%I64d", &n, &s);
  fact[0] = 1;
  for(int i = 1; i < 22; i++) fact[i] = 1LL * fact[i - 1] * i % mod;
  for(int i = 0; i < n; i++) scanf("%I64d", &f[i]);
  LL ans = 0;
  for(int mk = 0; mk < (1 << n); mk++) {
    LL sign = 0, sum = s;
    for(int i = 0; i < n; i++) if(mk >> i & 1) {
      sum -= f[i] + 1;
      sign ^= 1;
    }
    if(sum < 0) continue;
    if(sign) ans += mod - C(sum + n - 1, n - 1);
    else ans += C(sum + n - 1, n - 1);
    ans %= mod;
  }
  printf("%I64d\n", ans);
  return 0;
}
