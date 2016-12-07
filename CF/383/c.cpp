#include <bits/stdc++.h>

using namespace std;
const int N = 2000;
typedef long long LL;
int to[N], vis[N];

LL lcm(LL a, LL b) {
    return a / __gcd(a, b) * b;
}

int main() {
    int n; scanf("%d", &n);
    memset(vis, 0, sizeof vis);
    for(int i = 1; i <= n; i++) scanf("%d", &to[i]);
    LL ans = 1;
    for(int i = 1; i <= n; i++) if(!vis[i]) {
        int k = i, s = 0;
        do {
            vis[k] = true;
            s++;
            k = to[k];
        } while(!vis[k]);
        if(k != i) {
            puts("-1");
            return 0;
        }
        if(s & 1) ans = lcm(ans, s);
        else ans = lcm(ans, s / 2);
    }
    printf("%I64d\n", ans);
    return 0;
}
