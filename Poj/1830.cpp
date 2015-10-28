#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 50

int a[N][N];
int op[N], ed[N];
int n;

int gauss()
{
    int ret = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            if(a[j][i])
            {
                for(int k = 0; k < n + 1; k++)
                    swap(a[j][k], a[i][k]);
                break;
            }
        if(!a[i][i]) continue;
        for(int j = 0; j < n; j++)
            if(i != j && a[j][i])
            {
                for(int k = 0; k < n + 1; k++) a[j][k] ^= a[i][k];
            }
    }

    for(int i = 0; i < n; i++) if(!a[i][i] && a[i][n]) return -1;
    for(int i = 0; i < n; i++) if(!a[i][i] && !a[i][n]) ret++;
    return ret;
}

int main()
{
    //freopen("input.in", "r", stdin);
    int _T; scanf("%d", &_T);
    for(int _CAS = 1; _CAS <= _T; _CAS++)
    {
        memset(a, 0, sizeof a);
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &op[i]);
        for(int i = 0; i < n; i++) scanf("%d", &ed[i]);
        for(int i = 0; i < n; i++) if(op[i] != ed[i]) a[i][n] = 1;
        for(int i = 0; i < n; i++) a[i][i] = 1;
        int x, y;
        while(true)
        {
            scanf("%d%d", &x, &y);
            if(x == 0 && y == 0) break;
            x--; y--;
            a[y][x] = 1;
        }
        int p = gauss();
        if(p != -1) printf("%d\n", (1 << p));
        else printf("Oh,it's impossible~!!\n");
    }
    return 0;
}
