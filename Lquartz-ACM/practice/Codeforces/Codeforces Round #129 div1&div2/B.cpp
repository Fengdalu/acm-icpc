#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define OP begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)

#define NAME ""
#define Maxn 101111

int g[Maxn], dmax[Maxn], cnt[Maxn];
int n;

int main() {
    int i, j, k, u, v, w;
    //freopen(NAME".in", "r", stdin);
    //freopen(NAME".out", "w", stdout);
    while(cin >> n) {
        g[0] = 0;
        LL ans = 0;
        for(i = 1; i <= n; i++) cin >> g[i];
        dmax[0] = 0;
        for(i = 1; i <= n; i++) dmax[i] = max(dmax[i - 1], g[i]);
        cnt[0] = 0;
        for(i = 1; i <= n; i++) {
            if(g[i] < dmax[i - 1]) {
                cnt[i] = dmax[i - 1] - g[i];
            }
            else cnt[i] = 0;
            u = cnt[i] - cnt[i - 1];
            if(u > 0) ans += u;
        }
        cout << ans << endl;
    }
    return 0;
}
