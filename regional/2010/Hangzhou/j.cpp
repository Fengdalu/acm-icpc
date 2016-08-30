#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

const int N = 1010;
double dp[N][N];
char s[N];
char s1[N];
char buf[3];
double p[27];
int nt[N];
int to[N][27];

void getnext(char T[], int next[], int LT) {
    int i, j;
    next[0]=-1; next[1] = 0;
    for (i = 1, j = 0; i < LT; ) {
        while (j != -1 && T[i] != T[j]) j = next[j];
        i++; j++;
        next[i] = j;
    }
}

int main() {
    int n, m;
    while(~scanf("%d%d", &n, &m)){
        if(n == 0 && m == 0) break;
        memset(p, 0, sizeof p);
        for(int i = 0; i < n; i++) {
            scanf("%s", buf);
            scanf("%lf", &p[buf[0] - 'a']);
        }
        scanf("%s", s);
        int len = strlen(s);
        getnext(s, nt, len);
        for(int i = 1; i <= len; i++) s1[i] = s[i - 1];
        for(int i = len; i >= 1; i--) nt[i] = nt[i - 1] + 1;
        for(int i = 1; i <= len; i++) if(s1[nt[i]] != s1[i]) nt[i] = 0;
        swap(s, s1);
        memset(to, 0, sizeof to);
        for(int i = 0; i <= len; i++) {
            for(int j = 0; j < 27; j++)
                if(j == s[i + 1] - 'a') {
                    to[i][j] = i + 1;
                }
                else {
                    int k = i;
                    while(k != 0 && s[k + 1] - 'a' != j) k = nt[k];
                    if(s[k + 1] == j + 'a') to[i][j] = k + 1;
                    else to[i][j] = 0;
                }
        }
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1.0;
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j < len; j++) if(dp[i][j] != 0.0) {
                double now = dp[i][j];
                for(int k = 0; k < 27; k++) dp[i + 1][to[j][k]] += now * p[k];
            }
            dp[i + 1][len] += dp[i][len];
        }
        printf("%.2f%%\n", dp[m][len]*100);
    }
    return 0;
}

