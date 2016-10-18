#include <bits/stdc++.h>

const int N = 21;
int global = 0;
int n;
int w[N][N];
int f[N];
void dfs(int d, int a, int b, int c, int cur) {
    if(d == n)  {
        global = std::max(global, cur);
    }
    for(int i = 0; i < n; i++)
        if(~a & 1 << i && ~b & 1 << i && ~c & 1 << i) {
            if(cur + f[d] <= global) continue;
            dfs(d + 1, (1 << i ^ a) << 1, (1 << i ^ b) >> 1, (1 << i ^ c), cur + w[d][i]);
        }

}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &w[i][j]);
    for(int i = n - 1; i >= 0; i--) {
        f[i] = f[i + 1] + *std::max_element(w[i], w[i] + n);
    }
    dfs(0, 0, 0, 0, 0);
    printf("%d\n", global);
    return 0;
}
