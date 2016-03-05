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
#define N 1001

vector<string>H;
int f[N][N];
char buf[1000];
int n;
int m;
deque<PII>Q;
vector<int>G[N];
string a, b;

void bfs()
{
    while(!Q.empty())
    {
        PII p = Q.front(); Q.pop_front();

        ECH(G[p.BB])
        if(f[p.AA][*it] == -1)
        {
            Q.PB(MP(p.AA, *it));
            f[p.AA][*it] = f[*it][p.AA] = f[p.AA][p.BB] + 1;
        }

        ECH(G[p.AA])
        if(f[p.BB][*it] == -1)
        {
            Q.PB(MP(p.BB, *it));
            f[p.BB][*it] = f[*it][p.BB] = f[p.AA][p.BB] + 1;
        }
    }
}

int main()
{
    while(~scanf("%d", &n))
    {
        if(!n) break;
        H.CLR;
        FOR(i, n) { scanf("%s", buf); H.PB(string(buf)); }
        sort(H.OP, H.ED);
        scanf("%d", &m);

        memset(f, -1, sizeof f);
        FOR(i, n) f[i][i] = 0;
        Q.CLR;
        FOR(i, n) G[i].CLR;
        FOR(i, m)
        {
            scanf("%s", buf);
            int x = lower_bound(H.OP, H.ED, string(buf)) - H.OP;
            scanf("%s", buf);
            int y = lower_bound(H.OP, H.ED, string(buf)) - H.OP;
            Q.PB(MP(x, y));
            f[x][y] = f[y][x] = 1;
            G[x].PB(y); G[y].PB(x);
        }
        bfs();
        int ans = -1;
        bool flg = false;

        FOR(i, n) if(!flg) FOR(j, n)
        {
            if(f[i][j] == -1) { flg = true; break; }
            ans = max(ans, f[i][j]);
        }
        if(flg) printf("-1\n"); else printf("%d\n", ans);
    }
}