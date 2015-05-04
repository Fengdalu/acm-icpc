#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int f[300000];
int p[300000];
char c[500010];
int a[500010], b[500010];
char buf[10];

int main()
{
    freopen("intouch.in", "r", stdin);
    freopen("intouch.out", "w", stdout);
    int n, m; scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%s", buf);
        c[i] = buf[0];
        if(c[i] == '!') scanf("%d", &a[i]);
        else scanf("%d%d", &a[i], &b[i]);
    }

    memset(f, 0, sizeof f);
    memset(p, 0, sizeof p);
    for(int i = m - 1; i > -1; i--)
    {
        if(c[i] == '!') p[a[i]]++;
        else if(c[i] == '-') { f[a[i]] -= p[b[i]]; f[b[i]] -= p[a[i]]; }
        else if(c[i] == '+') { f[a[i]] += p[b[i]]; f[b[i]] += p[a[i]]; }
    }
    for(int i = 1; i <= n; i++) printf("%d ", f[i]);
    printf("\n");
    fclose(stdout);
    return 0;
}