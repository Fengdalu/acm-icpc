#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MOD 0x3f3f3f3f
#define INF 1000000000
#define LL long long
#define AA first
#define BB second
#define PII pair<int, int>
#define MP(x, y) make_pair(x, y)
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define M 1000000
#define N 62

PII e[M];
bool vis[N];
int c[N];
int n, m;

int chk()
{
    for(int i = 0; i < m; i++) if(!vis[e[i].AA] && !vis[e[i].BB]) return false;
    return true;
}
int ans = INF;
int tot;
void dfs(int x)
{
    if(x == n + 1)
    {
        if(chk()) cmin(ans, tot);
        return ;
    }
    if(c[x] + tot < ans)
    {
        vis[x] = true;
        tot += c[x];
        dfs(x + 1);
        vis[x] = false;
        tot -= c[x];
    }
    dfs(x + 1);}

int main()
{
    while(~scanf("%d%d", &n, &m)) {
        for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
        for(int i = 0; i < m; i++) scanf("%d%d", &e[i].AA, &e[i].BB);
        ans = INF;
        tot = 0;
        dfs(1);
        printf("%d\n", ans);
    }
    return 0;
}
