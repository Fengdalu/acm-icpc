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


const int MAXN = 10000 + 5;

int a[100005];
int main()
{
    int _T;
    scanf("%d", &_T);
    int x,y;
    int n,A,B,L;
    for(int CAS = 1; CAS <= _T; CAS ++)
    {
        scanf("%d%d%d%d",&n,&A,&B,&L);
        clr(a, 0);
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d",&x,&y);
            for(int j = x; j < y; j++)
                a[j] = 1;
        }
        int ans = 0;
        int now = 0;
        for(int i = 0; i < L; i ++)
        {
            if(a[i]) now -= A;
            else now += B;
            ans = min(ans, now);
            //cout << i << " " << now << endl;
        }
        printf("Case #%d: %d\n", CAS, -ans);
    }
    return 0;
}