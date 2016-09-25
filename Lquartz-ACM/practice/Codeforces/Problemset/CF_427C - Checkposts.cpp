//#pragma comment(linker,"/STACK:102400000,102400000")
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define BGN begin()
#define END end()
#define SZ size()
#define SORT(p) sort(p.BGN,p.ED)
#define CLR(a, b) memset(a, (b), sizeof(a))
#define mabs(x) (x < 0 ? -x : x)
#define sqr(x) ((x)*(x))
#define ITE ::iterator
#define INF (1LL<<62)
typedef long long LL;
typedef pair<int, int> PII;
typedef vector <int> VI;
typedef set < int > SI;

#define N 111111
#define M 444444
#define MOD 1000000007LL

int n, m;
/*
*TarjanSCC_adj_list
*/

struct edgenode
{
    int u, v, next;
} edge[2*M];
int tot, last[N];
int dfn[N], low[N], belong[N], instack[N], ncnt, nindex;
int cost[N];
stack <int > sta;
LL dmin[N], dnum[N];

void addedge(int x, int y)
{
    edge[tot].u = x; edge[tot].v = y; edge[tot].next = last[x]; last[x] = tot++;
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
            while(!sta.empty()) sta.pop();
            Tarjan(i);
        }
//    ///*
//    for(int i = 1; i <= n; i++)
//        printf("%d %d\n", i, belong[i]);
    //*/
}

int main() {
    int Test;
    while(scanf("%d", &n) != EOF){
        for(int i = 1; i <= n; i++) {
            scanf("%d", &cost[i]);
        }
        scanf("%d", &m);
        memset(last, -1, sizeof(last));
        tot = 0;
        for(int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            addedge(u, v);
        }
        solve();
        LL ans = 0;
        LL num = 1;
        for(int i = 1; i <= ncnt; i++) {
            dmin[i] = INF;
            dnum[i] = 0;
        }
        for(int i = 1; i <= n; i++) {
            int c = belong[i];
            if(dmin[c] > cost[i]) {
                dmin[c] = cost[i];
                dnum[c] = 1;
            }
            else if(dmin[c] == cost[i]) {
                dnum[c]++;
            }
        }
        for(int i = 1; i < ncnt; i++) {
            ans += dmin[i];
            num *= dnum[i];
            num %= MOD;
        }
        cout << ans << " " << num << endl;
    }
    return 0;
}
