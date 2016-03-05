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


const int MAXN = 1048576 + 5;
LL f[MAXN];
LL g[MAXN];
int main()
{
    int _T;
    scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS ++)
    {
        LL ans = 0;
        int n,m;
        int x;
        scanf("%d%d",&n,&m);
        clr(f,0);
        clr(g,0);
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&x);
            for(int i = 0; i <= 1048576; i++)
                if(f[i]) g[i ^ x] += f[i];
            g[x] ++;
            for(int i = 0; i <= 1048576; i++)
                f[i] = g[i];
        }
        for(int i = m; i <= 1048576; i++)
            ans = ans + f[i];
        if(m == 0) ans++;
        printf("Case #%d: ",CAS);
        printf("%I64d\n",ans);
    }
    return 0;
}