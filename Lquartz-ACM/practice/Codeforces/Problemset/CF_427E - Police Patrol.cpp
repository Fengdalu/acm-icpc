//#pragma comment(linker,"/STACK:102400000,102400000")
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <functional>

using namespace std;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define BGN begin()
#define END end()
#define SZ size()
#define SORT(p) sort(p.BGN,p.ED)
#define CLR(a, b) memset(a, (b), sizeof(a))
#define mabs(x) (x < 0 ? -x : x)
#define sqr(x) ((x)*(x))
#define ITE ::iterator
typedef long long LL;
typedef pair<int, int> PII;
typedef vector <int> VI;
typedef set < int > SI;
#define INF (1LL<<62)
#define N 1111111
LL n, m;
LL d[N];

int main() {
    int Test;
    while(cin >> n >> m) {
        for(int i = 1; i <= n; i++){
            scanf("%I64d", &d[i]);
        }
        int lz = max(n / 2 - 10, 1LL);
        int rz = min(n / 2 + 10, n);
        LL ans = INF;
        for(int x = lz; x <= rz; x++) {
            LL dmin = 0;
            int l = 1;
            while(l <= x) {
                dmin += (d[x] - d[l]);
                l += m;
            }
            int r = n;
            while(x <= r) {
                dmin += (d[r] - d[x]);
                r -= m;
            }
            ans = min(ans, dmin);
        }
        cout << ans*2LL << endl;
    }
    return 0;
}
