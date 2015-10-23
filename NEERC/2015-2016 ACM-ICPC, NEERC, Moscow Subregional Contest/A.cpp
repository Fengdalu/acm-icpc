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

vector<LL>s;

int main()
{
    ios::sync_with_stdio(false);
    s.CLR;
    LL n; cin >> n; n--;
    for(LL i = 1; i * i <= n; i++)
    if(n % i == 0) { s.PB(i); s.PB(n / i); }
    sort(s.OP, s.ED);
    s.resize(unique(s.OP, s.ED) - s.OP);
    ECH(s) cout << (*it) << " ";
    return 0;
}
