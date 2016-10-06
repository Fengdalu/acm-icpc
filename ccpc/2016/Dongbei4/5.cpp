#include <bits/stdc++.h>

int a[50][50];
int main() {
    int _t;
    int n, m;
    scanf("%d", &_t);
    for(int cas = 1; cas <= _t; cas++) {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf("%d", &a[i][j]);
        if(n == 1 && m == 1) { printf("Case #%d: No\n", cas); continue; }
        bool flag = false;
        for(int i = 0; i < m; i++) {
            for(int j = i + 1; j < m; j++) {
                flag |= a[0][i] == a[0][j];
                flag |= a[n - 1][i] == a[n - 1][j];
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                flag |= a[i][0] == a[j][0];
                flag |= a[i][m - 1] == a[j][m - 1];
            }
        }
        for(int i = 0; i < n - 1; i++)
            for(int j = 0; j < m - 1; j++) {
                flag |= a[i][j] == a[i + 1][j];
                flag |= a[i][j + 1] == a[i][j];
            }
        printf("Case #%d: %s\n", cas, flag ? "Yes" : "No");
    }
    return 0;
}
