#include <bits/stdc++.h>

#define MP std::make_pair
#define AA first
#define BB second
#define cmax(x, y) x = std::max(x, y)
const int N = 5e3+1;
typedef std::pair<int, int> pii;
int ind[N];
int op[N], to[N], nt[N], w[N];
int dp[N][N];
bool vis[N][N];
int pre[N][N];
int cnt = 0;

void add(int a, int b, int c) {
    op[cnt] = a;
    to[cnt] = b;
    w[cnt] = c;
    nt[cnt] = ind[a];
    ind[a] = cnt;
    cnt++;
}

int main() {
    int n, m, K;
    scanf("%d%d%d", &n, &m, &K);
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= n; j++)
            dp[i][j] = 1e9+1;
    std::fill(ind, ind + n, -1);
    for(int i = 0; i < m; i++) {
        int u, v, c; scanf("%d%d%d", &u, &v, &c);
        u--; v--;
        add(u, v, c);
    }
    std::queue<pii> q;
    dp[0][1] = 0;
    vis[0][1] = true;
    q.push(MP(0, 1));
    while(q.size()) {
        pii sta = q.front(); q.pop();
        int W = dp[sta.AA][sta.BB];
        vis[sta.AA][sta.BB] = false;
        for(int k = ind[sta.AA]; k != -1; k = nt[k]) {
            int v = to[k];
            int c = w[k];
            if(W + c > K) continue;
            if(W + c < dp[v][sta.BB + 1]) {
                dp[v][sta.BB + 1] = W + c;
                pre[v][sta.BB + 1] = sta.AA;
                if(!vis[v][sta.BB + 1]) {
                    q.push(MP(v, sta.BB + 1));
                    vis[v][sta.BB + 1] = true;
                }
            }
        }
    }
    for(int i = n; i >= 0; i--) {
        if(dp[n - 1][i] <= K) {
            printf("%d\n", i);
            pii cur = MP(n - 1, i);
            std::vector<pii> ans;
            ans.push_back(cur);
            while(cur.AA != 0) {
                cur.AA = pre[cur.AA][cur.BB];
                cur.BB--;
                ans.push_back(cur);
            }
            std::reverse(ans.begin(), ans.end());
            for(int i = 0; i < ans.size(); i++) printf("%d ", ans[i].AA + 1);
            return 0;
        }
    }
    return 0;
}
