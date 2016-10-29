#include <bits/stdc++.h>

#define cmax(x, y) x = std::max(x, y)

int w[40][10];
int tot = 0;
int a[10];
int ans;
void init() {
    for(int i = 1; i <= 9; i++)
        for(int j = 1; j <= 9; j++)
            if(i + j <= 9) {
                w[tot][i - 1]++;
                w[tot][j - 1]++;
                w[tot][i + j - 1]++;
                tot++;
            }
}

void dfs(int d, int cur) {
    if(d == tot) return;
    if(cur + tot - d <= ans) return;
    bool flag = true;
    for(int i = 0; i < 10 && flag; i++)
        if(a[i] - w[d][i] < 0) flag = false;
    if(flag) {
        for(int i = 0; i < 10; i++)
            a[i] -= w[d][i];
        cmax(ans, cur + 1);
        dfs(d + 1, cur + 1);
        for(int i = 0; i < 10; i++)
            a[i] += w[d][i];
    }
    dfs(d + 1, cur);
}

int main() {
    init();
    int T; scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++) {
        for(int i = 0; i < 9; i++) scanf("%d", a + i);
        ans = 0;
        dfs(0, 0);
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}

