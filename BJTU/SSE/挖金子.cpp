#include <bits/stdc++.h>
#define ONES __builtin_popcount

int global;
int n, m;
int ALL;
const int N = 11;
char dp[N][1<<N][1<<N];
void dfs(int d, int ans, int must, int now) {
    if(ans >= global) return;
    if(dp[d][must][now] != 0 && dp[d][must][now] < ans) return;
    dp[d][must][now] = ans;
    if(d == n) {
        if(must != 0) return;
        global = std::min(global, ans);
        return ;
    }
    std::vector<int> L;
    for(int i = 0; i < m; i++)
        if(~must & 1 << i) L.push_back(i);
    for(int i = 0; i < m; i++)
        if(must >> i & 1) {
            if(i) now |= 1 << (i - 1);
            now |= (1 << (i)) | (1 << (i + 1));
        }
    now &= ALL;
    int TOT = L.size();
    for(int i = 0; i < (1 << TOT); i++) {
        int mk = must;
        int cur = now;
        int nxt = 0;
        for(int j = 0; j < TOT; j++)
            if(i >> j & 1) {
                int p = L[j];
                mk ^= (1 << p);
                nxt |= 1 << p;
                if(p) cur |= (1 << (p - 1));
                cur |= (1 << p);
                cur |= (1 << (p + 1));
            }
        cur &= ALL;
        nxt |= must;
        int add = ONES(mk & ALL);
        dfs(d + 1, ans + add, (~cur & ALL), nxt & ALL);
    }
}

const int ans[10][10] = {{1,1,1,2,2,2,3,3,3,4},{1,2,2,3,3,4,4,5,5,6},{1,2,3,4,4,5,6,7,7,8},{2,3,4,4,6,7,7,8,10,10},{2,3,4,6,7,8,9,11,12,13},{2,4,5,7,8,10,11,12,14,16},{3,4,6,7,9,11,12,14,16,17},{3,5,7,8,11,12,14,16,18,20},{3,5,7,10,12,14,16,18,20,22},{4,6,8,10,13,16,17,20,22,24}};
//int ans[11][11];
int main() {
    /*
    for(int i = 1; i <= 10; i++)
        for(int j = i; j <= 10; j++) {
            n = i; m = j;
            memset(dp, 0, sizeof dp);
            ALL = (1 << m) - 1;
            global = n * m;
            dfs(0, 0, 0, 0);
            ans[n][m] = global;
        }
    printf("const int ans[10][10] = {");
    for(int n = 1; n <= 10; n++) {
        if(n != 1) printf(",");
        printf("{");
        for(int m = 1; m <= 10; m++) {
            if(m != 1) printf(",");
            printf("%d", ans[std::min(n, m)][std::max(n, m)]);
        }
        printf("}");
    }
    puts("};");
    */
    int n, m; scanf("%d%d", &n, &m);
    printf("%d\n", ans[n - 1][m - 1]);
    return 0;
}
