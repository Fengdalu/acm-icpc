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
const int N = 100005;
const int BIT_N = N << 1;
inline int low_bit(int x)
{
    return x & -x;
}
queue<LL> Q;
struct BIT
{
    int a[BIT_N];
    void init()
    {
         clr(a, 0);
    }
    void del(LL i)
    {
        //printf("del %d\n", i);
        while(i < BIT_N)
        {
            a[i] = 0;
            i += low_bit(i);
        }
    }
    void add(LL i, int x)
    {
        //printf("add %d %d\n", i,x);
        if(i > 100001) return;
        Q.push(i);
        //printf("add %d %d \n",i - 100001,x);
        while(i < BIT_N)
        {
            if(x > a[i]) a[i] = x;
            i += low_bit(i);
        }
    }
    int qry(LL i)
    {
        if(i <= 0) return 0;
        //printf("qry %d\n", i - 100001);
        int ret = 0;
        while(i > 0)
        {
            if(a[i] > ret) ret = a[i];
            i -= low_bit(i);
        }
        return ret;
    }
}bit;
pii b[N];
piii v[N];
piii a[N];
pli s[BIT_N];
int mp[BIT_N];
void run()
{
    int m,n,c;
    scanf("%d%d%d", &m, &n, &c);
    for(int i = 0; i < n; i++)
        scanf("%d%d%d",&a[i].AA.AA, &a[i].AA.BB, &a[i].BB);
    //for(int i = 0; i < n; i++) a[i].AA.BB = m + 1 - a[i].AA.BB;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
         v[i].AA.AA = a[i].AA.BB + a[i].AA.AA;
         v[i].AA.BB = a[i].AA.AA;
         v[i].BB = i;
    }
    sort(v, v + n);
    //FOR(i,n) printf("a : %d %d\n", a[i].AA.AA, a[i].AA.BB);
    FOR(i,n)
    {
        int x = v[i].BB;
        //printf("sort : %d %d %d\n", a[x].AA.AA, a[x].AA.BB,v[i].AA.AA);
    }
    bit.init();
    int x;
    int p;
    LL tmp;
    for(int i = 0; i < n; i++)
    {
        int now = v[i].BB;
        if(i == 0 || v[i].AA.AA != v[i - 1].AA.AA)
        {
            //puts("clr");
            while(!Q.empty())
            {
                bit.del(Q.front());
                Q.pop();
            }
            ans = max(ans, 1);
            x = a[now].AA.AA;
            p = a[now].BB;
            tmp = 1ll * p * p + x;
            //printf("\t calc %d %d %d  xy %d %d\n", x, p, tmp, a[now].AA.AA, a[now].AA.BB);
            {
                bit.add(tmp, 1);
            }
        }
        else
        {
            int ret = 1;
            x = a[now].AA.AA;
            p = a[now].BB;
            tmp = -1ll * p * p + x - c + 1;
            //printf("\t calc %d %d %d  xy %d %d\n", x, p, tmp, a[now].AA.AA, a[now].AA.BB);
            {
                 ret += bit.qry(tmp);
            }
            if(ret > ans) ans = ret;
            tmp = 1ll * p * p + x;
            {
                bit.add(tmp, ret);
            }
        }
    }
    //dbg(ans);
    for(int i = 0; i < n; i++) a[i].AA.BB = m + 1 - a[i].AA.BB;
    for(int i = 0; i < n; i++)
    {
         v[i].AA.AA = a[i].AA.BB + a[i].AA.AA;
         v[i].AA.BB = a[i].AA.AA;
         v[i].BB = i;
    }
    sort(v, v + n);
    /*FOR(i,n) printf("a : %d %d\n", a[i].AA.AA, a[i].AA.BB);
    FOR(i,n)
    {
        int x = v[i].BB;
        printf("sort : %d %d %d\n", a[x].AA.AA, a[x].AA.BB,v[i].AA.AA);
    }*/
    bit.init();
    for(int i = 0; i < n; i++)
    {
        int now = v[i].BB;
        if(i == 0 || v[i].AA.AA != v[i - 1].AA.AA)
        {
            //puts("clr");
            while(!Q.empty())
            {
                bit.del(Q.front());
                Q.pop();
            }
            ans = max(ans, 1);
            x = a[now].AA.AA;
            p = a[now].BB;
            tmp = 1ll * p * p + x;
            //printf("\t calc %d %d %d  xy %d %d\n", x, p, tmp, a[now].AA.AA, a[now].AA.BB);
            {
                bit.add(tmp, 1);
            }
        }
        else
        {
            int ret = 1;
            x = a[now].AA.AA;
            p = a[now].BB;
            tmp = -1ll * p * p + x - c + 1;
            //printf("\t calc %d %d %d  xy %d %d\n", x, p, tmp, a[now].AA.AA, a[now].AA.BB);
            {
                 ret += bit.qry(tmp);
            }
            if(ret > ans) ans = ret;
            tmp = 1ll * p * p + x;
            {
                bit.add(tmp, ret);
            }
        }
    }


    printf("%d\n", ans);
}
int main()
{
    freopen("bishops.in","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--) run();
    return 0;
}
close
