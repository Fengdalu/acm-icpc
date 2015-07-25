#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
#define N 3000
#define M 130000
#define INF 0x3f3f3f
#define LL long long

int ind[N];
int t[M], nt[M], opp[M];
LL c[M];
int op[M], ed[M], pt[M];
int cnt;
int n, m;

int add(int a, int b, int C)
{
    t[cnt] = b;
    nt[cnt] = ind[a];
    ind[a] = cnt;
    c[cnt] = C;
    return cnt++;
}

void add1(int a, int b, int c)
{
    static int x, y;
    x = add(a, b, c);
    y = add(b, a, 0);
    opp[x] = y; opp[y] = x;
}

LL f[N];
int q[N];
bool vis[N];
int spfa()
{
    memset(vis, 0, sizeof vis);
    for(int i = 1; i <= n; i++) f[i] = INF;
    f[1] = 0;
    int l = 0, r = 0; q[l] = 1; vis[1] = true;
    while(l <= r)
    {
        int x = q[l % n];
        l++; vis[x] = false;
        for(int k = ind[x]; k != -1; k = nt[k])
        if(f[t[k]] > f[x] + c[k])
        {
            f[t[k]] = f[x] + c[k];
            if(!vis[t[k]])
            {
                r++;
                q[r % n] = t[k];
                vis[t[k]] = true;
            }
        }
    }
    return f[n];
}

int h[N];
bool bfs()
{
    int l = 0, r = 0;
    q[l] = 1;
    memset(h, 0, sizeof h);
    h[1] = 1;
    while(l <= r)
    {
        int x = q[l++];
        for(int k = ind[x]; k != -1; k = nt[k])
        if(!h[t[k]] && c[k] > 0)
        {
            h[t[k]] = h[x] + 1;
            q[++r] = t[k];
        }
    }
    return h[n] != 0;
}

int dfs(int x, int p)
{
    if(x == n) return p;
    bool flg = false;
    int tot = 0;
    for(int k = ind[x]; k != -1; k = nt[k])
    if(h[t[k]] == h[x] + 1)
    {
        int d = dfs(t[k], min(p, (int)c[k]));
        if(d)
        {
            p -= d;
            tot += d;
            c[k] -= d;
            flg = true;
            c[opp[k]] += d;
        }
    }
    return tot;
}

int dinic()
{
    int ans = 0, tmp;
    while(bfs())
    {
        //cout <<"H: ";for(int i = 1; i <= n; i++) cout << h[i] << " "; cout << endl;
        while(true)
        {
            int fw = dfs(1, INF);
            //cout << fw << endl;
            if(!fw) break;
            else ans += fw;
        }
    }
    //cout <<"H: ";for(int i = 1; i <= n; i++) cout << h[i] << " "; cout << endl;
    return ans;
}

int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        for(int i = 1; i <= n; i++) ind[i] = -1;
        for(int i = 0; i < m; i++) { scanf("%d%d%d", &op[i], &ed[i], &pt[i]); }
        cnt = 0;
        for(int i = 0; i < m; i++)
        {
            add(op[i], ed[i], pt[i]);
            add(ed[i], op[i], pt[i]);
        }
        spfa();
        for(int i = 1; i <= n; i++) ind[i] = -1;
        cnt = 0;
        for(int i = 0; i < m; i++)
        {
            if(f[op[i]] + pt[i] == f[ed[i]]) add1(op[i], ed[i], 1);
            swap(op[i], ed[i]);
            if(f[op[i]] + pt[i] == f[ed[i]]) add1(op[i], ed[i], 1);
        }
        printf("%d ", dinic());

        for(int i = 1; i <= n; i++) ind[i] = -1;
        cnt = 0;
        for(int i = 0; i < m; i++)
        {
            if(f[op[i]] + pt[i] == f[ed[i]]) add(op[i], ed[i], 1);
            swap(op[i], ed[i]);
            if(f[op[i]] + pt[i] == f[ed[i]]) add(op[i], ed[i], 1);
        }
        printf("%I64d\n", m - spfa());
    }
    return 0;
}
