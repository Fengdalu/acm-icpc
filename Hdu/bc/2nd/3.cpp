#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;
const int maxn = 100010;
const ll mod = 998244353LL;
ll a[maxn], b[maxn];
ll L, R;
pair<ll, ll> f[maxn];
int n;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        scanf("%I64d%I64d", &L, &R);
        for(int i = 0; i < n; i++) scanf("%I64d", &a[i]);
        sort(a, a + n);
        int cnt = 0;
        for(int i = 1; i < n; i++) {
            ll p = a[i] - a[i - 1] + 1;
            ll q = a[i] + a[i - 1] - 1;
            if(p > R || q < L) continue;
            p = max(p, L);
            q = min(q, R);
            if(p <= q) f[cnt++] = make_pair(p, q);
        }
        sort(f, f + cnt);
        ll ans = 0;
        if(cnt == 0) {
            cout << R - L + 1L << endl;
            continue;
        }
        ll l = f[0].first, r = f[0].second;
        for(int i = 0; i < cnt; i++) {
            if(f[i].first > r) {
                ans += r - l + 1;
                l = f[i].first;
            }
            r = max((ll)f[i].second, r);
        }
        ans += r - l + 1LL;
        cout << R - L + 1LL - ans << endl;
    }
    return 0;
}
