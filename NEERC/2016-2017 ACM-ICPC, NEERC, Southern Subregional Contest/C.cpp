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
#define all(x) x.begin(),x.end()
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

LL gcd(LL a, LL b){if(b == 0) return a;return gcd(b,a%b);}
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

const int N = 5005;
struct nodee
{
    int v;
    int nxt;
}e[N << 1];
int h[N];
int n,m;
int tot;
void init(){tot = 0; clr(h, -1);}
void add(int x,int y)
{
    e[tot].v = y;
    e[tot].nxt = h[x];
    h[x] = tot;
    tot++;
}
int ns;
int nq;
piii v[N];
int cs[N];
queue<pii> q;
int vis[N];
int main()
{
    init();
    scanf("%d%d",&n,&m);
    for(int i = 0,x,y; i < m; i++)
    {
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    clr(cs, 0);
    scanf("%d",&ns);
    for(int i = 0,c,k,p; i < ns; i++)
    {
        scanf("%d%d%d",&c,&k,&p);
        v[i] = MP3(p,k,c);
        cs[c] += k;
    }
    sort(v, v + ns);
    scanf("%d",&nq);
    for(int flag,left,t,i = 0,g,a,l,buy,r; i < nq; i++)
    {
        scanf("%d%d%d",&g,&buy,&a);
        flag = -1;
        left = buy;
        l = 0;
        r = n;
        int FLAG = 0;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            flag = 0;
            FORR(i,n) vis[i] = 0;
            while(!q.empty()) q.pop();
            vis[g] = 1;
            q.push(MP(g,0));
            while(!q.empty())
            {
                pii t = q.front();
                q.pop();
                int it = h[t.AA];
                int v;
                if(t.BB < mid) while(~it)
                {
                    v = e[it].v;
                    if(!vis[v])
                    {
                        vis[v] = 1;
                        q.push(MP(v, t.BB + 1));
                    }
                    it = e[it].nxt;
                }
            }
            LL sum = 0;
            left = buy;
            FOR(i,ns) if(vis[v[i].BB])
            {
                t = min(left, v[i].AA.BB);
                sum += 1ll* v[i].AA.AA * t;
                left -= t;
            }
            if(sum <= a && left == 0) flag = 1;
            if(flag) FLAG = 1;
            if(flag) r = mid;
            else l = mid + 1;
        }
        if(FLAG)
        printf("%d\n",l);
        else puts("-1");
    }
    return 0;
}
