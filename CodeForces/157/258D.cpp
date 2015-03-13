#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define DB double
#define N 2000

DB f[N][N];
int a[N];
int n, k;

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    memset(f, 0, sizeof f);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        if(i != j)
        {
            if(a[i] > a[j]) f[i][j] = 1; 
        }
    for(int j = 0; j < k; j++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        x--; y--;
        for(int i = 0; i < n; i++)
        if(i != x && i != y)
        {
            f[i][x] = f[i][y] = 0.5 * f[i][x] + 0.5 * f[i][y];
            f[y][i] = 1.0 - f[i][y];
            f[x][i] = 1.0 - f[i][x];
        }
        f[x][y] = f[y][x] = 0.5;
    }
    DB ans = 0.0;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            ans += f[i][j];
    /*
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%.2f ", f[i][j]);
        putchar('\n');
    }
    */
    printf("%.6f\n", ans);
    return 0;
}