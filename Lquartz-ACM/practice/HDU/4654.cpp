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
typedef long long LL;
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
const LL MOD = 1000000007;
const LL INF = 0x3f3f3f3f;
#define Maxn 111
#define Maxm 111
int n, m, k;
//朴素最小割
//注意节点下标0~n-1
int comb[Maxn];
int edge[Maxn][Maxn], g[Maxn][Maxn], node[Maxn];
int S, T, minCut;
int top, sta[Maxn];
int maxi;
vector<int> parta, partb;
vector<int> belong[Maxn];

int Search (int n) {
    int i, j, u;
    int vis[Maxn], wet[Maxn];
    memset(vis, 0, sizeof(vis)); 
    memset(wet, 0, sizeof(wet));
    int minCut = 0, temp = -1, top = 0;
    int maxi;
    S = -1, T = -1;
    for (i=0; i< n; i++) {
        maxi = -MOD;
        for (j = 0; j < n; j++) {
            u = node[j];
            if (!comb[u] && !vis[u] && wet[u] > maxi) {
                temp = u;
                maxi = wet[u];
            }
        }
        sta[top++] = temp;
        vis[temp] = true;
        if (i == n - 1)
            minCut = maxi;
        for (j = 0; j < n; j++) {
            u = node[j];
            if (!comb[u] && !vis[u]) {
                wet[u] += edge[temp][u];
            }
        }
    }
    S = sta[top - 2];
    T = sta[top - 1];
    for (i = 0; i < top; i++)  node[i] = sta[i];
    return minCut;
}

int StoerWagner (vector<int> & li) {
    int ans = MOD, i, j, k,cur, n = li.SZ, u, v;
    int used[Maxn];
    memset(comb, 0, sizeof(comb));
    for (i = 0; i < n; i++) {
        node[i] = i;
        belong[i].clear();
        belong[i].PB(i);
    }
    for (i = 1; i < n; i++) {
        k = n - i + 1;
        cur = Search(k);
        if (cur < ans) {
            ans = cur;
            for(j = 0; j < n; j++) used[j] = 0;
            for(j = 0; j < belong[T].SZ; j++) {
                used[belong[T][j]] = 1;
            }
        }
        for(j = 0; j < belong[T].SZ; j++) belong[S].PB(belong[T][j]);
        if (ans == 0) break;
        comb[T] = true;
        for (j = 0; j < n; j++) {
            if (j == S) continue;
            if (!comb[j]) {
                edge[S][j] += edge[T][j];
                edge[j][S] += edge[j][T];
            }
        }
    }
    parta.clear(); partb.clear();
    for(j = 0; j < n; j++) {
        if(used[j]) parta.PB(li[j]);
        else partb.PB(li[j]);
    }
    return ans;
}
int dfs(vector<int> &li) {
    int n = li.SZ, i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            edge[i][j] = g[li[i]][li[j]];
        }
    }
    int cur = StoerWagner(li);
    if(cur >= k) return 1;
    vector<int> a(parta), b(partb);
    return dfs(a) + dfs(b);
}
int main() {
    int i, j, u, v, w;
    while (scanf ("%d%d%d", &n, &m, &k) != EOF) {
        memset(g, 0, sizeof(g));
        for (int i = 0; i < m; i++) {
            scanf ("%d%d", &u, &v);
            u--; v--;
            g[u][v] += 1;
            g[v][u] += 1;
        }
        vector<int> li;
        for(i = 0; i < n; i++) li.PB(i);
        printf ("%d\n", dfs(li));
    }
    return 0;
}
