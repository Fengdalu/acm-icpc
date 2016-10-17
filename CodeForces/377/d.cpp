#include <bits/stdc++.h>

typedef long long ll;
#define cmin(x, y) x = std::min(x, y)

const int N = 1e5+100;
int d[N];
int a[N];
int q[N];
bool vis[N];
int n, m;

bool check(int up) {
    std::fill(vis, vis + m + 1, 0);
    int cnt = 0;
    int has = 0;
    while(up) {
        if(d[up] != 0)  {
            if(!vis[d[up]])  has++, q[cnt++] = up;
            vis[d[up]] = true;
        }
        up--;
    }
    if(has != m) return false;
    q[cnt++] = 0;
    std::reverse(q, q + cnt);
    int tot = 0;
    for(int i = 1; i < cnt; i++) {
        tot += q[i] - q[i - 1] - 1;
        if(tot < a[d[q[i]]]) return false;
        tot -= a[d[q[i]]];
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", d + i);
    for(int i = 1; i <= m; i++) scanf("%d", a + i);
    int l = 1, r = n;
    while(l < r) {
        int mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    if(!check(l)) puts("-1");
    else printf("%d", l);
    return 0;
}
