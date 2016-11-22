#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int a[100010];
bool vis[100010];
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    int k = m;
    while(k--) {
        int x; scanf("%d", &x); x--;
        vis[x] = true;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) if(!vis[i]) {
        int v = (i + 1) % n;
        if(!vis[v])ans += 1ll * a[i] * a[v];
    }
    ll tot = 0;
    for(int i = 0; i < n; i++) tot = tot + a[i];
    for(int i = 0; i < n; i++) if(vis[i]) {
        ans = ans + (tot - a[i]) * a[i];
    }
    tot = 0;
    for(int i = 0; i < n; i++) if(vis[i]) tot += 1ll * a[i];
    for(int i = 0; i < n; i++) if(vis[i]) {
        ans -= 1ll * (tot - a[i]) * a[i];
        tot -= a[i];
    }
    cout << ans << endl;
    return 0;
}
