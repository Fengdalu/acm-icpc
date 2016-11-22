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
#define N 200010
#define M 400010
int ind[N], in[N];
int t[M], nt[M];
int cnt;
priority_queue<int>q;
vector<int>ans;

void add(int x, int y)
{
    t[cnt] = y;
    nt[cnt] = ind[x];
    ind[x] = cnt++;
    in[y]++;
}

int main()
{
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    memset(ind, -1, sizeof ind);
    memset(in, 0, sizeof in);
    cnt = 0;

    FOR(i, m)
    {
        int x, y; cin >> x >> y;
        add(y, x);
    }
    ans.CLR;
    FORR(i, n) if(in[i] == 0) q.push(i);
    while(q.SZ)
    {
        int x = q.top(); q.pop(); ans.PB(x);
        for(int k = ind[x]; k != -1; k = nt[k])
        {
            in[t[k]]--;
            if(in[t[k]] == 0) q.push(t[k]);
        }
    }
    reverse(ans.OP, ans.ED);
    ECH(ans) cout << (*it) << " ";
    return 0;
}
