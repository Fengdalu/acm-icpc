#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    ll n, a, b, p, q, ans = 0;
    cin >> n >> a >> b >> p >> q;
    ll n1 = n / a;
    ll n2 = n / b;
    ll n3 = n / lcm(a, b);
    n1 -= n3; n2 -= n3;
    ans = n1 * p + n2 * q + n3 * max(p, q);
    cout << ans << endl;
}
