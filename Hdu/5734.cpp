#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
int w[1000010];
int b[1000010];

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n) ;
        for(int i = 0; i < n; i++) scanf("%d", &w[i]);
        for(int i = 0; i < n; i++)
        if(w[i] > 0) b[i] = 1; else b[i] = -1;
        ll up = 0, down = 0;
        ll up1 = 0;
        for(int i = 0; i < n; i++) {
            up1 += b[i] * (ll)w[i];
            up += w[i] * w[i] * (ll)n;
        }
        down = n;
        up -= up1 * up1;
        ll c = gcd(up, down);
        cout << up / c << "/" << down / c << endl;
    }
    return 0;
}

