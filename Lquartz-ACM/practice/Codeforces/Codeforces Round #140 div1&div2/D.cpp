//#include <bits/stdc++.h>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define SZ size()
#define AA first
#define BB second
#define BG begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)

#define Maxn 111111
int n, m;
LL g[Maxn];
LL ans[Maxn];
LL sum[Maxn];
int q[Maxn];

int main() {
    int i, l;
    LL j;
    LL k;
    LL u, v, w;
    while(cin >> n) {
        sum[0] = 0;
        for(i = 1; i <= n; i++) {
            cin >> g[i];
        }
        sort(g + 1, g + n + 1);
        for(i = 1; i <= n; i++) sum[i] = sum[i - 1] + g[i];
        for(k = 1; k <= n; k++) {
            LL tp = 0;
            i = n;
            w = 0;
            u = 1;
            do {
                u *= k;
                j = i - u;
                l = max(j, 1LL);
                //printf("liu %d %d %d\n", i, j, l);
                w++;
                tp += w * (sum[i - 1] - sum[l - 1]);
                //printf("%lld %lld %lld %lld\n", tp, w, sum[i - 1], sum[l - 1]);
                if(j <= 0) break;
                i = j;
            } while(true);
            ans[k] = tp;
        }
        cin >> m; 
        for(i = 0; i < m; i++) cin >> q[i];
        for(i = 0; i < m; i++) {
            k = q[i];
            if(k > n) cout << ans[n] ;
            else cout << ans[k] ;
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}
