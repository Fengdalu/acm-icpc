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


const int MAXN = 1000000 + 5;
const int N = 500000;
const LL inv2 = MOD / 2 + 1;
int a[MAXN];
LL ans[MAXN];
int b[MAXN];
LL calc(LL l, LL r)
{
    if(l > r) return 0;
    LL n = (r - l + 1);
    return (l + r) % MOD * inv2 % MOD * n % MOD;
}
void init()
{
    clr(a,0);
    a[1] = 1;
    a[2] = 2;
    a[3] = 2;
    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 1;
    LL sum = 3;
    int nowi = 3;
    int now = 4;
    LL l;
    LL r;
    while(sum <= 1000000000LL)
    {
        for(int i = 0; i < a[nowi]; i++)
        {
            a[now++] = nowi;
        }
        sum += a[nowi] * nowi;
        nowi++;
        //printf("%d\n",sum);
    }
    a[2] = 2;
//    printf("now = %d\n",nowi);
    b[0] = 0;
    for(int i = 1;i < N; i++)
        b[i] = b[i - 1] + a[i];
    ans[0] = 0;
    ans[1] = 1;
    for(int i = 2; i < N; i++)
        ans[i] = (ans[i - 1] + calc(b[i - 1] + 1,b[i]) * i % MOD) % MOD;
}
int geti(int n)
{
    //if(n >= 999613347) return 438639;
    int ret = lower_bound(b,b + 438830,n) - b;
    if(b[ret] == n) return ret;
    else return ret - 1;
}
int main()
{
    init();
//    for(int i = 0; i < N; i++)
//        if(a[i] && i > 400000)
//        printf("%d : %d %d %I64d\n",i,a[i],b[i],ans[i]);
    int _T;
    scanf("%d",&_T);
    for(int CAS = 0; CAS < _T; CAS++)
    {
        int now = 0;
        int i = 1;
        int n;
        scanf("%d",&n);
        i = geti(n);
        //cout << "i = " << i << endl;
        LL tmp = 0;
        tmp = ans[i];
        //cout << "tmp = " << tmp << endl;
        tmp = (tmp + calc(b[i] + 1,n) % MOD * (1LL + i) % MOD) % MOD;
        //cout << "calc = " << calc(b[i] + 1,n) << endl;
        //cout << "b[" << i << "]" << b[i] << endl;
        printf("%I64d\n",tmp);
    }
    return 0;
}