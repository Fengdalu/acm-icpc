#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int vis[199];

int main()
{
    int n, v; scanf("%d%d", &n, &v);
    memset(vis, 0, sizeof vis);
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int k, t; scanf("%d", &k);
        for(int j = 0; j < k; j++)
        {
            scanf("%d", &t);
            if(v > t) { vis[i] = true; }
        }
        if(vis[i]) ans++;
    }
    printf("%d\n", ans);
    for(int i = 0; i < n; i++)
        if(vis[i]) printf("%d ", i + 1);
    return 0;
}

