#include <bits/stdc++.h>
using namespace std;
#define AA first
#define BB second
typedef pair<int, int> PII;
typedef long long ll;

int main() {
    ll d, k, a, b, t;
    cin >> d >> k >> a >> b >> t;
    if(d <= k) {
        cout << a * d << endl;
        return 0;
    }
    ll tot = a * k;
    d -= k;
    if(t + a * k >= b * k)  {
        cout << tot + d * b;
    }
    else {
        ll loop = d / k;
        tot += loop * (t + a * k);
        d -= loop * k;
        cout << tot + min(t + a * d, b * d);
    }
    return 0;
}
