#include <bits/stdc++.h>

const int N = 600;
int a[N], b[N];
int S[N];
bool dp[N][N];
int pre[N][N];
int same[N][N];
int n, m;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    for(int i = 1; i <= n; i++)
        S[i] = S[i - 1] + a[i];
    for(int i = 1; i <= n; i++) {
        same[i][i] = true;
        for(int j = i + 1; j <= n; j++) {
            same[i][j] = same[i][j - 1] && (a[j] == a[j - 1]);
        }
        same[i][i] = false;
    }

    scanf("%d", &m);
    for(int i = 1; i <= m; i++) scanf("%d", b + i);
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int k = 0; k < i && !dp[i][j]; k++)
                if(dp[k][j - 1] && (S[i] - S[k] == b[j]) && !same[k + 1][i]) dp[i][j] = true, pre[i][j] = k;
        }
    }
    if(dp[n][m]) {
        puts("YES");
        int i = n, j = m;
        while(j != 0) {
            int p = pre[i][j];
            int MX = *std::max_element(a + p + 1, a + i + 1);
            int P;
            if(p + 1 == i) {
                i = p;
                j--;
                continue;
            }
            for(int k = p + 1; k <= i; k++) if(a[k] == MX) {
                if(k + 1 <= i && a[k + 1] < MX) { P = k; break; }
                if(k - 1 > p && a[k - 1] < MX) { P = k; break; }
            }
            int UP = i;
            int sum = a[P];
            while(UP != p + 1) {
                if(P + 1 <= UP && sum > a[P + 1])  {
                    printf("%d R\n", P);
                    sum += a[P + 1];
                    UP--;
                }
                else if(P - 1 > p && sum > a[P - 1]) {
                    printf("%d L\n", P);
                    sum += a[P - 1];
                    P--;
                    UP--;
                }
            }
            j--; 
            i = p;
        }
    }
    else puts("NO");
    return 0;
}
