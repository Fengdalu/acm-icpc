#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define FOR(i, n) for(int i = 0; i < n; i++)
#define AA first
#define BB second
#define PB(x) push_back(x)
#define SZ size()
#define MP(a, b) make_pair(a, b)
#define OP begin()
#define ED end()
#define CLR clear()
typedef pair<int, int> PII;
#define N 100010

vector<int>G[N];
int c[N];
int fa[N];
int n, m;

int dfs(int x, int cnt)
{
    if(c[x]) cnt++; else cnt = 0;
    if(cnt > m) return 0;
    if(G[x].SZ == 1 && G[x][0] == fa[x]) return 1;
    int tot = 0;
    for(int i = 0; i < G[x].SZ; i++)
    if(G[x][i] != fa[x])
    {
        fa[G[x][i]] = x;
        tot += dfs(G[x][i], cnt);
    }
    return tot;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
    for(int i = 1; i <= n; i++) G[i].clear();
    for(int i = 1; i < n; i++)
    {
        int x, y; scanf("%d%d", &x, &y);
        G[x].PB(y); G[y].PB(x);
    }
    int ans = dfs(1, 0);
    printf("%d\n", ans);
	return 0;
}
