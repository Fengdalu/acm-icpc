#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define PII pair<int, int>
#define AA first
#define BB second
int f[10][10];
int c[200];
int n, m, k;

bool dfs(int x, int y)
{
    if(x == n - 1 && y == m) return true;
    if(y == m) return dfs(x + 1, 0);
    int s = x * m + y;
    for(int i = 0; i < k; i++) if(2 * c[i] > n * m - s + 1) return false;
    for(int i = 0; i < k; i++)
    if(c[i])
    {
        if(x - 1 >= 0 && f[x - 1][y] == i) continue;
        if(y - 1 >= 0 && f[x][y - 1] == i) continue;

        f[x][y] = i;
        c[i]--;
        if(dfs(x, y + 1)) return true;
        c[i]++;
        f[x][y] = -1;
    }
    return false;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T; scanf("%d", &T);
    for(int _i = 1; _i <= T; _i++)
    {
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 0; i < k; i++) scanf("%d", &c[i]);
        printf("Case #%d:\n", _i);
        memset(f, -1, sizeof f);

        if(dfs(0, 0))
        {
            printf("YES\n");
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if(j != 0) printf(" ");
                    printf("%d", f[i][j] + 1);
                }
                printf("\n");
            }
        }
        else printf("NO\n");
    }
    return 0;
}