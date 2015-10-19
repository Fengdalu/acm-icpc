#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define LL long long
#define u32  unsigned int
#define AA first
#define BB second
typedef pair<int, int> PII;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define PB(x) push_back(x)
#define SZ size()
#define MP(a, b) make_pair(a, b)
#define OP begin()
#define ED end()
#define CLR clear()
#define INS(x) insert(x)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORR(i, n) for(int i = 1; i <= n; i++)
#define MEM(a) memset(a, 0, sizeof a)
#define ECH(x) for(__typeof x.OP it = x.OP; it != x.ED; it++)
#define ONES(x) __builtin_popcount(x)
/*===========================================================*/

int a[16];
int d[16];
int c[16];
int b[16];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    FOR(i,n) scanf("%d",&a[i]);
    FOR(i,m) scanf("%d",&b[i]);
    int sum1 = 0;
    int sum0 = 0;
    FOR(i,n) if(a[i] == 1) sum1++;else sum0++;
//    cout << "sum" << sum0 << sum1 << endl;
    int sumj = 0;
    int sumo = 0;
    FOR(i,m) if(i & 1) sumo += b[i]; else sumj += b[i];
//    cout << "sum" << sumj << sumo << endl;
    int ans = 99999999;
    // solve first 0
    if(sumj == sum0)
    {
        int now = 0;
        int add = 0;
        int tot = 0;
        int i = 0;
        while(tot < n)
        {
            FOR(j,b[i])
                c[tot++] = add;
            add ^= 1;
            i++;
        }
        int j;
        FOR(i,n) d[i] = a[i];
//        FOR(i,n) cout << c[i] << " ";
//        cout << endl;
        FOR(i,n)
        {
            if(d[i] == c[i]) continue;
            j = i;
            while(j < n)
            {
                if(d[j] != d[i])
                {
                    swap(d[i],d[j]);
                    now += j - i;
                    break;
                }
                j++;
            }
        }
        ans = min(ans, now);
//        cout <<"1:" << now << endl;
    }
    // solve first 1
    if(sumj == sum1)
    {
        int now = 0;
        int add = 1;
        int tot = 0;
        int i = 0;
        while(tot < n)
        {
            FOR(j,b[i])
                c[tot++] = add;
            add ^= 1;
            i++;
        }
        int j;
        FOR(i,n) d[i] = a[i];
//        FOR(i,n) cout << c[i] << " ";
//        cout << endl;
        FOR(i,n)
        {
            if(d[i] == c[i]) continue;
            j = i + 1;
            while(j < n)
            {
                if(d[j] != d[i])
                {
                    swap(d[i],d[j]);
                    now += j - i;
                    break;
                }
                j++;
            }
        }
        ans = min(ans, now);
//        cout << now << endl;
    }
    printf("%d\n",ans);
}
