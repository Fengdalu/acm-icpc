#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++) {
        int m; scanf("%d", &m);
        long long ans = 0;
        for(int i = 1; i <= m; i++) {
            ans += m - __gcd(i, m);
        }
        printf("Case %d: %I64d\n", cas, ans);
    }
    return 0;
}
