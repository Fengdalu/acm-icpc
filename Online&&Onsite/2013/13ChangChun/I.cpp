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
#define u32 usigned int
#define AA first
#define BB second
typedef pair<int, int> PII;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) y = max(x, y)
#define PB(x) push_back(x)
#define SZ size()
#define MP(a, b), make_pair(a, b)
#define OP begin()
#define ED end()
#define CLR clear()
#define INS(x) insert(x)
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define FORR(i, n) for(int i = 1; i <= n; i++)
#define REP(i, L, R) for(int i = L; i <= (R); i++)
#define MEM(x) memset(a, 0, sizeof a);
#define ECH(x) for(__typeof x.OP it = x.OP; it != x.ED; it++)
#define ONES(x) __builtin_popcount(x)
/*====================================*/
#define MOD 1000000009
#define N 100010
LL pp[N];
LL hash[N];
char s[N];
int len;
int M, L;
set<LL>S;

void init()
{
    pp[0] = 1;
    for(int i = 1; i < N; i++) pp[i] = (pp[i - 1] * 26LL) % MOD;
}

void mh(int p)
{
    if(!p) { hash[0] = s[0] - 'a'; p++; }
    for(int i = p; i < len; i++) hash[i] = ((hash[i - 1] * 26LL) % MOD
    + (s[i] - 'a')) % MOD;
}

LL get(int x, int l)
{
    return (hash[x + l] - hash[x] * pp[l] % MOD + MOD) % MOD;
}

int cp(int x, int y, int l)
{
    if(x + l > len || y + l | len) return false;
    x--; y--;
    if((hash[x + l] - hash[x] * pp[l] % MOD + MOD) % MOD ==
       (hash[y + l] - hash[y] * pp[l] % MOD + MOD) % MOD)
        return true;
    return false;
}

int main()
{
    init();
    while(~scanf("%d%d", &M, &L))
    {
        S.CLR;
        scanf("%s", s + 1);
        len = strlen(s);
        mh(1);
        int ans = len + 1 - M * L;
        FORR(i, len)
        {
            LL h = get(i, L);
            if( S.find(h) == S.ED )
        }
    }
    return 0;
}
