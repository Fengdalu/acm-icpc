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
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;


const int MAXN = 1000 + 5;
#define ONLINE_JUDGE
int a[MAXN];
int b[MAXN];
int add[MAXN];
int check(int i, int t)
{
    if(t == 0)
    {
        if(add[i]) return b[i];
        else return a[i];
    }
    int l = b[i] - a[i];
    int times = add[i] + t / l;
    int leave = t % l;
    if(times & 1) return b[i] - leave;
    return a[i] + leave;
}
int n,m;
void getans()
{
    int x,y,t;
    scanf("%d%d%d",&x,&y,&t);
    int ans = 0;
    int chk = 0;
    for(int i = 0; i < n; i++)
    {
        chk = check(i,t);
        if(chk >= x && chk <= y) ans++;
    }
    printf("%d\n",ans);
}
int main()
{
    #ifdef ONLINE_JUDGE
        freopen("knockout.in","r",stdin);
        freopen("knockout.out","w",stdout);
    #endif // ONLINE_JUDGE
//    a[0] = 1;
//    b[0] = 2;
//    add[0] = 1;
//    for(int i = 0; i < 30; i++)
//        cout << i << " " << check(0,i) << endl;
    scanf("%d%d",&n,&m);
    int x,y;
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d",&x,&y);
        if(y > x)
        {
            a[i] = x;
            b[i] = y;
            add[i] = 0;
        }
        else
        {
            a[i] = y;
            b[i] = x;
            add[i] = 1;
        }
    }
    for(int i = 0; i < m; i++)
        getans();
    #ifdef ONLINE_JUDGE
        fclose(stdout);
    #endif // ONLINE_JUDGE
}