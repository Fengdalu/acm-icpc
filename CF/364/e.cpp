#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<int>g[200100];
int fa[200010];
int u[200010];
int sz[200010];
int q[2000010];
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < 2 * k; i++) {
        int x;
        scanf("%d", &x);
        ++u[x];
    }
    for(int i = 1; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int l = 0, r = 0;
    q[l] = 1;
    while(l <= r) {
        int x = q[l++];
        for(auto &t: g[x]) if(t != fa[x]){
            fa[t] = x;
            q[++r] = (t);
        }
    }
    ll ans = 0;
    for(int i = r; i >= 0; i--) {
        int v = q[i];
        if(u[v]) sz[v]++;
        for(auto &t: g[v]) if(t != fa[v]) {
            sz[v] += sz[t];
        }
        ans += min(sz[v], 2 * k - sz[v]);
    }
    cout << ans << endl;
    return 0;
}
