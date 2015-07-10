#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
#define N 100010
#define LL long long
#define M 2000100

int t[M], nt[M];
int ind[N];
int cnt;
int n, m;
LL B, W;
int vis[N];
int c1, c2;
LL ans, md;
bool flg;

void add(int a, int b)
{
    t[cnt] = b;
    nt[cnt] = ind[a];
    ind[a] = cnt;
    cnt++;
}

int dfs(int x, bool pre)
{
    vis[x] = !pre;
    if(vis[x]) B++; else W++;
    int C = 0;
    for(int k = ind[x]; k != -1; k = nt[k])
    {
        if(vis[t[k]] == vis[x]) return -1;
        if(vis[t[k]] == -1)
        {
            int P = dfs(t[k], vis[x]);
            if(P == -1) return -1;
            C += P;
        }
    }
    return C + 1;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n + 1; i++) ind[i] = -1;
    cnt = 0;
    for(int i = 0; i < m; i++)
    {
        int op, ed;
        scanf("%d%d", &op, &ed);
        add(op, ed); add(ed, op);
    }
    for(int i = 0; i < n + 1; i++) vis[i] = -1;

    md = flg = c1 = ans = c2 = 0;
    for(int i = 1; i < n + 1; i++)
    if(vis[i] == -1)
    {
        B = W = 0;
        int C = dfs(i, 1);
        //cout << C << " " << B << " " << W << endl;
        if(C == -1) { flg = true; ans = 0; md = 1; break; }
        if(C == 2) c1++;
        if(C > 2) { c2++; md += B * (B - 1) / 2LL + W * (W - 1) / 2LL; }
    }
    //cout << md << endl;
    if(m == 0) printf("3 %I64d\n", (LL)n * (n - 1) * (n - 2) / 6LL);
    else if(flg) printf("0 1\n");
    else if(c2) printf("1 %I64d\n", md);
    else printf("2 %I64d\n", (LL)c1 * (n - 2));
    return 0;
}

