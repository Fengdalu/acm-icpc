#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
using namespace std;
#define PQ priority_queue
#define INF 1e9

namespace G
{
    const int N = 1010;
    const int M = 5000;

    int f[N];
    int ind[N];
    int t[M], nt[M], c[M];
    int cnt;
    int ST;
    struct node
    {
        int x;
        node (int x): x(x) {}
        node (){}
        bool operator < (const node &b) const
        {
            if(f[x] == f[b.x]) return x < b.x;
            return f[x] < f[b.x];
        }
    };
    set<node>s;

    void init(int SS)
    {
        cnt = 0;
        memset(ind, -1, sizeof ind);
        for(int i = 1; i <= N; i++) f[i] = INF;
        ST = SS;
        f[SS] = 0;
        s.clear();
        for(int i = 1; i <= N; i++) s.insert(node(i));
    }

    void add(int x, int y, int cc)
    {
        t[cnt] = y;
        c[cnt] = cc;
        nt[cnt] = ind[x];
        ind[x] = cnt;
        cnt++;
    }

    void add2(int x, int y, int cc)
    {
        add(x, y, cc);
        add(y, x, cc);
    }

    int dijk(int target)
    {
        while(s.size())
        {
            int p = s.begin()->x;
            s.erase(s.begin());
            for(int k = ind[p]; k != -1; k = nt[k])
            if(f[p] + c[k] < f[t[k]])
            {
                s.erase(s.find(node(t[k])));
                f[t[k]] = f[p] + c[k];
                s.insert(node(t[k]));
            }
        }
        return f[target];
    }
}

int main()
{
    int m, n; scanf("%d%d", &m, &n);
    int x, y, z;
    G::init(1);
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        G::add2(x, y, z);
    }
    printf("%d\n", G::dijk(n));
    return 0;
}
