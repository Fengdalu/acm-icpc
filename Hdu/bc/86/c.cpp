#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;

int f[200010];
int main() {
    int _T; scanf("%d", &_T);
    while(_T--) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        f[0] = 0;
        for(int i = 1; i <= n; i++) {
            int x; scanf("%d", &x);
            f[i] = f[i - 1] + 1 * (x >= m);
        }
        ll ans = 0;
        for(int i = 1; i <= n; i++) {
            int l = 0, r = i;
            while(l < r) {
                int mid = (l + r + 1) / 2;
                if(f[i] - f[mid] >= k) l = mid;
                else r = mid - 1;
            }
            if(f[i] - f[l] >= k) ans += 1ll * max(0, min(n - k + 1, l + 1));
        }
        cout << ans << endl;
    }
    return 0;
}
