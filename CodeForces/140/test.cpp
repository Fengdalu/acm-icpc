#include <algorithm>　　　
#include <bitset>　　　　
#include <cctype>
#include <cerrno>
#include <clocale>
#include <cmath>
#include <complex>　　　　
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>　　　　　
#include <exception>　　　
#include <fstream>
#include <functional>　　　
#include <limits>
#include <list>　　　　　
#include <map>　　　　　　
#include <iomanip>
#include <ios>　　　　　　
#include <iosfwd>　　　　　
#include <iostream>
#include <istream>　　　　
#include <ostream>　　　　
#include <queue>　　　　　
#include <set>　　　　　　
#include <sstream>　　　　
#include <stack>　　　　　
#include <stdexcept>　　　
#include <streambuf>　　　
#include <string>　　　　
#include <utility>　　　　
#include <vector>　　　　　
#include <cwchar>
#include <cwctype>

using namespace std;
//#define Online_Judge
#define outstars cout << "***********************" << endl;
#define clr(a,b) memset(a,b,sizeof(a))
#define lson l , mid  , rt << 1
#define rson mid + 1 , r , rt << 1 | 1
#define mk make_pair
#define pb push_back
#define sz size()
#define AA first
#define BB second

#define FOR(i , x , n) for(int i = (x) ; i < (n) ; i++)
#define FORR(i , x , n) for(int i = (x) ; i <= (n) ; i++)
#define REP(i , x , n) for(int i = (x) ; i > (n) ; i--)
#define REPP(i ,x , n) for(int i = (x) ; i >= (n) ; i--)
const int MAXN = 2000 + 5;
const int MAXV = 4000 + 50;
const int sigma_size = 26;

const int inf = 0x3f3f3f3f;
const int INF = ~0U >> 1;
const int IMIN = 0x80000000;

#define eps 1e-10
const long long MOD = 1000000000 + 7;
const int mod = 10007;
typedef long long LL;
const double PI = acos(-1.0);
typedef double D;
typedef pair<int , int> pii;
typedef vector<int> vec;
typedef vector<vec> mat;

#define Bug(s) cout << "s = " << s << endl;
///#pragma comment(linker, "/STACK:102400000,102400000")
LL a[100][100];
LL b[100];
int m = 45;
LL calcp(LL p,LL n,LL tt)
{
    if(tt < 1) return 0;
    if(n == 0) return 0LL;
    if(n == b[p - 1]) return a[p][tt];
    else if(n < b[p - 1]) return calcp(p - 1, n, tt);
    else return a[p][tt] + calcp(p - 1, n - b[p - 1],tt - 1);
}
LL calc(LL n,LL tt)
{
    if(n == 0) return 0LL;
    LL p;
    LL ans = 0;
    FORR(i,1,m)
        {
            if(n - b[i - 1] >= 0)
            {
                n -= b[i - 1];
                if(tt > 0)ans += a[i][tt];
                p = i;
            }
        }
    if(n < b[p - 1]) return ans + calcp(p - 1,n,tt);
    else
    {
        n -= b[p - 1];
        return ans + calcp(p - 1,n,tt - 1) + a[p][tt];
    }
}
int main()
{
    clr(a,0);
    a[1][1] = 1;
    FORR(i,2,m)
        FORR(j,1,i)
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
    LL n,t;
    LL ans = 0;
    b[0] = 1LL;
    FORR(i,1,m) b[i] = b[i - 1] * 2LL;
    cin >> n >> t;
    LL tt = -1;
    n++;
    FORR(i,0,m) if(t == b[i]) tt = i;
    tt++;/*
    while(n)
    {
        FORR(i,1,m)
        {
            if(n - b[i - 1] >= 0)
            {
                n -= b[i - 1];
                if(tt > 0)ans += a[i][tt];
            }
        }
    }
    //FIRST
    LL FIRST;
        FORR(i,1,m)
        {
            if(n - b[i - 1] >= 0)
            {
                n -= b[i - 1];
                if(tt > 0)ans += a[i][tt];
                FIRST = i;
            }
        }
    if(b[FIRST - 1] >= n)
    {
        ans += a[FIRST][tt];
        tt--;
        while(n)
        {
            FORR(i,1,m)
            {
                if(n - b[i - 1] >= 0)
                {
                    n -= b[i - 1];
                    if(tt > 0)ans += a[i][tt];
                }
            }
        }
    }
    else
    {
        while(n)
        {
            FORR(i,1,m)
            {
                if(n - b[i - 1] >= 0)
                {
                    n -= b[i - 1];
                    if(tt > 0)ans += a[i][tt];
                }
            }
            tt--;
        }
    }*/
    LL hehe = 0;
    if(t == 1) hehe = -1;
    cout << calc(n,tt)  + hehe<< endl;
    return 0;
}