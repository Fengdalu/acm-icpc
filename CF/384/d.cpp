#include <bits/stdc++.h>

using namespace std;

const int N = 3e5+100;

typedef long long LL;

vector<int> g[N];
int a[N];
bool flag = false;
LL ans;
LL sum[N];

LL dfs(int x, int fa) {

    bool vis = false;
    LL f1 = 0, f2 = 0;
    int s = 0;

    for(int u: g[x]) if(u != fa) {
        s++;
        LL w = dfs(u, x);
        sum[x] += sum[u];
        if(s == 1) {
            f1 = w;
        }
        else if(s == 2) {
            f2 = w;
        }
        else {
            if(w > f2) f2 = w;
        }
        if(s >= 2 && f2 > f1) swap(f2, f1);
    }
    if(s >= 2) {
        if(!flag) ans = f1 + f2;
        flag = true;
        ans = max(f1 + f2, ans);
    }
    sum[x] += a[x];
    if(s >= 1) return max(f1, sum[x]);
    else return sum[x];
}


int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    for(int i = 0; i < n - 1; i++) {
        int u, v; scanf("%d%d", &u, &v); v--; u--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, 0);
    if(flag) {
        cout << ans << endl;
    }
    else cout << "Impossible" << endl;
    return 0;
}
