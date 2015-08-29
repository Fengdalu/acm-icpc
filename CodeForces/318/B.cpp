#include <iostream>
#include <cstdio>
#include <iostream>
#include <set>
#include <cstring>
using namespace std;
#define N 5000
#define PII pair<int, int>
#define A first
#define B second

PII e[N];
bool f[N][N];
int c[N];
int n, m;

int main()
{
    memset(c, 0, sizeof c);
    memset(f, 0, sizeof f);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int x, y; scanf("%d%d", &x, &y);
        c[x]++;
        c[y]++;
        e[i] = PII(x, y);
        f[x][y] = true;
        f[y][x] = true;
    }
    int ans = (5 * N);
    for(int i = 0; i < m; i++)
    {
        int tmp = c[e[i].A] + c[e[i].B];
        for(int j = 1; j <= n; j++)
        if(f[e[i].A][j] && f[e[i].B][j])
        {
            ans = min(ans, tmp + c[j]);
        }
    }
    if(ans == (5 * N)) printf("-1");
    else printf("%d\n", ans - 6);
    return 0;
}
