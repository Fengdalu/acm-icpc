/*
 *
 * 将0~6这7种牌面看作节点，把骨牌看作是连接两节点的无向弧，这样就组成了一个无向图（当然可能有重边），图中的一条欧拉路就对应一种方案。
 * 欧拉回路先递归后记录方案，如果图中有桥，先记录方案会报错。
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 20
#define MAXM 210

int t[MAXM], nt[MAXM], c[MAXM], opp[MAXM];
int out[MAXN], ind[MAXN];
int stk[MAXM], vis[MAXM], fr[MAXM];
int cnt = 0;
int l;
int n;

int abs(int x)
{
    if (x < 0) return -x;
    return x;
}

void dfs(int x)
{
    int p = ind[x];
    for (;p != -1; p = nt[p])
    {
        if (!vis[p])
        {
            vis[p] = 1;
            vis[opp[p]] = 1;
            printf("%d %d\n", x, t[p]);
            dfs(t[p]);
            fr[++cnt] = x;
            stk[cnt] = t[p];
        }

    }
}

void addedge(int a, int b, int s)
{
    cnt++;
    t[cnt] = b;
    c[cnt] = s;
    nt[cnt] = ind[a];
    ind[a] = cnt;
}

int main()
{
    int i, j, k;
    for (i = 0; i < 10; i++) ind[i] = -1;
    memset(out, 0, sizeof(out));

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        int a, b;

        scanf("%d%d", &a, &b);
        addedge(a, b, i);
        opp[cnt] = cnt + 1;
        addedge(b, a, -i);
        opp[cnt] = cnt - 1;
        out[a]++;
        out[b]++;
    }

    cnt = 0;
    j = -1;
    for (i = 0; i <= 6; i++)
        if (out[i] != 0) {j = i; break;}

    int t = 0;
    for (i = 0; i <= 6; i++)
    {
        if (out[i] & 1) {j = i; t++;}
    }

    if (t != 0 && t != 2) {printf("No solution\n"); return 0;}
    dfs(j);

    printf("\n\n");
    for (i = cnt; i >= 1; i--)
    {
        printf("%d %d\n", fr[i], stk[i]);
    }
    return 0;
}


