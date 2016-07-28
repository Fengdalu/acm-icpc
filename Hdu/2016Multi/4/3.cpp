#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
typedef pair<pii,int> piii;
typedef pair<LL,LL> pll;
typedef pair<LL,int> pli;
typedef pair<int,LL> pil;

//#pragma comment(linker, "/STACK:102400000,102400000")

#define MP3(x,y,z) make_pair(make_pair(x,y),z)
#define MP make_pair
#define AA first
#define XX first.first
#define YY first.second
#define BB second
#define PB push_back
#define SZ size()
#define dbg(x) cerr <<#x<<" = " << x << endl

const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;

#define clr(a,b) memset(a,b,sizeof(a))
#define cmin(x,y) x = min(x,y)
#define cmax(x,y) x = max(x,y)
#define ccmin(x,y) {if(~x) x = std::min(x,y);else x = y;}
#define ccmax(x,y) {if(~x) x = std::max(x,y);else x = y;}
#define FOR(i,x) for(int i = 0, __END__ = (int)(x); i < __END__ ; i++)
#define FORR(i,x) for(int i = 1, __END__ = (int)(x); i <= __END__ ; i++)
#define REP(i,x,y) for(int i = (int)(x), __END__ = (int)(y); i <= __END__; i++)

const int MAXN = 100000 + 5;

int st[401];
int a[20][20];
vector<int> e[20];
int xx[1 << 20 | 3];
int mask[1 << 20 | 3];
int bb[22];
void init()
{
    FOR(i,22) bb[i] = 1 << i;
    FORR(i, (1 << 20) - 1)
    {
        for(int j = 20; j >= 0; j--)
            if(i % bb[j] == 0)
            {
                xx[i] = bb[j];
                break;
            }
    }
    mask[1] = 1;
    REP(i,2, (1 << 20) - 1)
    {
        mask[i] = mask[i - 1] ^ xx[i];
    }
}
int st_p[30];
int c[404];
int d[404];
int f[400];
int main()
{
    init();
    int T;
    scanf("%d",&T);
    FORR(cas, T)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        clr(a, -1);
        int x,y;
        FOR(i,400) st[i] = 1;
        FOR(i,n) e[i].clear();
        FOR(i,m)
        {
            scanf("%d%d",&x,&y);
            if(x > y) swap(x,y);
            a[x][y] = 1;
            e[x].PB(i);
            e[y].PB(i);
            st[i] = 1;
            c[i] = x;
            d[i] = y;
        }
        FOR(i,n) st_p[i] = 1;
        int tot = 0;
        int ans = 30;
        int lmask = 0;
        REP(id,1, (1 << (n - 1)) - 1)
        {
            x = __builtin_ctz(mask[id] ^ lmask);
            y = 1;
            //printf("now = %d %d %d %d\n",lmask, mask[id], x, y);
            FOR(it, e[x].size())
            {
                if(st[e[x][it]] == 0) {st[e[x][it]] = y;tot--;}
                else {st[e[x][it]] = 0; tot++;}
            }
            //printf("tot = %d\n", tot);
            if(tot < ans) ans = tot;
            lmask = mask[id];
        }
        FOR(i,400) st[i] = 1;
        tot = 0;
        clr(f,0);
        REP(id,1, (1 << (n - 1)) - 1)
        {
            x = __builtin_ctz(mask[id] ^ lmask);
            y = 1;
            //printf("now = %d %d %d %d\n",lmask, mask[id], x, y);
            FOR(it, e[x].size())
            {
                if(st[e[x][it]] == 0) {st[e[x][it]] = y;tot--;}
                else {st[e[x][it]] = 0; tot++;}
            }
            //printf("tot = %d\n", tot);
            if(tot == ans)
            {
                FOR(i,m)
                    if(!st[i])
                    {
                        f[i]++;
                    }
            }
            lmask = mask[id];
        }
        //printf("%d\n",ans);
        printf("Case #%d:",cas);
        FOR(i,m) printf(" %d", f[i]);
        puts("");
    }
    return 0;
}
