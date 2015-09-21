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
#define N 20010
#define M 100010
#define LL long long
#define PII pair<int, int>
#define E pair< int, PII >
#define QQ pair< PII, LL >

int n, m, q;
E e[M];
int fa[N];
int c[N];
QQ Q[N];

int find(int x)
{
    if(fa[x] == x) return x;
    fa[x] = find(fa[x]);
    return fa[x];
}

int merge(int x, int y)
{
    int cnt = c[find(y)];
    fa[find(y)] = find(x);
    c[find(x)] += cnt;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T; scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &n, &m, &q);
        for(int i = 1; i <= n; i++) c[i] = 1;
        for(int i = 1; i <= n; i++) fa[i] = i;
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &e[i].BB.AA, &e[i].BB.BB, &e[i].AA);
        }
        sort(e, e + m);
        for(int i = 0; i < q; i++)
        {
            Q[i].AA.BB = i;
            scanf("%d", &Q[i].AA.AA);
            Q[i].BB = 0;
        }
        sort(Q, Q + q);

        int cnt = 0;
        for(int i = 0; i < m; i++)
        {
//            cout <<  e[i].BB.AA << " " << e[i].BB.BB << " " << e[i].AA << endl;;
            int x = find(e[i].BB.AA), y = find(e[i].BB.BB);
            LL ans = 0;
            if(x != y)
            {
                ans = (LL)c[x] * c[y];
                merge(x, y);
            }

            while(cnt < q)
            {
                if(e[i].AA <= Q[cnt].AA.AA) { Q[cnt].BB += ans * 2LL; break; }
                cnt++;
            }
        }
        for(int i = 1; i < q; i++) Q[i].BB += Q[i - 1].BB;
        for(int i = 0; i < q; i++) swap(Q[i].AA.BB, Q[i].AA.AA);
        sort(Q, Q + q);
        for(int i = 0; i < q; i++) printf("%I64d\n", Q[i].BB);
    }
    return 0;
}
