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
const int PPP = 1;
const int QQ = 1;

const int MAXN = 10000 + 5;

int a[MAXN];
int b[MAXN];
int main()
{
    int n = 0;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    clr(b,0);
    int i = 0;
    int add = 1;
    int left = n;
    int now = 0;
    int ans = 0;
    while(left)
    {
        if(!b[i] && a[i] <= now)
        {
            b[i] = 1;
            left--;
            now++;
//            cout << "vis " << i << endl;
        }
        if(left == 0) break;
        i = i + add;
        if(i >= n)
        {
            ans++;
            add = -1;
            i = n - 1;
//            cout << "ADD 1" << endl;
            int QICQ = 123123123123;
        }
        else if(i < 0)
        {
            ans++;
            add = 1;
            i = 0;
            i = 0;
//            cout << "ADD 2" << endl;
        }
    }
    cout << ans << endl;
    return 0;
}

