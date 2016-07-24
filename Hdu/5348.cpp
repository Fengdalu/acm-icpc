#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define PII pair<int, int>
#define MP(a, b) make_pair(a, b)
#define AA first
#define BB second

namespace G
{
    const int MAXN = 200010, MAXM = 700000 * 2;
    int ind[MAXN], in[MAXN], fa[MAXN];
    int nt[MAXM], chose[MAXM], vis[MAXM], t[MAXM], opp[MAXM];
    typedef PII element;
    typedef int state;
    element f[MAXM];
    int cnt;
    int n, m;

    void init()
    {
//        memset(ind, -1, sizeof ind);
//        memset(in, 0, sizeof in);
//        memset(chose, 0, sizeof chose);
//        memset(vis, 0, sizeof vis);
        for(int i = 1; i <= n; i++) fa[i] = i;
        for(int i = 1; i <= n; i++) ind[i] = -1;
        for(int i = 1; i <= n; i++) in[i] = 0;
        cnt = 0;
    }

    int addedge(int x, int y)
    {
        in[y]++;
        cnt++;
        t[cnt] = y;
        nt[cnt] = ind[x];
        ind[x] = cnt;
        chose[cnt] = false;
        vis[cnt] = false;
        return cnt;
    }

    int find(int x)
    {
//        if(fa[x] == x) return x;
//        fa[x] = find(fa[x]);
//        return fa[x];
        int rt = x, tmp;
        while(fa[rt] != rt) rt = fa[rt];
        while(x != rt)
        {
            tmp = fa[x];
            fa[x] = rt;
            x = tmp;
        }
        return rt;
    }

    void add2(int x, int y, int id)
    {
        int tmp1 = addedge(x, y), tmp2 = addedge(y, x);
        opp[tmp1] = tmp2; opp[tmp2] = tmp1;
        f[id] = MP(tmp1, tmp2);
        fa[find(x)] = find(y);
    }

    int odd[MAXN];
    void addext()
    {
        for(int i = 1; i <= n; i++) odd[i] = -1;
        for(int i = 1; i <= n; i++) if(in[i] & 1)
        if(odd[find(i)] == -1) odd[find(i)] = i;
        else
        {
            add2(i, odd[find(i)], 0);
            odd[find(i)] = -1;
        }
    }


    int stk[MAXM * 10];
    void dfs(int x)
    {
        int l = -1;
        stk[++l] = x;

        while(l >= 0)
        {
            x = stk[l--];
            for(int k = ind[x]; ind[x] != -1; ind[x] = nt[k], k = ind[x])
            if(!vis[k])
            {
                vis[k] = vis[opp[k]] = true;
                chose[k] = true;
                stk[++l] = x;
                stk[++l] = t[k];
                break;
            }
        }
    }
//        for(int k = ind[x]; ~k; k = nt[k])
//        if(!vis[k])
//        {
//            vis[k] = vis[opp[k]] = true;
//            chose[k] = true;
//            dfs(t[k]);
//        }


    void dfs()
    {
        for(int i = 1; i <= n; i++) { dfs(i);}
    }

    void output()
    {
        for(int i = 1; i <= m; i++)
        if(chose[f[i].AA]) printf("1\n");
        else printf("0\n");
    }
}

int main()
{
//    freopen("1006.in", "r", stdin);
//    freopen("1006.out", "w", stdout);
    int T; scanf("%d", &T);
    int a, b;
    while(T--)
    {
        scanf("%d%d", &G::n, &G::m);
        G::init();
        for(int i = 0; i < G::m; i++)
        {
            scanf("%d%d", &a, &b);
            G::add2(a, b, i + 1);
        }
        G::addext();
        G::dfs();
        G::output();
    }
    return 0;
}
