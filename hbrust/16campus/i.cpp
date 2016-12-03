#include <bits/stdc++.h>
#define cmin(x, y) x = std::min(x, y)

using namespace std;
typedef long long LL;
const int N = 2e5;
int a[N];

int main() {
    int n, k;
    while(~scanf("%d%d", &n, &k)) {
        for(int i = 0; i < n; i++) scanf("%d", a + i);
        sort(a, a + n);
        LL ans = 0;
        for(int i = 0; i < n; i++) {
            int g = a[i] + k;
            ans += 1LL * (upper_bound(a, a + n, g) - lower_bound(a, a + n, g));
        }
        printf("%lld\n", ans);
    }
    return 0;
}
