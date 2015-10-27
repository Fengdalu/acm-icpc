#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <fstream>
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
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define FORR(i, n) for(int i = 1; i <= (n); i++)
#define REP(i, L, R) for(int i = (L); i <= (R); i++)
#define MEM(a) memset(a, 0, sizeof a)
#define ECH(x) for(__typeof x.OP it = x.OP; it != x.ED; it++)
#define ONES(x) __builtin_popcount(x)
/*===========================================================*/
#define N 100100

int n;
int a[N];
vector<int> G[N];
bool vis[N];
LL lcm[N], lcm1[N];

LL gcd(LL a, LL b)
{
    if(!b) return a;
    return gcd(b, a % b);
}

LL Lcm(LL a, LL b)
{
    return a / gcd(a, b) * b;
}

void dfs1(int x, int fa)
{
    if(a[x] != 0) { lcm[x] = 1; return; }
    ECH(G[x]) if(*it != fa) dfs1(*it, x);
    LL p = 1;
    LL cnt = 0;
    ECH(G[x])
    if(*it != x)
    {
        p = Lcm(p, lcm[*it]);
        cnt++;
    }
    lcm[x] = Lcm(cnt, p);
}

void dfs2(int x, int fa)
{
    if(a[x] != 0) { lcm[x] = 1; return; }
    ECH(G[x]) if(*it != fa) dfs2(*it, x);
    lcm1[x] = 1;
    ECH(G[x]) if(*it != fa) lcm1[x] = Lcm(lcm1[x], lcm[*it]);
}


int main()
{
    ios::sync_with_stdio(false);
    LL n;
    cin >> n;
    LL tot = 0LL;
    FORR(i, n) { LL x; cin >> x; tot += x; }
    cout << (tot + n - 2) / (n - 1) << endl;
    return 0;
}
