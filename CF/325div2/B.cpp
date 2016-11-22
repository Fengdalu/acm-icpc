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


int f[100], g[100];
int c[100];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 2; i <= n; i++) cin >> f[i];
    for(int j = 1; j <= n - 1; j++) cin >> g[j];
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 2; i <= n; i++) f[i] += f[i - 1];
    for(int i = n - 1; i >= 1; i--) g[i] += g[i + 1];


    int p = 1, q = -1;
    for(int i = 1; i <= n; i++) if(f[i] + g[i] + c[i] < f[p] + g[p] + c[p]) p = i;

    for(int i = 1; i <= n; i++) if(i != p) if(q == -1 || f[i] + g[i] + c[i] < f[q] + g[q] + c[q]) q = i;

    cout << f[p] + g[p] + c[p] + f[q] + g[q] + c[q] << endl;
    return 0;
}
