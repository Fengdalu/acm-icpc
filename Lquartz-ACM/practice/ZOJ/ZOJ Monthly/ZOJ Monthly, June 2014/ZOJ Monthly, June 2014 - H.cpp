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
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define OP begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)

const double eps = 1e-8;
const LL MOD = 1000000007;
#define N 101000
#define M 301000

/*
*TarjanSCC_adj_list
*/
      
struct edgenode
{
    int u, v, next;
} edge[2*M];
int tot, last[N];
int dfn[N], low[N], belong[N], instack[N], ncnt, nindex, cnt[N], sum[N], ind[N];
stack<int> sta;
map<PII, int> dmap;
queue<int> Q;
int n, m;   
void addedge(int u, int v)
{
//    cout << "add " << u << " " << v << endl;
    edge[tot].u = u; edge[tot].v = v; edge[tot].next = last[u]; last[u] = tot++;
}
      
void Tarjan(int u)   //Tarjan
{
    dfn[u] = low[u] = nindex++;   //给dfn和low赋初始值
    sta.push(u);    //将节点压栈
    instack[u] = 1;
    for(int j = last[u]; j != -1; j = edge[j].next)
    {
        int v = edge[j].v;
        if(!dfn[v])        //未遍历，即未在栈内的节点
        {
            Tarjan(v);
            if(low[u] > low[v])
                low[u] = low[v];
        }
        else if(instack[v] && dfn[v] < low[u]) //已经入栈的节点
            low[u] = low[v];
    }
    if(dfn[u] == low[u])      //弹出root及之上的节点， 为一个强连通分量
    {
        //并且标记或者染色
        int i;
        do
        {
            i = sta.top();
            instack[i] = 0;
            belong[i] = ncnt;
            sta.pop();
        }
        while(i != u);
        ncnt++;
    }
}
      
void solve()
{
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(instack, 0, sizeof(instack));
    memset(belong, 0, sizeof(belong));
    ncnt = 1;
    nindex = 1;
    for(int i = 1; i <= n; i++)
        if(0 == dfn[i])
        {
            Tarjan(i);
        }
    ///*
//    for(int i = 1; i <= n; i++)
//        printf("%d %d\n", i, belong[i]);
    //*/
}
vector<int> gao[N];
int main() {
    int i, j, x, y, u, v;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    while(scanf("%d%d", &n, &m) != EOF) {
        for(i = 0; i <= n; i++) last[i] = -1;
        tot = 0;
        for(i = 0; i < m; i++) {
            scanf("%d%d", &x, &y);
            addedge(x, y);
        }
        solve();
        dmap.clear();
        for(i = 0; i <= ncnt; i++) {
            gao[i].clear();
            ind[i] = 0;
            cnt[i] = 0;
        }
        for(i = 1; i <= n; i++) cnt[belong[i]]++;
        for(i = 0; i < tot; i++) {
            x = belong[edge[i].u], y = belong[edge[i].v];
//            cout << "a " << x << " " << y << endl;
            if(x != y) {
                if(dmap[MP(x, y)] == 0) {
//                    cout << "gao " << x << " " << y << endl;
                    dmap[MP(x, y)] = 1;
                    gao[x].PB(y);
                    ind[y] ++;
                }
            }
        }
        while(!Q.empty()) Q.pop();
        for(i = 1; i < ncnt; i++) {
            if(ind[i] == 0) Q.push(i);
            sum[i] = cnt[i];
//            cout << "cnt: " << cnt[i] << endl;
        }
        while(!Q.empty()) {
            u = Q.front(); Q.pop();
//            cout << "Q: " << u << endl;
            for(i = 0; i < gao[u].SZ; i++) {
                v = gao[u][i];
                ind[v]--;
//                cout << "sum " << sum[u] << " " << cnt[v] << " " << sum[v] << endl;
                if(sum[v] < sum[u] + cnt[v]) {
                    sum[v] = sum[u] + cnt[v];
                }
                if(ind[v] == 0) {
                    Q.push(v);
                }
            }
        }
        int ans = 0;
        for(i = 1; i < ncnt; i++) cmax(ans, sum[i]);
        printf("%d\n", ans);
    }
    return 0;
}

