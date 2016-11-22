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

struct C{LL id, v, d, p; C(LL id, LL v, LL d, LL p): id(id), v(v), d(d), p(p){}; C(){} };
vector<C>Q, F;
vector<C>::iterator t;

int n;
int main()
{
    ios::sync_with_stdio(false);
    Q.CLR;
    cin >> n;
    FOR(i, n) { LL v, d, p; cin >> v >> d >> p; Q.PB(C(i + 1, v, d, p)); }
    F.CLR;
    ECH(Q)
    if(it->p >= 0)
    {
        F.PB(*it);
        LL tot = it->v, add = 0;
        t = it + 1;
        while(t < Q.ED)
        {
            if(t->p >= 0 && t->p < tot + add) { t->p = -1; add += t->d; tot--; }
            else if(t->p >= 0){ t->p -= add + tot; tot--; }
            t++;
            tot = max(0LL, tot);
        }
    }
    cout << F.SZ << endl;
    ECH(F) cout << it->id << " "; cout << endl;
    return 0;
}
