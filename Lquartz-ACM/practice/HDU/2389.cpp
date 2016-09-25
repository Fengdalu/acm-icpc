#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define Maxn 6100
#define Maxm 9800000
#define MOD 1000000007

#define SQ(x) ((x)*(x))
/*
* HopcroftKarp
* ¡ŸΩ”±Ì
*/

//int preHungary()
//{
//	int res = 0, u, v;
//	for(int i = 1; i <= n; i++)
//	{
//		u = i;
//		for(int j = last[u]; j != -1; j = e[j].next)
//		{
//			v = e[j].v;
//			if(-1 == my[v])
//			{
//				mx[u] = v;
//				my[v] = u;
//				res++;
//				break;
//			}
//		}
//	}
//	return res;
//}
/*
 *  HK O(E*V^0.5) ◊Ó¥Û∆•≈‰
 *  ◊Û∞ÎÕº 0~n-1
 *  ”“∞ÎÕº n~n+m-1
 */
 struct edgenode {
	int v, next;
}e[Maxm];
int last[Maxn], tot;
int n, m, match = 0;
int mx[Maxn], my[Maxn], dx[Maxn], dy[Maxn], dis, visit[Maxn];
queue<int> Q;
int ux[Maxn], uy[Maxn], px[Maxn], py[Maxn], pv[Maxn];

void adde(int u, int v) {
    e[tot].v = v; e[tot].next = last[u]; last[u] = tot++;
}
bool searchPath()
{
    int i, j;
	dis = MOD;
	for(i = 0; i < n; i++) dx[i] = -1;
	for(j = n; j < n + m; j++) dy[j] = -1;
	while(!Q.empty()) Q.pop();
	for(int i = 0; i < n; i++)
		if(-1 == mx[i]) Q.push(i);
	int u, v;
	while(!Q.empty())
	{
		u = Q.front(); Q.pop();
		if(dx[u] > dis) break;
		for(int j = last[u]; j != -1; j = e[j].next)
		{
			v = e[j].v;
			if(-1 != dy[v]) continue;
			dy[v] = dx[u] + 1;
			if(-1 == my[v])
				dis = dy[v];
			else
			{
				dx[my[v]] = dy[v] + 1;
				Q.push(my[v]);
			}
		}
	}
	return dis != MOD;
}

bool dfs(int u)
{
	int v;
	for(int j = last[u]; j != -1; j = e[j].next)
	{
		v = e[j].v;
		if(visit[v] || dx[u] + 1 != dy[v]) continue;
		if(dy[v] == dis && my[v] != -1) continue;
		visit[v] = true;
		if(-1 == my[v] || dfs(my[v]))
		{
			my[v] = u;
			mx[u] = v;
			return true;
		}
	}
	return false;
}

int solve()
{
    int i, j;
	match = 0;
	for(i = 0; i < n; i++) mx[i] = -1;
	for(j = n; j < n + m; j++) my[j] = -1;
//	match += preHungary();
	while(searchPath())
	{
		for(j = n; j < n + m; j++) visit[j] = false;
		for(int i = 0; i < n; i++)
			if(-1 == mx[i] && dfs(i)) match++;
	}
	return match;
}

int main() {
    int i, j, d, dd, u, v, w, te, t;
    scanf("%d", &te);
    for(int ca = 1; ca <= te; ca++) {
        scanf("%d", &t);
        scanf("%d", &n);
        for(i = 0; i < n; i++) {
            scanf("%d%d%d", &px[i], &py[i], &pv[i]);
        }
        scanf("%d", &m);
        for(i = 0; i < m; i++) {
            scanf("%d%d", &ux[i], &uy[i]);
        }
        tot = 0;
        for(i = 0; i < n + m; i++) last[i] = -1;
        for(i = 0; i < n; i++) {
            d = SQ(t * pv[i]);
            for(j = 0; j < m; j++) {
                dd = SQ(px[i] - ux[j]) + SQ(py[i] - uy[j]);
                if(d >= dd) {
                    adde(i, j + n);
                }
            }
        }
        printf("Scenario #%d:\n", ca);
        printf("%d\n", solve());
        printf("\n");
    }
    return 0;
}
