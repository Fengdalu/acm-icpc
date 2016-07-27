#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define LL long long
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
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define FORR(i, n) for(int i = 1; i <= (n); i++)
#define ECH(x) for(__typeof x.OP it = x.OP; it != x.ED; it++)

#define N 3000
#define M 100000
#define INF 0x7fffffff

int ind[N], pre[N], f[N];
bool vis[N];
int bg[M], t[M], nt[M], c[M], op[M], v[M];
int cnt;
int S, T;

int add(int a, int b, int C, int V) //	`不要直接调用`
{
    bg[cnt] = a;
    t[cnt] = b;
    v[cnt] = V;
    c[cnt] = C;
    nt[cnt] = ind[a];
    ind[a] = cnt;
    return cnt++;
}

int ADD(int a, int b, int c, int v) //`添加边, 容量C, 价值V`
{
    int x = add(a, b, c, v);
    int y = add(b, a, 0, -v);
    op[x] = y; op[y] = x;
    return x;
}

int h[N], q[N];

bool spfa()
{
    memset(vis, 0, sizeof vis);
    for(int i = S; i <= T; i++) f[i] = INF;
    for(int i = S; i <= T; i++) pre[i] = -1;
    pre[S] = -1;
    f[S] = 0;
    int l = 0, r = 0; q[l] = S; vis[S] = true;
    while(l <= r)
    {
        int x = q[l % N];
        l++; vis[x] = false;
        for(int k = ind[x]; k != -1; k = nt[k])
        if(c[k] > 0 && f[t[k]] > f[x] + v[k])
        {
            f[t[k]] = f[x] + v[k];
            pre[t[k]] = k;
            if(!vis[t[k]])
            {
                r++;
                q[r % N] = t[k];
                vis[t[k]] = true;
            }
        }
    }
    return pre[T] != -1;
}

LL dfs()
{
    int ans = INF;
    int k = pre[T];
    while(k != -1)
    {
        ans = min(ans, c[k]);
        k = pre[bg[k]];
    }
    k = pre[T];
    while(k != -1)
    {
        c[k] -= ans;
        c[op[k]] += ans;
        k = pre[bg[k]];
    }
    return ans;
}

LL dinic() // `程序入口`
{
    LL ans = 0, tmp;
    while(spfa())
    {
        ans += (LL)f[T] * dfs();
    }
    return ans;
}


int n, m;
int main()
{
    while(~scanf("%d%d", &n, &m)){
    memset(ind, -1, sizeof ind);
    cnt = 0;
    S = 0; T = n + 1;
    FOR(i, m)
    {
        int x, y, V; scanf("%d%d%d", &x, &y, &V);
        ADD(x, y, 1, V);
        ADD(y, x, 1, V);
    }
    ADD(S, 1, 2, 0);
    ADD(n, T, 2, 0);
    printf("%I64d\n", dinic());
    }
    return 0;
}
