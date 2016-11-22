#include <bits/stdc++.h>
const int N = 100010;
const int NN = 20;
const int M = 100010*2;

bool dp[NN][1 << NN];
int pre[NN][1 << NN];
int n, m;
int a[M], b[M];
int in[N], out[N];
int id[N], node[NN];
int fa[N];
int f[NN][NN];
bool vis[N];
std::vector<int>g[N], g1[N], g3[NN];

inline void solve() {
    scanf("%d%d", &n, &m);
    if(m < n) {
        puts("There is no route, Karl!");
        return ;
    }
    for(int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y); x--; y--;
        a[i] = x;
        b[i] = y;
        /*
        g[x].push_back(y);
        g[y].push_back(x);
        */
        out[x]++;
        in[y]++;
    }
    std::fill(id, id + n, -1);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(in[i] == 1 && out[i] == 1)  continue;
        id[i] = cnt;
        node[cnt] = i;
        cnt++;
    }
    for(int i = 0; i < m; i++) {
        int x = a[i], y = b[i];
        int ix = id[x], iy = id[y];
        if(id[x] != - 1 && id[y] != -1) {
            g1[ix].push_back(iy);
            g1[iy].push_back(ix);
        }
        g[x].push_back(y);
        g[y].push_back(x);
    }

    if(cnt == 0) {
        int i = 0;
        while(i != 1) {
            printf("%d ", i);
            i = g[i][0];
        }
        printf("%d ", i);
        return;
    }

    for(int i = 0; i < cnt; i++) {
        std::fill(vis, vis + n, 0);
        int op = i;
        std::queue<int> q;
        q.push(node[i]);
        vis[node[i]] = true;
        while(q.size()) {
            int x = q.front();
            q.pop();
            for(int i = 0; i < g[x].size(); i++) {
                int v = g[x][i];
                if(vis[v]) continue;
                if(id[v] != -1) g3[op].push_back(v), f[op][v] = true;
                vis[v] = true;
                q.push(v);
            }
        }
    }

    memset(dp, 0, sizeof dp);
    memset(pre, -1, sizeof pre);

    dp[0][1] = 1;
    std::cout << cnt << std::endl;
    for(int i = 0; i < cnt; i++) {
        if(g3[i].size() >= 2) {
            puts("There is no route, Karl!");
            return;
        }
    }
    for(int j = 0; j < 1 << cnt; j++) {
        for(int i = 0; i < cnt; i++)
            if(((1 << i) & j) != 0) if(dp[i][j]) {
                for(auto &k: g3[i]) {
                    dp[k][(1 << k) | j] = true;
                    pre[k][(1 << k) | j] = i;
                }
                if(g3[i].size() == 0) {
                    for(auto &k: g1[i]) {
                        dp[k][(1 << k) | j] = true;
                        pre[k][(1 << k) | j] = i;
                    }
                }
            }
    }

    int all = (1 << cnt) - 1;
    std::vector<int>ans;
    for(int i = 1; i < cnt; i++)
        if(dp[0][all] && f[i][0]) {
            int x = i, mk = (all);
            while(pre[x][mk] != -1) {
                int st = node[pre[i][mk]];
                std::queue<int> q; q.push(st);
                std::fill(vis, vis + n, 0);

                while(q.size()) {
                    int x = q.front();
                    std::cout << x << std::endl;
                    q.pop();
                    if(x == node[i]) break;
                    for(int i = 0; i < g[x].size(); i++) {
                        int v = g[x][i];
                        if(vis[v]) continue;
                        vis[v] = true;
                        fa[v] = x;
                        q.push(x);
                    }
                }

                int k = node[i];
                while(k != st) {
                    ans.push_back(k);
                    k = fa[k];
                }
                ans.push_back(i);
                mk = mk ^ (1 << x);
                x = st;
            }
            std::reverse(ans.begin(), ans.end());
            for(int i = 0; i < ans.size(); i++) {
                printf("%d ", ans[i] + 1);
            }
            return;
        }
    puts("There is no route, Karl!");
}
int main() {
    solve();
    return 0;
}


