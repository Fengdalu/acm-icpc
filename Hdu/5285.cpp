#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100010
#define M 200040

int ind[N];
int t[M], nt[M];
int cnt;

void add(int a, int b)
{
    t[cnt] = b;
    nt[cnt] = ind[a];
    ind[a] = cnt;
    cnt++;
}

int W, B;
int vis[N];
int w, b;
int n, m;
bool dfs(int x)
{
    if(vis[x]) w++; else b++;
    for(int k = ind[x]; k != -1; k = nt[k])
    {
        if(vis[t[k]] == -1) { vis[t[k]] = !vis[x]; if(!dfs(t[k])) return false; }
        if(vis[t[k]] == vis[x]) return false;
    }
    return true;
}

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        if(n <= 1) { puts("Poor wyh"); continue; }
        if(m == 0) { printf("%d %d\n", n - 1, 1); continue; }
        cnt = 0;
        for(int i = 1; i <= n; i++) ind[i] = -1;
        for(int i = 1; i <= n; i++) vis[i] = -1;
        for(int i = 0; i < m; i++)
        {
            int a, b; scanf("%d%d", &a, &b);
            add(a, b); add(b, a);
        }
        W = B = 0;
        bool flg = true;
        for(int i = 1; i <= n; i++)
        if(vis[i] == -1)
        {
            w = b = 0;
            vis[i] = 0;
            if(!dfs(i)) { flg = false; break; }
            W += max(w, b); B += min(w, b);
        }
        if(flg) printf("%d %d\n", W, B);
        else printf("Poor wyh\n");
    }
    return 0;
}
