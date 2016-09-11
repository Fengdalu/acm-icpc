#include <iostream>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#define db(x) std::cout << "";
const int N = 100010;
std::vector<int> g[N];


typedef std::pair<int, int> PII;
typedef long long ll;
#define PB(x) push_back(x)
#define SZ size()
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
int cntx;
int X[N];

int a[N];
int in[N];
ll ans = 0;
ll K;

struct BIT {
    int _[N];
    void init() {
        std::fill(_, _ + N, 0);
    }
    static int lowbit(int x) {
        return (x) & (-x);
    }
    void push(int x, int v) {
        while(x < N) {
            _[x] += v;
            x += lowbit(x);
        }
    }

    int cal(int x) {
        int tot = 0;
        while(x) {
            tot +=  _[x];
            x -= lowbit(x);
        }
        return tot;
    }
} T;

void dfs(int x, int fa) {
    db("dfs: ");
    db(x); db(' ')
    if(X[a[x]] != 0) {
        int pos = std::upper_bound(X, X + cntx, K / X[a[x]]) - X;
        pos--;
        db(pos); db('\n');
        if(pos != -1) { ans += 1ll * T.cal(pos + 1); db(T.cal(pos + 1)) }
        db('\n');
    }
    else {
        ans += 1ll * T.cal(N-1);
    }
    T.push(a[x] + 1, 1);
    for(int k = 0; k != g[x].size(); k++) {
        int v = g[x][k];
        dfs(v, x);
    }
    T.push(a[x] + 1, -1);
}

void solve() {
    int n;
    ans = 0;
    scanf("%d%lld", &n, &K);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    for(int i = 1; i <= n; i++) X[i - 1] = a[i];
    std::sort(X, X + n);
    cntx = std::unique(X, X + n) - X;
    for(int i = 1; i <= n; i++) {
        a[i] = std::lower_bound(X, X + cntx, a[i]) - X;
    }
    std::fill(in, in + n + 1, 0);
    T.init();
    for(int i = 1; i <= n; i++) g[i].clear();
    for(int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        db(x) db(' ') db(y) db('\n')
            g[x].push_back(y);
        in[y]++;
    }
    for(int i = 1; i <= n; i++) {
        db("check: ")db(i) db('\n')
            if(in[i] == 0) dfs(i, i);
    }
    std::cout << ans << std::endl;
}

int main() {
    int _t; scanf("%d", &_t);
    while(_t--) solve();
    return 0;
}

