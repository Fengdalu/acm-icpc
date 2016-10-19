#include <bits/stdc++.h>

#define cmax(x, y) x = std::max(x, y)
int w[2010][100];
int dp[2][100];
int W, H, n;

int main() {
    scanf("%d%d%d", &W, &H, &n);
    for(int i = 0; i < n; i++) {
        int op, L, price;
        scanf("%d%d%d", &op, &L, &price);
        //cmax(w[op + H - 1][L], price);
        w[op + H - 1][L] = price;
    }
    int cur = 0, nxt = 1;
    std::fill(dp[cur], dp[cur] + W + 1, -1);
    dp[cur][(W + 1) / 2] = w[0][(W + 1) / 2];
    for(int i = 0; i < 2000; i++) {
        std::fill(dp[nxt], dp[nxt] + W + 1, -1);
        for(int j = 1; j <= W; j++) if(~dp[cur][j]) {
            for(int S = -2; S <= 2; S++) {
                if(S + j < 1 || S + j > W) continue;
                cmax(dp[nxt][S + j], dp[cur][j] + w[i + 1][S + j]);
            }
        }
        std::swap(cur, nxt);
    }
    printf("%d\n", *std::max_element(dp[cur], dp[cur] + W + 1));
    return 0;
}
