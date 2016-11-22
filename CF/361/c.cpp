#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <queue>
using namespace std;

typedef long long ll;

ll cal(ll x) {
    ll ans = 0;
    for(ll k = 2; ; k++) {
        ll t = k * k * k;
        if(t > x) break;
        else ans += x / t;
    }
    return ans;
}

int main() {
    ll m;
    cin >> m;
    ll l = 0, r = 1LL << 62;
    while(l < r) {
        ll mid = (l + r) / 2LL;
        if(cal(mid) < m) l = mid + 1;
        else r = mid;
    }
    if(cal(l) == m)
    cout << l << endl;
    else cout << -1 << endl;
    return 0;
}
