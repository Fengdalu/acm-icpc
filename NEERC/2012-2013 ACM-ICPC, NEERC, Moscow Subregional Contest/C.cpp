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

int a[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        sum += a[i];
    }
    int cnt = 0;
    int ans = 0;
    cnt = (sum + n) / n;
    for(int i = 0; i < n; i++)
    {
        if(a[i] >= cnt) ans++;
    }
    printf("%d\n",ans);
    return 0;
}