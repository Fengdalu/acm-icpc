#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int a[100010];
typedef long long ll;
int main() {
    int n, h, tot = 0, k;
    ll ans = 0;
    scanf("%d%d%d", &n, &h, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    ll s = 0;
    ll J = 0;
    while(J < n) {
        while(J < n && s + a[J] <= h) {
            s += a[J];
            J++;
        }
        if(J == n) break;
        ll p = (s + a[J]) - h;
        p = (p + k - 1) - (p + k - 1) % k;
        p = min(p, (ll)s);
        ans += (p + k - 1) / k;
        s -= p;
    }
    ans += (s + k - 1) / k;
    cout << ans << endl;
    return 0;
}
