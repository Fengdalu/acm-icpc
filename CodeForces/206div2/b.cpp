#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
int n, m;
int a[2000], b[2000];

void cmin(ll &a, ll b) {
    a = min(a, b);
}

int main()  {
    ll c1, c2, c3, c4;
    cin >> c1 >> c2 >> c3 >> c4;
    cin >> n >> m;
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < m; i++) scanf("%d", &b[i]);
    sort(a, a + n);
    sort(b, b + m);
    ll ta = 0;
    ll tb = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ta += min(c1 * a[i], c2);
    }
    ta = min(ta, c3);
    for(int i = 0; i < m; i++) {
        tb += min(c1 * b[i], c2);
    }
    tb = min(tb, c3);
    cout << min(c4, ta + tb) << endl;
    return 0;
}
