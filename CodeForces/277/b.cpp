#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef long long ll;
#define AA first
#define BB second
#define MP make_pair
#define SZ size
#define PB push_back
const int N = 200;
int match[N];
bool vis[N];
int a[N], b[N];
vector<int>g[N];
int n, m;

int dfs(int x) {
    if(vis[x]) return false;
    vis[x] = true;
    for(auto &t: g[x]) {
        if(match[t] == -1 || dfs(match[t])) {
            match[t] = x; return true;
        }
    }
    return false;
}
int main() {
    memset(match, -1, sizeof match);
    scanf("%d", &n); for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &m); for(int i = 0; i < m; i++) scanf("%d", &b[i]);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) if(abs(a[i] - b[j]) <= 1)
            g[i].PB(j);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        memset(vis, 0, sizeof vis);
        if(dfs(i)) ans++;
    }
    printf("%d", ans);
    return 0;
}


