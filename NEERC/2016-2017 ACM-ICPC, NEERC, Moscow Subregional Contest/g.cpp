#include <bits/stdc++.h>

typedef std::pair<int, int> pii;
const int MX = 200;
const int N = MX * MX;
const int M = MX * MX;
int stk[N];
int ind[N];
int nt[M], t[M], c[M], vis[M], chose[M];
int cnt = 0;

void add(int x, int y, int z) {
    t[cnt] = y;
    nt[cnt] = ind[x];
    c[cnt] = z;
    ind[x] = cnt++;
}

std::vector<int> ans;
void dfs(int x) {
    int l = -1;
    stk[++l] = x;
    while(l >= 0) {
        int x = stk[l--];
        for(int k = ind[x]; ind[x] != -1; ind[x] = nt[k], k = ind[x])
            if(!vis[k]) {
                // 无向图加入下面这句
                vis[k] = true;
                // ==================
                chose[k] = true;
                stk[++l] = x;
                stk[++l] = t[k];
                break;
            }
        if(ind[x] == -1) {
            ans.push_back(x);
        }
    }
}

int main() {
    int n; scanf("%d", &n);
    std::fill(ind, ind + n + 1, -1);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) if(i != j) {
            add(i, j, 0);
        }
    add(0, 1, 0);
    add(1, 0, 0);
    dfs(0);
    int t = ans[1];
    for(int i = 0; i < ans.size() - 3; i++)
        printf("%d %d %d\n", ans[i + 1], ans[i + 1], ans[i]);
    int lst = ans[ans.size() - 3];
    printf("%d %d %d\n", 0, t, lst);
    return 0;
}
