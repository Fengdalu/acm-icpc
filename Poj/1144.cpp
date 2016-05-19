#include <iostream>
#include <cstdio>
#include <cstring>
#define N 200
#define M 1000000

using namespace std;

int ind[N], dfn[N], low[N];
bool flg[N];
int t[M], nt[M];
int cnt = 0;
char s[10000];
int ans;
int cc;

void add(int a, int b)
{
    cnt++;
    t[cnt] = b;
    nt[cnt] = ind[a];
    ind[a] = cnt;
}

void dfs(int x, int fa)
{
    dfn[x] = low[x] = ++cnt;
    for(int k = ind[x]; k != -1; k = nt[k])
        if(t[k] != fa)
        {
            if(!dfn[t[k]] )
            {
                dfs(t[k], x);
                if(x == 1) cc++;
                else
                {
                    low[x] = min(low[x], low[t[k]]);
                    if(low[t[k]] >= dfn[x]) flg[x] = true;
                }
            }
            else low[x] = min(low[x], dfn[t[k]]);
        }
    //cout << x << " " << dfn[x] << " " << low[x] << endl;
}

int main()
{
    while(true)
    {
        int n;
        scanf("%d\n", &n);
        if(n == 0) break;
        cnt = 0;
        for(int i = 0; i <= n; i++) ind[i] = -1;
        memset(dfn, 0, sizeof dfn);
        while(true)
        {
            gets(s);
            if(!strcmp(s, "0")) break;
            int x, y;
            int len = strlen(s);
            int i;
            int num = 0;
            for(i = 0; i < len; i++)
            {
                if(s[i] == ' ') break;
                else num = num * 10 + s[i] - '0';
            }
            x = num;
            for(;i < len; i++)
            {
                if(s[i] == ' ')
                {
                    add(x, num);
                    add(num, x);
                    num = 0;
                }
                else num = num * 10 + s[i] - '0';
            }
            add(x, num);
            add(num, x);
            num = 0;
        }
        memset(flg, 0, sizeof flg);
        ans = 0; cnt = 0; cc = 0;
        dfs(1, -1);
        for(int i = 2; i <= n; i++) if(flg[i]) ans++;
        if(cc > 1) ans++;
        printf("%d\n", ans);
    }
    return 0;
} 
