#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
typedef long long ll;
int r[maxn], c[maxn];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int cnt = 0;
    ll tot = (ll)n * (ll)n;
    ll n1 = 0, n2 = 0;
    for(int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y); x--; y--;
        int flag = 0;
        if(!r[x]) { tot -= n - n2; n1++; flag++; }
        if(!c[y]) { tot -= n - n1; n2++; flag++; }
        r[x] = c[y] = 1;
        printf("%lld ", tot);
    }
    return 0;
}
