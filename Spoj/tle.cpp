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
const int mod = 1e9;

void update(int &a, int b) {
  a = (a + b) % mod;
}

int main() {
  int _T;
  scanf("%d", &_T);
  while(_T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    vector< vector<int> >dp(n, vector<int>(1 << m, 0));
    for(int i = 0; i < 1 << m; i++) dp[0][i] = 1;
    int c; scanf("%d", &c);
    for(int j = 0; j * c < 1 << m; j++) dp[0][j * c] = 0;

    for(int i = 1; i < n; i++) {
      scanf("%d", &c);
      for(int mk = 0; mk < 1 << m; mk++) dp[i][mk] = dp[i - 1][((1 << m) - 1) ^ mk];
      for(int d = 0; d < m; d++)
        for(int mk = (1 << m) - 1; mk > -1; mk--) if(1 << d & ~mk) {
          update(dp[i][mk], dp[i][mk ^ (1 << d)]);
        }
      for(int j = 0; j * c < 1 << m; j++) dp[i][j * c] = 0;
    }
    int ans = 0;
    for(int mk = 0; mk < 1 << m; mk++) update(ans, dp[n - 1][mk]);
    cout << ans << endl;
  }
  return 0;
}
