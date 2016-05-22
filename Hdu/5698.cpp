#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const long long mod = 1000000007;
const int maxn = 300010;
long long fact[maxn];
long long inv[maxn];

int main() {
    fact[0] = 1;
    for(int i = 1; i < maxn; i++) fact[i] = (fact[i - 1] * i) % mod;
    inv[1] = 1;
    inv[0] = 1;
    for(int i = 2; i < maxn; i++) inv[i] = ((mod - mod / i) * inv[mod % i]) % mod;
    for(int i = 2; i < maxn; i++) inv[i] = (inv[i] * inv[i - 1]) % mod;
    int n, m;
    while(~scanf("%d%d", &n, &m)) {
        n -= 2;
        m -= 2;
        n = n + m;
        cout << fact[n] * inv[m] % mod * inv[n - m] % mod << endl;
    }
}
