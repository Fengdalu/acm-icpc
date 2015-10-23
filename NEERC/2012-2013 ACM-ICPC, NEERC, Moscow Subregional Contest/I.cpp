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
#define dbg(x) cerr << #x << " = " << x << endl;
const double PI = acos(-1.0);
const LL MOD = 1000000000 + 7;


const int MAXN = 10000 + 5;

bool can(LL x,LL y,LL a,LL b)
{
    if(x >= a && y >= b) return true;
    if(x >= b && y >= a) return true;
}
LL fenf(LL x,LL y,LL a,LL b,bool& canjiao,LL jiaox,LL jiaoy)
{
//    cout << x << " " << y << " " << a << " " << b << endl;
    LL x1,x2,y1,y2;
    LL ret = (x / a) * (y / b);
//    dbg(ret);
    x1 = x % a;
    y1 = b;
    x2 = a;
    y2 = y % b;
    LL need1 = y / b;
    if (x1 == 0) need1 = 0;
    LL need2 = x / a;
    if (y2 == 0) need2 = 0;
    if(need1 != 0) canjiao = can(x1,y1,jiaox,jiaoy);
    if(need2 != 0) canjiao = can(x2,y2,jiaox,jiaoy);
    if(need1 != 0 && need2 != 0) canjiao = can(x1,y2,jiaox,jiaoy);
    return ret;
}
LL calc(LL x,LL y,LL a,LL b)
{
    LL x1,x2,y1,y2;
    LL ret = (x / a) * (y / b);
    x1 = x % a;
    y1 = b;
    x2 = a;
    y2 = y % b;
    LL need1 = y / b;
    if (x1 == 0) need1 = 0;
    LL need2 = x / a;
    if (y2 == 0) need2 = 0;
    LL la = x % a;
    LL lb = x % b;
//    cout << x1 << " " << y1 << " " << need1 << endl;
//    cout << x2 << " " << y2 << " " << need2 << endl;
    if(need1 == 0 && need2 == 0) return ret;
    if(need2 == 0)
    {
//        cout << "HI" << endl;
        int tmp = a / x1;
        return ret + (need1 + tmp - 1) / tmp;
    }
    if(need1 == 0)
    {
        int tmp = b / y2;
        return ret + (need2 + tmp - 1) / tmp;
    }
    ///============================
    LL add = 1000000000000000000LL;
    LL now = 0;
    need1 ++;
    LL tmp = b / y2;
    now += (need2 + tmp - 1) / tmp;
    tmp = tmp = a / x1;
    now += (need1 + tmp - 1) / tmp;
    //dbg(now);
    cmin(add, now);
    now = 0;
    need1 --;
    need2 ++;
    tmp = b / y2;
    now += (need2 + tmp - 1) / tmp;
    tmp = tmp = a / x1;
    now += (need1 + tmp - 1) / tmp;
    //dbg(now);
    cmin(add,now);
    return add + ret;
    ///============================
//    cout << "CHAI" << endl;
    LL f1x,f1y,f2x,f2y;
    LL cntf1,cntf2;
    bool canjiao;
    bool f1,f2;
    if(a >= b)
    {
        // calc x2
        LL tmp = b / y2;
        //dbg(tmp);
        LL add = 0;
        ret += (need2 + tmp - 1) / tmp;
        //dbg(ret);
        f1 = f2 = false;
        canjiao = false;
        LL cnt1 = 0;
        if(need2 / tmp && b % y2)
        {
            f1y = b % y2;
            f1x = x2;
            f1 = true;
            cnt1 += fenf(f1x,f1y,y1,x1,canjiao,la,lb) * (need2 / tmp);
//            cout << "fenf = " << fenf(f1x,f1y,x1,y1,canjiao,la,lb) << endl;
        }
        if(need2 % tmp)
        {
            f2y = b - y2 * (need2 % tmp);
            f2x = x2;
            f2 = true;
            cnt1 += fenf(f2x,f2y,y1,x1,canjiao,la,lb);
//            cout << "fenf = " << fenf(f2x,f2y,x1,y1,canjiao,la,lb) << endl;
        }
        if(!canjiao) need1++;
//        dbg(need1);
//        dbg(cnt1);
        need1 = need1 - cnt1;
//        dbg(ret);
//        dbg(need1);
//        cout << endl;
        if(need1 <= 0) return ret;
        tmp = a / x1;
        return ret + (need1 + tmp - 1) / tmp;
    }
    else
    {
        //calc x1
    }
    return 1000000000000000000LL;
}
int main()
{
    LL x,y,a,b;
    cin >> x >> y >> a >> b;
    LL ans = 1000000000000000000LL;
    if(x >= a && y >= b) cmin(ans, calc(x,y,a,b));
    if(x >= b && y >= a) cmin(ans, calc(x,y,b,a));
    swap(x,y);
    if(x >= a && y >= b) cmin(ans, calc(x,y,a,b));
    if(x >= b && y >= a) cmin(ans, calc(x,y,b,a));
    cout << ans << endl;
}