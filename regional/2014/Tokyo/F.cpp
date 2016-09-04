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
#define N 1000

int n, m;
typedef pair<int, PII> node;
vector <node>E;
vector <int>ES;
int f[N];

int find(int x)
{
    if(f[x] == x) return x;
    f[x] = find(f[x]);
    return f[x];
}

void merge(int x, int y)
{
    f[find(x)] = find(y);
}

int MST(int q)
{
    FORR(i, n) f[i] = i;
    int ans = 0;
    int cnt = 0;

    FOR(i, E.SZ)
    if(q != i && find(E[i].BB.AA) != find(E[i].BB.BB))
    {
        cnt++;
        ans += E[i].AA;
        if(q == -1) ES.PB(i);
        merge(E[i].BB.AA, E[i].BB.BB);
        if(cnt == n - 1) break;
    }
    return ans;
}

int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        E.CLR;
        FOR(i, m) { int S, D, V; scanf("%d%d%d", &S, &D, &V); if(S > D) swap(S, D); E.PB(node(V, MP(S, D)));  }
        sort(E.OP, E.ED);
        ES.CLR;
        int V = MST(-1);
        int cnt = 0; LL ans = 0;

        ECH(ES)
        {
            if(MST(*it) != V) { cnt++; ans += (LL)E[*it].AA; }
        }
        printf("%d %lld\n", cnt, ans);
    }
    return 0;
}
