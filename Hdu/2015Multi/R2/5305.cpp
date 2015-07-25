#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 10

int f[N];
int n, m;
int op[N * N], ed[N * N];
bool flg;
int ans;

void dfs(int x)
{
    if(x == m)
    {
        int flg = 1;
        for(int i = 1; i <= n; i++) if(f[i]) { flg = 0; break; }
        ans += flg;
    }
    else
    {
        if(f[op[x]] && f[ed[x]])
        {
            f[op[x]]--; f[ed[x]]--;
            dfs(x + 1);
            f[op[x]]++; f[ed[x]]++;
        }
        dfs(x + 1);
    }
}


int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        memset(f, 0, sizeof f);
        for(int i = 0; i < m; i++) { scanf("%d%d", &op[i], &ed[i]); }
        for(int i = 0; i < m; i++) f[op[i]]++;
        for(int i = 0; i < m; i++) f[ed[i]]++;
        flg = true;
        for(int i = 1; i <= n; i++) if(f[i] & 1) flg = false;
        if(!flg) puts("0");
        else
        {
            for(int i = 1; i <= n; i++) f[i] >>= 1;
            ans = 0;
            dfs(0);
            printf("%d\n", ans);
        }
    }
    return 0;
}

