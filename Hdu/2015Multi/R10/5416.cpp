#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
using namespace std;
#define N 100010
#define M 500010
#define NN 1000000
#define LL long long

int n, T, Q;
int cc[NN];
int ans[NN];

namespace G
{
    int ind[N];
    int t[M], nt[M], c[M];
    int q[N];
    bool vis[N];
    int cnt;
    int s;

    void init()
    {
        cnt = 0;
        memset(ind, -1, sizeof ind);
        memset(vis, 0, sizeof vis);
        s = 0;
    }
    void add(int a, int b, int C)
    {
        t[cnt] = b;
        c[cnt] = C;
        nt[cnt] = ind[a];
        ind[a] = cnt;
        cnt++;
    }


    void dfs(int x)
    {
        if(vis[x]) return;
        vis[x] = true;
        cc[s]++;
        for(int k = ind[x]; k != -1; k = nt[k])
        if(!vis[t[k]])
        {
            s ^= c[k];
            dfs(t[k]);
            s ^= c[k];
        }
    }
}





int main()
{
    //freopen("1011.in", "r", stdin);
    scanf("%d", &T);
    int TT = T;
    while(T--)
    {
        scanf("%d", &n);
        G::init();
        for(int i = 0; i < n - 1; i++)
        {
            int a, b, p; scanf("%d%d%d", &a, &b, &p);
            G::add(a, b, p); G::add(b, a, p);
        }
        memset(cc, 0, sizeof cc);
        G::dfs(1);

        int cnt1 = 0;
        for(int i = 0; i < NN; i++) if(cc[i] != 0) ans[cnt1++] = i;
//        for(int i = 0; i < cnt1; i++) cout << ans[i].A << " " << ans[i].B << endl;
        scanf("%d", &Q); int s;
        for(int i = 0; i < Q; i++)
        {
            scanf("%d", &s);
            LL sum = 0;
            for(int j = 0; j < cnt1; j++)
            {
                if(s != 0)sum += cc[ans[j]] * (LL)cc[s ^ ans[j]];
                else sum += (LL)cc[ans[j]] * (LL)(cc[ans[j]]);
                //else sum += (ULL)(cc[ans[j]] - 1) * (ULL)cc[s ^ ans[j]];
                //else sum += (ULL)ans[id].B * (ULL)(ans[j].B - 1);
            }
            if(s != 0)printf("%I64d\n", sum / 2LL);
            else printf("%I64d\n", (sum + n) / 2LL);
        }
    }
    return 0;
}
