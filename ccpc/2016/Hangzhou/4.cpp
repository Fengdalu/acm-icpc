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

LL ten[10][10];
LL mi[10][10];
void init()
{
    REP(i,0,9)
    {
        ten[i][0] = i;
        REP(j,1,9) ten[i][j] = ten[i][j - 1] * 10ll;
    }
    REP(i,0,9)
    {
        mi[i][0] = 1;
        REP(j,1,9) mi[i][j] = mi[i][j - 1] * i;
    }
}
int tot[2];
LL a[10][10];
LL b[2][100005];
void dfs(int now, LL val, int x)
{
    if((x == 0 && now == 5) || (x == 1 && now == 10))
    {
        b[x][tot[x]++] = val;
        return;
    }
    FOR(j,10)
        dfs(now + 1, val + a[now][j], x);
}
void run(int cas)
{
    int x;
    int k;
    scanf("%d%d",&x,&k);
    FOR(i,10)
    {
        FOR(j,10)
        {
            a[i][j] = mi[j][k] - ten[j][i];
        }
    }
    tot[1] = tot[0] = 0;
    dfs(0, 0, 0);
    dfs(5, 0, 1);
    map<LL,int> mp;
    LL ans = 0;
    FOR(i,tot[1]) b[1][i] = x - b[1][i];
    FOR(i,2) sort(b[i], b[i] + tot[i]);
    vector<pii> v;
    v.clear();
    for(int i = 0; i < tot[1]; i++)
    {
        if(v.empty()) v.push_back(MP(b[1][i],1));
        else if(v.back().AA == b[1][i]) v.back().BB++;
        else v.push_back(MP(b[1][i],1));
    }
    int j = 0;
    int totj = v.size();
    FOR(i,tot[0])
    {
        while(j < totj && b[0][i] > v[j].AA) j++;
        if(b[0][i] == v[j].AA) ans += v[j].BB;
    }
    /*
    int j = 0;
    int cnt = 0;
    FOR(i,tot[0])
    {
        while(j < tot[1] && b[0][i] > b[1][j]) j++;
                if(i == 0 || b[1][j] != b[1][j - 1])
        {
            cnt = 1;
            while(j + 1 < tot[1] && b[1][j] == b[1][j + 1]) cnt++,j++;
        }
        if(b[0][i] == b[1][j]) ans += cnt;
    }*/
    //for(int i = 0; i < tot[1]; i++) mp[b[1][i]]++;
    //for(int i = 0; i < tot[0]; i++) ans += mp[x - b[0][i]];
    if(x == 0) ans--;
    printf("Case #%d: %lld\n", cas, ans);
}
int main()
{
    init();
    int t;
    scanf("%d",&t);
    FORR(i,t) run(i);
    return 0;
}
