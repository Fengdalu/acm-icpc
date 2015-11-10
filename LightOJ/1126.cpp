#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 51;
#define cmax(x, y) x = max(x, y)

int f[500010], g[500010];
int c[100];
int n, m;

int main()
{
    //freopen("input.in", "r", stdin);
    int _T; scanf("%d", &_T);
    for(int _C = 1; _C <= _T; _C++)
    {
        memset(f, -1, sizeof f);
        memset(g, -1, sizeof g);
        f[0] = 0;
        m = 0;

        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &c[i]);
        for(int i = 0; i < n; i++) m += c[i];
        m = (m + 1) / 2;
        for(int i = 0; i < n; i++)
        {
            int h = c[i];
            swap(f, g);
            for(int j = 0; j <= m; j++) f[j] = -1;
            for(int j = 0; j <= m; j++) if(g[j] != -1) cmax(f[j], g[j]);
            for(int j = 0; j <= m; j++)
            if(g[j] != -1)
            {
                int T = g[j], G = g[j] - j + h;
                if(T < G) swap(T, G);
                if(T <= m) cmax(f[T - G], T);
            }
            for(int j = 0; j <= m; j++)
            if(g[j] != -1)
            {
                int T = g[j] + h, G = g[j] - j;
                if(T < G) swap(T, G);
                if(T <= m) cmax(f[T - G], T);
            }
        }

        if(f[0] == 0) printf("Case %d: impossible\n", _C);
        else printf("Case %d: %d\n", _C, f[0]);
    }
    return 0;
}
