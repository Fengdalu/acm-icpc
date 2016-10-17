#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define cmax(x, y) x = std::max(x, y)

int dp[2][27];
bool cp[27][27];
char s[100010];


int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%s", s);
    scanf("%d", &m);
    char ch[10];
    for(int i = 0; i < m; i++) {
        scanf("%s", ch);
        int u = ch[0] - 'a', v = ch[1] - 'a';
        cp[u][v] = cp[v][u] = true;
    }
    int cur = 0, next = 1;
    dp[cur][s[0] - 'a'] = 1;
    for(int i = 1; i < n; i++) {
        int u = s[i] - 'a';
        for(int j = 0; j < 27; j++) dp[next][j] = dp[cur][j];
        for(int j = 0; j < 27; j++) {
            if(!cp[j][u])
                cmax(dp[next][u], dp[cur][j] + 1);
        }
        std::swap(cur, next);
    }
    std::cout << n - *std::max_element(dp[cur], dp[cur] + 27) << std::endl;
}

