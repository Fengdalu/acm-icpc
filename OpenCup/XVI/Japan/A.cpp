#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

const int maxn = 10010;
const int maxm = 200;
int n, m;
char s[maxm][maxn];
int f[maxn];
int cur[maxn];

int main() {
    //freopen("A.in", "r", stdin);
    scanf("%d%d", &m, &n);
    for(int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    for(int i = 1; i <= n; i++) {
        memset(cur, 0, sizeof cur);
        for(int j = 1; j <= m; j++) {
            if(s[i][j] == 'E') cur[j]++;
            cur[j] += cur[j - 1];
        }
        for(int j = 1; j <= m; j++)
            f[j] += cur[j];
    }
    int l = 0;
    int v = m * n - f[m];
    for(int i = 0; i <= m; i++) {
        int c1 = f[i];
        int c2 = (m * n - i * n) - (f[m] - f[i]);
        if(c1 + c2 < v) {
            l = i;
            v = c1 + c2;
        }
    }
    if(f[m] == m * n) l = 0;
    if(f[m] == 0) l = m;
    printf("%d %d\n", l, l + 1);
    return 0;
}

