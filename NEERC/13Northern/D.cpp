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
//#pragma comment(linker, "/STACK:102400000,102400000")
#define clr(a,b) memset(a,b,sizeof(a))
#define cmin(x,y) x = min(x,y)
#define cmax(x,y) x = max(x,y)
#define MP make_pair
#define AA first
#define BB second
#define PB push_back
#define SZ size()
#define dbg(x) cerr <<#x<<" = " << x << endl
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;
typedef pair<int, int> pii;
#define FOR(i,x) for(int i = 0; i < (int) (x) ; i++)
#define FORR(i,x) for(int i = 1; i <= (int) (x) ; i++)

const int MAXN = 10000 + 5;
//GYM
#define ONLINE_JUDGE
priority_queue<pii> Q1;
char s[MAXN];
vector<pii> V[MAXN];
int p[MAXN];
int vis[MAXN];
inline void ADD(int x,int y,int z)
{
    V[y].PB(MP(x,z));
}
int main()
{
    #ifdef ONLINE_JUDGE
        freopen("dwarf.in","r",stdin);
        freopen("dwarf.out","w",stdout);
    #endif // ONLINE_JUDGE
    int n,m;
    clr(vis,0);
    while(!Q1.empty()) Q1.pop();
    scanf("%d%d",&n,&m);
    FORR(i,n)scanf("%d",&p[i]);
    FORR(i,n) Q1.push(MP(-p[i], i));
    int tx,ty,tz;
    FOR(i,m)
    {
        scanf("%d%d%d",&tx,&ty,&tz);
        ADD(tx,ty,tz);
        ADD(tx,tz,ty);
    }
    int now;
    int sz;
    while(!Q1.empty())
    {
        now = Q1.top().BB;
        Q1.pop();
        if(vis[now]) continue;
//        cout << now << endl;
        sz = V[now].SZ;
        FOR(i,sz)
        {
            if(p[V[now][i].AA] > p[V[now][i].BB] + p[now])
            {
                p[V[now][i].AA] = p[V[now][i].BB] + p[now];
                Q1.push(MP(-p[V[now][i].AA],V[now][i].AA));
            }
        }
        vis[now] = 1;
    }
    cout << p[1] << endl;
}