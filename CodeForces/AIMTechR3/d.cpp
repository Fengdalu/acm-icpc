#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


ll mk(ll tot) {
    ll n = 0;
    ll ans = 1;
    for(ll i = 1; n + i <= tot; i++) {
        n += i;
        ans++;
    }
    if(n == tot) return ans;
    return -1;
}

int main() {
    ll a, b, c, d;
    ll n0 = 0, n1 = 0;
    cin >> a >> c >> b >> d;
    if(a + b + c + d == 0) {
        cout << 0 << endl;
        return 0;
    }
    if(a == 0 && d == 0) {
        if(b == 0 && c == 0)  {
            printf("Impossible");
            return 0;
        }
        else n0 = n1 = 1;
    }
    else if(a == 0) {
        if(b != 0 || c != 0) n0 = 1;
        if((n1 = mk(d)) == -1) {
            printf("Impossible");
            return 0;
        }
    }
    else if(d == 0) {
        if(b != 0 || c != 0) n1 = 1;
        if((n0 = mk(a)) == -1) {
            printf("Impossible");
            return 0;
        }
    }
    else {
        n0 = mk(a);
        n1 = mk(d);
        if(n0 == -1 || n1 == -1) {
            printf("Impossible");
            return 0;
        }
    }
    if(b + c != n1 * n0) {
        printf("Impossible");
        return 0;
    }
    else {
        vector<int>p;
        ll sum = c;
        for(int i = n0; i >= 0; i--) {
            while(n1 && sum - i >= 0)  {
                p.push_back(i);
                sum -= i;
                n1--;
            }
        }
        sort(p.begin(), p.end());
        int J = 0;
        for(int i = 0; i <= n0; i++) {
            if(i != 0)
            printf("0");
            while(J < p.size() && p[J] <= i) printf("1"), J++;
        }
    }
    return 0;
}
