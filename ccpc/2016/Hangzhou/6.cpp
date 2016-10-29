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
char str[55];
int n;
LL a[30][30];
int b[5];
LL ans = 0;
int flag;
LL add[55][55];
void dfs(int x)
{
    if(x == 4)
    {
        //for(int i = 0; i < 4; i++) printf("%d ", b[i]); puts("");
        LL now = //a[0][b[0]] + a[b[0] + 1][b[1]]
            add[0][b[1]]
            - a[b[1] + 1][b[2]] * a[b[2] + 1][b[3]] / a[b[3] + 1][n - 1];
        /*printf("\t%lld", a[0][b[0]]);
        printf("\t%lld", a[b[0] + 1][b[1]]);
        printf("\t%lld", a[b[1] + 1][b[2]]);
        printf("\t%lld", a[b[2] + 1][b[3]]);
        printf("\t%lld", a[b[3] + 1][n - 1]);

        printf(" = %lld\n", now);*/
        if(flag)
        {
            ans = max(ans, now);
        }
        else
        {
            flag = 1;
            ans = now;
        }
        return;
    }
    int st = 0;
    if(x) st = b[x - 1] + 1;
    for(int i = st; i < n - 1; i++)
    {
        b[x] = i;
        dfs(x + 1);
    }
}
void run(int cas)
{
    scanf("%s",str);
    n = strlen(str);
    FOR(i,n)
    {
        a[i][i] = str[i] - '0';
        for(int j = i + 1; j < n; j++)
            a[i][j] = a[i][j - 1] * 10 - '0' + str[j];
    }
    FOR(i,n) for(int j = i + 1; j < n; j++)
    {
        add[i][j] = a[i][i] + a[i + 1][j];
        for(int k = i; k < j; k++)
            add[i][j] = max(add[i][j], a[i][k] + a[k + 1][j]);
    }
    //printf("%lld\n", a[0][3]);
    flag = 0;
    b[0] = 0;
    dfs(1);
    printf("Case #%d: %lld\n", cas, ans);
}
int main()
{
    int t;
    scanf("%d",&t);
    FORR(i, t) run(i);
    return 0;
}
