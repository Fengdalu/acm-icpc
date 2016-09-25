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
#define BG begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)

#define NAME ""

#define Maxn 101111
int n;
int a[Maxn], b[Maxn];
map<int, int> ma, mb, mboth;

int check1(int a[], int b[]) {
    int i, j, k, u, v, w;
    ma.clear(); mb.clear(); mboth.clear();
    for(i = 0; i < n; i++) {
        ma[a[i]]++;
        mb[b[i]]++;
        if(a[i] == b[i]) mboth[a[i]]++;
    }
    int ret = n + 1;
    for(i = 0; i < n; i++) {
        if(ma[a[i]] + mb[a[i]] - mboth[a[i]] >= (n + 1) / 2) {
            cmin(ret, max(0, (n + 1) / 2 - ma[a[i]]));
        }
    }
    for(i = 0; i < n; i++) {
        if(mb[b[i]] + ma[b[i]] - mboth[b[i]] >= (n + 1) / 2) {
            cmin(ret, max(0, (n + 1) / 2 - ma[b[i]]));
        }
    }
    if(ret > n) ret = -1;
    return ret;
}

int main() {
    int i, j, k, u, v, w;
    //freopen(NAME".in", "r", stdin);
    //freopen(NAME".out", "w", stdout);
    while(cin >> n ) {
        for(i = 0; i < n; i++) cin >> a[i] >> b[i];
        int ans = check1(a, b);
        cout << ans << endl;
    }
    return 0;
}
