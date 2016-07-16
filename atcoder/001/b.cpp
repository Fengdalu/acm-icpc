#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k;
ll ans = 0;

void cal(ll w, ll x) {
    if(x == 1) { ans += 2 * w - 1; return; }
    ll t = w / x;
    if(w % x == 0) {
        ans += 2 * t * x - x;
    }
    else if(w % x != 0){
        ans += 2 * t * x;
        cal(x, w % x);
    }
}



int main() {
    cin >> n >> k;
    if(k > n / 2) k = n - k;
    ans = ans + k + n - k;
    cal(n - k, k);
    cout << ans << endl;
}

