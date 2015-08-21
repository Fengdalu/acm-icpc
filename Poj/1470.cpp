#include <iostream>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 10010
#define POW 20

int ind[N], d[N];
int t[N], nt[N];
int f[N][POW];
int cnt;

void add(int a, int b)
{
    t[cnt] = b;
    nt[cnt] = ind[a];
    ind[a] = cnt++;
}

void dfs(int x, int dep)
{
    d[x] = dep;
    for(int i = 1; i < POW; i++) f[x][i] = f[f[x][i - 1]][i - 1];
    for(int k = ind[x]; k != -1; k = nt[k]) dfs(t[k], dep + 1);
}

int lca(int a, int b)
{
    if(d[b] > d[a]) swap(a, b);
    int t = d[a] - d[b];
    for(int i = 0; i < POW; i++) if(t & (1 << i)) a = f[a][i];

    if(a != b)
    {
        for(int i = POW - 1; i >= 0; i--)
        if(f[a][i] != f[b][i])
        {
            a = f[a][i];
            b = f[b][i];
        }
        a = f[a][0]; b = f[b][0];
    }
    return a;
}

int cc[N];
int main()
{
//    freopen("input.txt", "r", stdin);
    int n;
    while(~scanf("%d", &n))
    {

        int rt = -1;
        memset(ind, -1, sizeof ind);
        cnt = 0;
        for(int i = 1; i <= n; i++) f[i][0] = i;
        for(int i = 0; i < n; i++)
        {
            int r, Q, x; scanf("%d:(%d)", &r, &Q);
            for(int j = 0; j < Q; j++)
            {
                scanf("%d", &x);
                add(r, x);
                f[x][0] = r;
            }
        }
        for(int i = 1; i <= n; i++)
        if(f[i][0] == i)
        {
            for(int j = 0; j < POW; j++) f[i][j] = i;
            dfs(i, 0);
            break;
        }
        memset(cc, 0, sizeof cc);
        int Q; scanf("%d\n", &Q);
        char c;
        for(int i = 0; i < Q; i++)
        {
            while((c = getchar()) != '(' );
            int x, y; scanf("%d %d)", &x, &y);
            cc[lca(x, y)]++;
        }
        for(int i = 1; i <= n; i++) if(cc[i]) printf("%d:%d\n", i, cc[i]);
    }
    return 0;
}