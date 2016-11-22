#include <bits/stdc++.h>
using namespace std;
#define SQR(x) (x * x)
typedef long long ll;
ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

bool chk1(ll a) {
    for(ll i = 1; i * i <= a; i++) {
        ll b = sqrt(a - i * i);
        if(b * b != a - i * i) continue;
        if(gcd(b, i) != 1) continue;
        if(b < i * i) return false;
        ll x = i, y = b; if(x < y) swap(x, y);
        if(x == y) continue;
        cout << SQR(x) - SQR(y) << " " << 2ll * x * y << " " << endl;
        return true;
    }
    return false;
}

bool chk2(ll a) {
    if(a % 2 == 0 && a != 0) {
        a /= 2;
        for(ll i = 1; i * i <= a; i++) if(a % i == 0){
            ll x = i, y = a / i;
            if(x < y) swap(x, y);
            if(x == y) continue;
            if(gcd(x, y) == 1) {
                cout << SQR(x) - SQR(y) << " " << SQR(x) + SQR(y) << endl;
                return true;;
            }
        }
        return false;
    }
    return false;
}

bool chk3(ll a) {
    for(ll i = 1; i * i <= a; i++) if(a % i == 0) {
            ll aa = a / i, bb = i;
            ll p = (aa + bb - 2);
            if(p <= 0 || p % 2 == 1) continue;
            ll B = p / 2;
            ll A = aa - B - 1;
            B++;
            if(A <= 0) continue;
            if(A == B) continue;
            if(A < B) swap(A, B);
            cout << 2ll * A * B << " " << SQR(A) + SQR(B) << endl;
            return true;
        }
    return false;
}


int main() {
    ll a;
    cin >> a;
    if(chk1(a)) return 0;
    if(chk2(a)) return 0;
    if(chk3(a)) return 0;
    puts("-1");
    return 0;
}
