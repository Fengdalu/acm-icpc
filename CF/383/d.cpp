#include <bits/stdc++.h>

using namespace std;
#define AA first
#define BB second
#define MP make_pair
#define PII pair<int, int>
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define PB push_back

typedef long long LL;
const int N = 2000;
LL dp[2][2000];
int w[N], b[N], fa[N];
LL totw[N], totb[N];
vector<PII> a[N];

int find(int x) {
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
int main() {
    int n, m, W;
    scanf("%d%d%d", &n, &m, &W);
    for(int i = 0; i < n; i++) scanf("%d", w + i);
    for(int i = 0; i < n; i++) scanf("%d", b + i);
    for(int i = 0; i < n; i++) fa[i] = i;
    for(int i = 0; i < m; i++) {
        int x, y; scanf("%d%d", &x, &y); x--; y--;
        if(find(x) == find(y)) continue;
        x = find(x); y = find(y);
        fa[x] = y;
    }
    for(int i = 0; i < n; i++) {
        totw[find(i)] += w[i];
        totb[find(i)] += b[i];
        a[find(i)].PB(MP(w[i], b[i]));
    }
    int cur = 0, nxt = 1;
    for(int i = 0; i < n; i++) if(find(i) == i) {
        for(int j = 0; j <= W; j++) dp[nxt][j] = 0;
        for(int j = 0; j <= W - totw[i]; j++) cmax(dp[nxt][j + totw[i]], dp[cur][j] + totb[i]);
        for(auto &p: a[i]) {
            LL w = p.AA, b = p.BB;
            for(int j = 0; j <= W - w; j++) cmax(dp[nxt][j + w], dp[cur][j] + b);
        }
        for(int j = 0; j <= W; j++) cmax(dp[nxt][j], dp[cur][j]);
        swap(cur, nxt);
    }
    printf("%I64d\n", *max_element(dp[cur], dp[cur] + W + 5));
    return 0;
}
