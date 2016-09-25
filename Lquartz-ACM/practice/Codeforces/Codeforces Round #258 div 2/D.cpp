//#pragma comment(linker,"/STACK:102400000,102400000")​

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<long, long> PLL;

#define PB push_back
#define PF push_front
#define PPB pop_back
#define PPF pop_front
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)
#define SORT(g) sort(g.BG, g.ED)
#define MEM(a,b) memset(a,b,sizeof(a))
#define REVERSE(g) reverse(g.BG,g.ED)
#define REVERSE(g,l,r) reverse(g, g.BG + i, g.ED + i)
#define SBUSTR(S,l,r) S.substr(l, (r)-(l))

typedef vector<int> VI;
typedef vector<PII> VII;
typedef deque<int> QI;
typedef deque<PII> QII;
typedef vector<LL> VL;
typedef vector<PLL> VLL;
typedef deque<LL> QL;
typedef deque<PLL> QLL;
typedef vector<string> VS;
typedef deque<string> QS;

const double eps = 1e-8;
const LL MOD = 1000000007;
string str;
int n;
LL all[2];
LL cnt[2][2];

int main() {
    int i, j;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    while(cin >> str) {
        str = "#" + str;
        n = str.length();
        MEM(cnt, 0);
        MEM(all, 0);
        for(i = 1; i < n; i++) {
            j = str[i] - 'a';
            cnt[i & 1][j]++;
            all[1] += cnt[i & 1][j];
            all[0] += cnt[(i & 1) ^ 1][j];
        }
        cout << all[0] << " " << all[1] << endl;
    }
    return 0;
}
