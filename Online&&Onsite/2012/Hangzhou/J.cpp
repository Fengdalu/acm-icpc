#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define LL long long
#define u32  unsigned int
#define AA first
#define BB second
typedef pair<int, int> PII;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define PB(x) push_back(x)
#define SZ size()
#define MP(a, b) make_pair(a, b)
#define OP begin()
#define ED end()
#define CLR clear()
#define INS(x) insert(x)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORR(i, n) for(int i = 1; i <= n; i++)
#define MEM(a) memset(a, 0, sizeof a)
#define ECH(x) for(__typeof x.OP it = x.OP; it != x.ED; it++)
#define ONES(x) __builtin_popcount(x)
/*===========================================================*/
#define N 51

int n, K;
bool f[N][N];
int x[N], y[N], r[N];

int main()
{
    //freopen("input.txt", "r", stdin);
    while(~scanf("%d", &n))
    {
        if(!n) break;
        scanf("%d", &K);
        FOR(i, K) scanf("%d%d", &x[i], &y[i]);
        FOR(i, K) scanf("%d", &r[i]);

        int ans = K + 1;

        FOR( m, (1 << K) )
        {
            memset(f, 0, sizeof f);
            FOR(k, K) f[x[k]][y[k]] = true;
            FOR(k, K) if( m & (1 << k) )
            {
                for(int i = max(1, x[k] - r[k]); i <= min(n, x[k] + r[k]); i++)
                {
                    int o = (r[k] - abs(i - x[k]));
                    for(int j = max(1, y[k] - o); j <= min(n, y[k] + o); j++)
                    f[i][j] = true;
                }
            }
            bool flg = false;
            FORR(i, n) if(!flg) FORR(j, n) if(!flg) if(!f[i][j]) flg = true;
            if(!flg) ans = min(ans, ONES(m));
        }
        if(ans != K + 1)printf("%d\n", ans); else printf("-1\n");
    }
    return 0;
}
