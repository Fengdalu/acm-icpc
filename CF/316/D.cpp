#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
#define N 500010
#define PII pair<int, int>
#define MP(x, y) make_pair(x, y)
#define M 1000000
#define AA first
#define BB second

namespace G
{
    const int MAXN = 500010;
    const int MAXM = 1000000;

    int ind[MAXN];
    int t[MAXM], nt[MAXM];
    int time[MAXN];
    int lb[MAXN], rb[MAXN];
    int cnt;
    int n;
    int q[MAXN];
    int dep[MAXN];

    void init()
    {
        memset(ind, -1, sizeof ind);
        cnt = 0;
    }

    void add(int a, int b)
    {
        t[cnt] = b;
        nt[cnt] = ind[a];
        ind[a] = cnt;
        cnt++;
    }

    PII RG(int x)
    {
        return MP(lb[x], rb[x]);
    }

    void dfs(int x)
    {
        time[x] = ++cnt;
        lb[x] = cnt;
        for(int k = ind[x]; k != -1; k = nt[k])
            dfs(t[k]);
        rb[x] = cnt;
    }

    void bfs()
    {
        int l = 0, r = 0;
        q[l] = 1;
        dep[l] = 1;
        while(l <= r)
        {
            int x = q[l];
            int d = dep[l];
            l++;
            for(int k = ind[x]; k != -1; k = nt[k])
            {
                ++r;
                q[r] = t[k];
                dep[r] = d + 1;
            }
        }
    }
}


typedef struct BIT
{

    int buf[N];
    void init()
    {
        memset(buf, 0, sizeof buf);
    }

    int lowbit(int x){ return x & (-x); }
    void add(int p, int c)
    {
        while(p < N)
        {
            buf[p] += c;
            p += lowbit(p);
        }
    }

    int cal(int p)
    {
        int ans = 0;
        while(p > 0)
        {
            ans += buf[p];
            p -= lowbit(p);
        }
        return ans;
    }

    int sub(int l, int r)
    {
        return cal(r) - cal(l - 1);
    }
};

BIT sum[27];

int n, Q;
char s[N];

typedef struct{
    int id;
    int p, d;
    bool ans;
} QES;
QES f[M];

int cmp1(QES a, QES b)
{
    return a.d < b.d;
}

int cmp2(QES a, QES b)
{
    return a.id < b.id;
}

int main()
{
//    freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &Q);
    G::init();
    for(int i = 2; i <= n; i++) { int x; scanf("%d", &x); G::add(x, i); }
    scanf("%s", s);
    G::cnt = 0;
    G::dfs(1);
    G::bfs();
    for(int i = 0; i < Q; i++)
    {
        f[i].id = i;
        f[i].ans = true;
        scanf("%d%d", &f[i].p, &f[i].d);
    }


    sort(f, f + Q, cmp1);

    int J = 0;
    int B = 0;
    for(int i = 0; i < 27; i++) sum[i].init();
    for(int i = 0; i < Q; i++)
    {
        while(J < n && G::dep[J] <= f[i].d) { sum[s[G::q[J] - 1] - 'a'].add(G::time[G::q[J]], 1); J++; }
        while(B < n && G::dep[B] < f[i].d) { sum[s[G::q[B] - 1] - 'a'].add(G::time[G::q[B]], -1); B++; }

        int l = G::lb[f[i].p], r = G::rb[f[i].p];
        int C = 0;
        for(int i = 0; i < 27; i++)
        {
            if(sum[i].sub(l, r) % 2 != 0) C++;
        }
        if(C > 1) f[i].ans = false;
        else f[i].ans = true;
    }
    sort(f, f + Q, cmp2);
    for(int i = 0; i < Q; i++)
        if(f[i].ans) printf("Yes\n"); else printf("No\n");
    return 0;
}
