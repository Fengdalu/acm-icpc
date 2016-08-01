#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdlib>
#include<cctype>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<fstream>
#include<numeric>
#include<iomanip>
#include<bitset>
#include<list>
#include<stdexcept>
#include<functional>
#include<utility>
#include<ctime>
#include<cassert>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(int)(n);i++)
#define repd(i,a,b,d) for(int i=(a);i!=(b);i+=d)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000007;
const double PI = acos(-1.);
const double eps = 1e-9;

const int N = 5010;
int nxt[N][N];
int pre[N][N];
int dp[N][N];
int X[N];
int s[N];
int h[N];
int cnt, n;

int main() {
    while(~scanf("%d", &n)) {
        rep(i, 0, n) scanf("%d", &s[i]);
        rep(i, 0, n) X[i] = s[i];
        sort(X, X + n);
        cnt = unique(X, X + n) - X;
        rep(i, 0, n) s[i] = lower_bound(X, X + n, s[i]) - X;
        memset(nxt, -1, sizeof nxt);
        memset(pre, -1, sizeof pre);
        memset(dp, 0, sizeof dp);
        rep(i, 0, n)
            rep(j, i + 1, n) if(!~nxt[i][s[j]]) nxt[i][s[j]] = j;
        repd(i, n - 1, -1, -1)
            repd(j, i - 1, -1, -1) if(!~pre[i][s[j]]) pre[i][s[j]] = j;

        repd(i, n - 1, -1, -1) {
            dp[i][i] = 1;
            rep(j, 0, cnt) h[j] = 0;
            rep(j, i + 1, n) {

            }
        }
    }
    return 0;
}

