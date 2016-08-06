#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

typedef long long ll;

int a[100010];
int f[100010];
int main() {
    int _T; scanf("%d", &_T);
    while(_T--) {
        int n; scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        if(n == 3) {
            cout << 1ll * abs(a[0] - a[1]) + abs(a[1] - a[2]) + abs(a[0] - a[2]) << endl; continue;
        }
        int cnt = 0;
        ll ans = 0;
        for(int i = 0; i < n - 1; i++) f[cnt++] = -abs(a[i + 1] - a[i]);
        nth_element(f, f + 2, f + cnt);
        sort(f, f + 3);
        for(int i = 0; i < n - 1; i++) f[i] = -f[i];
        for(int i = 1; i < n - 1; i++) {
            int p = abs(a[i] - a[i - 1]);
            int q = abs(a[i + 1] - a[i]);
            if(p < q) swap(p, q);
            if(p == f[0] && q == f[1]) ans += 1ll * max(f[2], abs(a[i + 1] - a[i - 1]));
            else if(p == f[0]) ans += 1ll * max(f[1], abs(a[i + 1] - a[i - 1]));
            else ans += 1ll * max(f[0], abs(a[i + 1] - a[i - 1]));
        }
        int t = -1;
        for(int i = 1; i < n - 1; i++) t = max(t, abs(a[i] - a[i + 1]));
        ans += 1ll * t;
        t = -1;
        for(int i = 0; i < n - 2; i++) t = max(t, abs(a[i] - a[i + 1]));
        ans += 1ll * t;
        cout << ans << endl;
    }
    return 0;
}
