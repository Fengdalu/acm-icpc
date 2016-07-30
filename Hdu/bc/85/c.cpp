#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

bool check(ll x) {
    for(ll i = 2; i * i <= x; i++) {
        int cnt = 0;
        while(x % i == 0) {
            cnt++;
            x /= i;
        }
        if(cnt > 1) return false;
    }
    return true;
}

int main() {
    int _T;
    scanf("%d", &_T);
    while(_T--) {
        ll x; cin >> x;
        ll k = sqrt(x);
        ll ans = 1ll << 62;
        while(true) {
            if(check(k)) {
                if(k >= 2)
                ans = min(ans, x - k * k);
                break;
            }
            k--;
        }
        k = sqrt(x);
        if(k * k < x) k++;
        while(true) {
            if(check(k) && k >= 2) {
                ans = min(ans, k * k - x);
                break;
            }
            k++;
        }
        cout << ans << endl;
    }
    return 0;
}
