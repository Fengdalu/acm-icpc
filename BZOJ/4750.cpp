#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

const int N = 100010;
const LL MOD = 1000000061;
int a[N], l[N], r[N], s[N];

void run() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);

    l[1] = 1;
    stack<int> stk;
    stk.push(1);
    for(int i = 2; i <= n; i++) {
        int cur = a[i];
        while(stk.size() && a[stk.top()] <= cur) stk.pop();
        if(stk.size() == 0) l[i] = 1; else l[i] = stk.top() + 1;
        stk.push(i);
    }
    r[n] = n;
    while(stk.size()) stk.pop();
    stk.push(n);
    for(int i = n - 1; i >= 1; i--) {
        int cur = a[i];
        while(stk.size() && a[stk.top()] < cur) stk.pop();
        if(stk.size() == 0) r[i] = n; else r[i] = stk.top() - 1;
        stk.push(i);
    }

    LL ans = 0;
    for(int i = 0; i < 32; i++) {
        s[0] = 0;
        for(int j = 1; j <= n; j++) s[j] = ((a[j] >> i) & 1) ^ s[j - 1];
        for(int j = 1; j <= n; j++) s[j] += s[j - 1];
        for(int j = 1; j <= n; j++) {
            LL lw = j - l[j] + 1, rw = r[j] - j + 1;
            LL l0 = s[j - 1] - s[max(0, l[j] - 2)], r0 = s[r[j]] - s[j - 1];
            LL l1 = lw - l0, r1 = rw - r0;
            LL cur = (1LL * l0 * r1 % MOD + 1LL * l1 * r0 % MOD) % MOD;
            ans = (ans + 1LL * a[j] * cur % MOD * (1LL << i) % MOD) % MOD;
            ans %= MOD;
        }
    }
    printf("%d\n", int(ans));
}


int main() {
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++) run();
    return 0;
}
