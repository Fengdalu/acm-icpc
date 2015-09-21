#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;
#define AA first
#define BB second
#define N 10010
#define M 200010
#define LL long long

int n, m;
int ind[N], in[N], q[N], fa[N], c[N], v[N];
int t[M], nt[M];
LL ans;
int cnt;

void add(int a, int b)
{
    t[cnt] = b;
    nt[cnt] = ind[a];
    ind[a] = cnt;
    cnt++;
    in[b]++;
}

void add2(int a, int b)
{
    add(a, b); add(b, a);
}

void top()
{
    int l = 0, r = -1;
    memset(c, 0, sizeof c);
    for(int i = 1; i <= n; i++) if(in[i] == 1) { q[++r] = i; c[i] = 1; }
    while(l <= r)
    {
        int x = q[l++];
        for(int k = ind[x]; k != -1; k = nt[k])
        {
            in[t[k]]--;
            if(in[t[k]] == 1 && c[t[k]] == 0)
            {
                q[++r] = t[k];
                c[t[k]] = 1;
            }
        }
    }
}

int find(int x)
{
    if(fa[x] == x) return x;
    fa[x] = find(fa[x]);
    return fa[x];
}

void cal()
{
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int x = 1; x <= n; x++)
    if(c[x] == 0)
    {
        for(int k = ind[x]; k != -1; k = nt[k])
        if(c[t[k]] == 0)
        {
            fa[find(x)] = fa[find(t[k])];
        }
    }
    memset(c, 0, sizeof c);
    for(int i = 1; i <= n; i++) c[find(i)]++;
    //for(int i = 1; i <= n; i++) cout << c[find(i)] << " "; cout << endl;
    ans = 0;
    for(int i = 1; i <= n; i++) if(c[find(i)] > 1 && c[find(i)] % 2 == 1) ans += (LL)v[i];
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T; scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) scanf("%d", &v[i]);
        memset(ind, -1, sizeof ind);
        memset(in, 0, sizeof in);
        cnt = 0;
        for(int i = 0; i < m; i++)
        {
            int x, y; scanf("%d%d", &x, &y);
            add2(x, y);
        }
        top();
        cal();
        printf("%I64d\n", ans);
    }
    return 0;
}
