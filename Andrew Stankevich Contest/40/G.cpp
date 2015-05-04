#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define M 10000
#define N 1000
#define LL long long

LL f[N];
LL c[M];
int pre[N], ind[N];
int fr[M], t[M], nt[M];
int num[M];
bool vis[N];
int q[N];
int cnt;
int n, m, C;

void add(int a, int b, int cc, int nn)
{
    cnt++;
    c[cnt] = cc;
    fr[cnt] = a;
    t[cnt] = b;
    nt[cnt] = ind[a];
    ind[a] = cnt;

    num[cnt] = nn;
}

void spfa()
{
    int l = 0, r = 0;
    q[l] = 1;
    memset(vis, 0, sizeof vis);
    f[1] = 0;
    for(int i = 2; i <= n; i++) f[i] = -1;
    pre[1] = -1;
    while(l <= r)
    {
        int x = q[l % n];
        vis[x] = false;
        //cout << x <<endl;
        l++;
        for(int k = ind[x]; k != -1; k = nt[k])
        if(f[t[k]] == -1 || f[t[k]] > f[x] + c[k])
        {
            f[t[k]] = f[x] + c[k];
            pre[t[k]] = k;
            if(!vis[t[k]])
            {
                vis[t[k]] = true;
                r++;
                q[r % n] = t[k];
            }
        }
    }
}

int main()
{
    freopen("gas.in", "r", stdin);
    freopen("gas.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &C);
    cnt = 0;
    for(int i = 1; i <= n; i++) ind[i] = -1;
    int a, b, p;
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &a, &b, &p);
        add(a, b, p, i + 1); add(b, a, p, i + 1);
    }
    spfa();
    if(f[n] < C)
    {
        int l = 0;
        int k = n;
        while(pre[k] != -1)
        {
            q[++l] = num[pre[k]];
            k = fr[pre[k]];
        }
        printf("Unfair\n%d\n", l);
        for(int i = l; i >= 1; i--) printf("%d ", q[i]);
        printf("\n");
    }
    else
    printf("Fair\n");
    fclose(stdout);
    return 0;
}