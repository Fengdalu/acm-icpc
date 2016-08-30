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
typedef pair<int, int> PII;
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
#define REP_D(i,x,y) for(int i = (int)(x), __END__ = (int)(y); i >= __END__; i--)

const int MAXN = 100000 + 5;

LL gcd(LL a, LL b)
{
    if(b == 0) return a;
    return gcd(b,a%b);
}
inline LL readLL()
{
    char ch;bool flag = false;LL a = 0;
    while(!((((ch = getchar()) >= '0') && (ch <= '9')) || (ch == '-')));
    if(ch != '-'){a *= 10;a += ch - '0';}else{flag = true;}
    while(((ch = getchar()) >= '0') && (ch <= '9')){a *= 10;a += ch - '0';}
    if(flag)a = -a;return a;
}
inline int read()
{
    char ch;bool flag = false;int a = 0;
    while(!((((ch = getchar()) >= '0') && (ch <= '9')) || (ch == '-')));
    if(ch != '-'){a *= 10;a += ch - '0';}else{flag = true;}
    while(((ch = getchar()) >= '0') && (ch <= '9')){a *= 10;a += ch - '0';}
    if(flag)a = -a;return a;
}
const int MN = 30;
char str[MN][MN];
int id[MN][MN];
int dis[MN][MN];
int c[MN];
bool vis[MN][MN];
int tot;
inline int getst(int mask, int i)
{
    return (mask << 5) | i;
}
const int VX[4] = {0, 1, 0, -1};
const int VY[4] = {1, 0, -1, 0};
const int HASH = 10007;
const int STATE = (1 << 16) * 16;
struct HASHMAP
{
    int h[HASH];
    int nxt[STATE];
    int st[STATE];
    pii f[STATE];
    int size;
    void init()
    {
        size = 0;
        clr(h, -1);
    }
    void push(int mask, pii tmp)
    {
        int head = mask % HASH;
        int i = h[head];
        while(~i)
        {
            if(mask == st[i])
            {
                f[i] = min(f[i], tmp);
                return;
            }
            i = nxt[i];
        }
        st[size] = mask;
        f[size] = tmp;
        nxt[size] = h[head];
        h[head] = size++;
    }
}hm[2];
void run(int n,int m)
{
    tot = 0;
    FOR(i,n) scanf("%s", str[i]);
    memset(id, -1, sizeof id);
    FOR(i,n) FOR(j,m)
    {
        if(str[i][j] == 'F' || str[i][j] == 'G' || str[i][j] == 'Y') {
            id[i][j] = tot;
            c[tot] = str[i][j];
            tot++;
        }
    }
    FOR(i, n) FOR(j, m) if(id[i][j] != -1) {
        int base = id[i][j];
        queue<pair<PII, int> >q;
        memset(vis, 0, sizeof vis);
        vis[i][j] = true;
        q.push(MP(MP(i, j), 0));
        while(q.size()) {
            auto t = q.front(); q.pop();
            int x = t.AA.AA, y = t.AA.BB, d = t.BB;
            if(id[x][y] != -1) dis[base][id[x][y]] = d;
            if(str[x][y] == 'D') continue;
            for(int i = 0; i < 4; i++) {
                int tx = x + VX[i], ty = y + VY[i];
                if(tx < 0 || tx > n || ty < 0 || ty > m) continue;
                if(!vis[tx][ty]) {
                    vis[tx][ty] = true;
                    q.push(MP(MP(tx, ty), d + 1));
                }
            }
        }
    }
    int cur = 0;
    hm[cur].init();
    pii tmp;
    int st = 0;
    FOR(i,tot) if(c[i] == 'F') st = i;
    FOR(i,tot)
    {
        int mask = 1 << st;
        if(c[i] == 'G')
        {
            tmp.AA = dis[st][i];
            tmp.BB = 0;
        }
        if(c[i] == 'F') continue;
        if(c[i] == 'Y')
        {
            tmp.AA = dis[st][i];
            tmp.BB = dis[st][i];
        }
        hm[cur].push(getst(mask | (1 << i), i), tmp);
    }
    //FOR(i,tot) FOR(j,tot) cout << i << " " << j << " " << dis[i][j] << endl;
    int ans = -1;
    int ed = 0;
    FOR(i,tot) if(c[i] == 'Y') ed |= 1 << i;
    if(ed == 0) ans = 0;
    FOR(l,tot - 1)
    {
        hm[cur ^ 1].init();
        FOR(it, hm[cur].size)
        {
            int mask = hm[cur].st[it];
            int i = mask & 31;
            mask >>= 5;
            pii d = hm[cur].f[it];
            //printf("%d %d %d %d %d\n", l, mask,i, d.AA, d.BB);
            FOR(j, tot) if(!((mask >> j) & 1)) if(~dis[i][j])
            {
                tmp = d;
                if(c[j] == 'F') continue;
                if(c[j] == 'G')
                {
                    tmp.BB += dis[i][j];
                    tmp.AA = max(tmp.AA, tmp.BB);
                    tmp.BB = 0;
                }
                if(c[j] == 'Y')
                {
                    tmp.BB += dis[i][j];
                    tmp.AA = max(tmp.AA, tmp.BB);
                }
                hm[cur ^ 1].push(getst(mask | (1 << j),j),tmp);
            }
        }
        cur ^= 1;
        FOR(it, hm[cur].size)
        {
            //dbg((hm[cur].st[it] >> 5));
            if(((hm[cur].st[it] >> 5) & ed) == ed)
            {
                if(ans == -1) ans = hm[cur].f[it].AA;
                else ans = min(ans, hm[cur].f[it].AA);
            }
        }
    }
    //dbg(ed);
    cout << ans << endl;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        if(n == 0 && m == 0) return 0;
        run(n,m);
    }
}
