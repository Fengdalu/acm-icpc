#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9+7;
typedef long long LL;
LL mul(LL a, LL b) {
  LL tot = 0;
  while(b) {
      if(b & 1) tot = (tot + a);
      b >>= 1;
      a <<= 1;
      if(tot >= MOD) tot -= MOD;
      if(a >= MOD) a -= MOD;
    }
    return tot;
};

void fib(LL n, LL &x, LL &y) {
  if (n == 1) {
    x = y = 1;
    return;
  } else if (n & 1) {
    fib(n - 1, y, x);
    y += x; y %= MOD;
  } else {
    LL a, b;
    fib(n >> 1, a, b);
    y = (mul(a, a) % MOD + mul(b, b) % MOD) % MOD;
    x = (mul(a, b) % MOD + mul(a, (b + MOD - a)) % MOD) % MOD;
  }
}
