#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef unsigned long long u64;
const int maxn = 100010;
char a[maxn], b[maxn];

typedef unsigned long long u64;
const u64 Base = 31;

u64 h[maxn], h1[maxn];
u64 Pow[maxn];
const int mod = 1e9 + 7;

void Init() {
    Pow[0] = 1;
    for(int i = 1; i < maxn; i++) Pow[i] = Pow[i - 1] * Base;
}

void Init(u64* Hash, char *s, int len) {
    Hash[len] = 0;
    for(int i = len - 1; i >= 0; i--) Hash[i] = (u64)Hash[i + 1] * Base + (s[i] - 'a' + 1);
}

u64 Get(u64* Hash, int p, int L) {
    return Hash[p] - Hash[p + L] * Pow[L];
}

int main() {
    Init();
    int _T;
    scanf("%d", &_T);
    int cas = 1;
    while(_T--) {
        scanf("%s%s", a, b);
        int n = strlen(a);
        int m = strlen(b);
        Init(h, a, n);
        Init(h1, b, m);
        u64 q = Get(h1, 0, m);
        vector<int>dp(n, 0);
        dp[0] = 1;
        for(int i = 0; i < m; i++) dp[i] = 1;
        for(int i = m - 1; i < n; i++) {
            if(q == Get(h, i - m + 1, m)) {
                if(i != m - 1) dp[i] = (1ll * dp[i - m] + dp[i - 1]) % mod;
                else dp[i] = 2;
            }
            else if(i != 0) dp[i] = dp[i - 1];
            else dp[i] = 1;
        }
        printf("Case #%d: %d\n", cas++, dp[n - 1]);
    }
    return 0;
}

