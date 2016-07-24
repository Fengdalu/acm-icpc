#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
#define ONES(x) __builtin_popcount(x)

typedef long long ll;

const int maxn = 100100;
const int POW = 20;
int f[maxn][POW];
int mm[maxn];
int n, m;


int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

void init() {
    for(int i = 1; i <= n; i++) scanf("%d", &f[i][0]);
    for(int j = 0; j < POW; j++)
        for(int i = 1; i <= n; i++)
        if(i + (1 << (j + 1)) <= n + 1) {
            f[i][j + 1] = gcd(f[i][j], f[i + (1 << j)][j]);
        }
}


int qry(int l, int r) {
    int k = mm[r - l + 1];
    return gcd(f[l][k], f[r - (1 << k) + 1][k]);
}


int main() {
    mm[0] = -1;
    for(int i = 1; i < maxn; i++)
        if((i & (i - 1)) == 0) mm[i] = mm[i - 1] + 1;
        else mm[i] = mm[i - 1];

    int T, cas = 1;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        map<int, ll>ans;
        init();
        for(int i = 1; i <= n; i++) {
            int rr = n;
            while(true) {
                int l = i, r = rr;
                while(l < r) {
                    int mid = (l + r + 1) / 2;
                    if(qry(i, mid) != qry(i, rr)) l = mid;
                    else r = mid - 1;
                }
                int v = qry(i, rr);
                if(qry(i, l) == qry(i, rr)) {
                    ans[v] += (ll)rr - l + 1;
                    break;
                }
                ans[v] += (ll)rr - l;
                rr = l;
            }
        }
        printf("Case #%d:\n", cas++);
        scanf("%d", &m);
        for(int i = 0; i < m; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            int v = qry(x, y);
            printf("%d %I64d\n", v, ans[v]);
        }
    }
    return 0;
}
