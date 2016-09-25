#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;
typedef int LL;
typedef pair<int, int> PII;
 
#define PB push_back
#define PF push_front
#define PPB pop_back
#define PPF pop_front
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define OP begin()
#define ED end()
#define SORT(x) sort(x.begin(), x.end())
#define SQ(x) ((x)*(x))
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)
 
const double eps = 1e-8;
const LL MOD = 10007;
const LL INF = 0x3f3f3f3f;
#define Maxn 311
#define Maxm 111111

int tot;
//求n阶方阵的行列式
//MST计数调用detMod(n-1, a, MOD)
LL detMod(int n, LL a[][Maxn], LL MOD) {
    LL ret = 1;
    int i, j, k, t;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            a[i][j] = (a[i][j] + MOD) % MOD;
        }
    }
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++){
            while(a[j][i]) {
                t = a[i][i] / a[j][i];
                for(k = i; k < n; k++) {
                    a[i][k] = (a[i][k] - a[j][k] * t) % MOD;
                    swap(a[i][k], a[j][k]);
                }
                ret = -ret;
            }
        }
        if(a[i][i] == 0) return 0;
        ret = ret * a[i][i] % MOD;
    }
    return (ret + MOD) % MOD;
}

int fa[Maxn];
int getfa(int x) {return (fa[x] == x ? x : (fa[x] = getfa(fa[x])));}
LL a[Maxn][Maxn], b[Maxn][Maxn];
vector<PII> pt;

int n, R;
int main() {
    int i, j, k, u, v, w;
    int xx0, xx1, yy0, yy1;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    int te;
    scanf("%d", &te);
    for(int ca = 1; ca <= te; ca++) {
        scanf("%d%d", &n, &R);
        R *= R;
        pt.clear();
        for(i = 0; i < n; i++) {
            scanf("%d%d", &u, &v);
            pt.PB(MP(u, v));
        }
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                a[i][j] = b[i][j] = 0;
            }
        }
        sort(pt.OP,pt.ED);
        for(i = 0; i < n; i++) {
            for(j = i + 1; j < n; j++) {
                int dist = SQ(pt[i].AA - pt[j].AA) + SQ(pt[i].BB - pt[j].BB);
                if(dist <= R) {
                    xx0 = min(pt[i].AA, pt[j].AA); 
                    xx1 = max(pt[i].AA, pt[j].AA);
                    yy0 = min(pt[i].BB, pt[j].BB);
                    yy1 = max(pt[i].BB, pt[j].BB);
                    for(k = i + 1; k < j; k++) {
                        if(xx0 <= pt[k].AA && pt[k].AA <= xx1
                        && yy0 <= pt[k].BB && pt[k].BB <= yy1) {
                            if((pt[k].AA - pt[i].AA ) * (pt[j].BB - pt[i].BB) ==
                               (pt[k].BB - pt[i].BB ) * (pt[j].AA - pt[i].AA)) break;
                        }
                    }
                    if(k >= j){
                        a[i][i]++; a[j][j]++;
                        b[i][j]++; b[j][i]++;
                    }
                }
            }
        }
        for(i = 0; i < n; i++) fa[i] = i;
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(b[i][j]) {
                    fa[getfa(j)] = getfa(i);
                }
            }
        }
        LL ans = 0;
        for(j = 0; j < n; j++) if(getfa(j) != getfa(0)) break;
        if(j < n) {
            printf("-1\n");
            continue;
        }
        for(i = 0; i < n; i++) {
            for(j = 0; j< n; j++) {
                a[i][j] -= b[i][j];
            }
        }
        printf("%d\n", detMod(n - 1, a, MOD));
    }
    return 0;
}
