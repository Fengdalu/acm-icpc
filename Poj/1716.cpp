#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#define MAXN 10005
#define MAXM 10000000

using namespace std;

int cnt;
int t[MAXM], nt[MAXM], c[MAXM], ind[MAXN];
int q[MAXN], vis[MAXN];
int f[MAXN];

void add(int a, int b, int w)
{
    cnt++;
    t[cnt] = b;
    c[cnt] = w;
    nt[cnt] = ind[a];
    ind[a] = cnt;
}

int main()
{
    int m;
    int n = 0;
    cin >> m;
    cnt = 0;
    for (int i = 0; i < 10005; i++) ind[i] = -1;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a++;
        b++;
        if (a > b) swap(a, b);
        n = max(n, b);
        add(a - 1, b, 2);
    }
    
    for (int i = 0; i <= n; i++)
    {
        f[i] = - 2147483647;
        add(i, i + 1, 0);
        add(i + 1, i, -1);
    }
    
    f[0] = 0;
    memset(q, 0, sizeof q);
    memset(vis, 0, sizeof vis);
    
    int l = 0, r = 0;
    q[l] = 0;
    vis[0] = 1;
    while (l <= r)
    {
        int x = q[l % n];
        l++;
        vis[x] = 0;
        for (int k = ind[x]; k != -1; k = nt[k])
        {
            if (f[t[k]] < f[x] + c[k])
            {
                f[t[k]] = f[x] + c[k];
                if (!vis[t[k]])
                {
                    r++;
                    q[r % n] = t[k];
                    vis[t[k]] = 1;
                }
            }			
        }
    }
    
    cout << f[n] - f[0] << endl;
    return 0;
}