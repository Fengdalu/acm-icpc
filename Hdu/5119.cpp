#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
using namespace std;
#define AA first
#define BB second
typedef long long LL;
typedef pair<int, int> PII;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define PB(x) push_back(x)
#define SZ size()
#define MP(a, b) make_pair(a, b)
#define OP begin()
#define ED end()
#define CLR clear()
#define INS(x) insert(x)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define MEM(a) memset(a, 0, sizeof a)

typedef long long ll;
int f[1 << 21], g[1 << 21];
int main() {
    int T;
    scanf("%d", &T);
    int cas = 1;
    while(T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        memset(f, 0, sizeof f);
        memset(g, 0, sizeof g);
        f[0] = 1;
        for(int i = 0; i < n; i++) {
            int x;
            memset(g, 0, sizeof g);
            scanf("%d", &x);
            for(int mk = 0; mk < 1 << 21; mk++) {
                g[mk] += f[mk];
                g[mk ^ x] += f[mk];
            }
            swap(f, g);
        }
        ll ans = 0;
        for(int i = m; i < 1 << 21; i++)
            ans += f[i];
        cout << "Case #" << cas++ << ": " << ans << endl;
    }
    return 0;
}
