#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 50000

struct node
{
    int x, y;
    int t;
    int p;
    node(int x, int y, int t, int p) : x(x), y(y), t(t), p(p) {}
    int operator < (node b) const
    {
        if(x == b.x && x == b.x) return t < b.t;
        return (x >= b.x && y >= b.y);
    }
};

set<node>s;
set<node>::iterator iter;
int ans[N], cnt;
bool vis[N];

int x[N], y[N];
int next[N];
int fa[N];

int main()
{
    int n;
    freopen("test.txt",  "r", stdin);
    while(~scanf("%d", &n))
    {
        s.clear();
        for(int i = 0; i < n; i++) scanf("%d", &x[i]);
        for(int i = 0; i < n; i++) scanf("%d", &y[i]);
        for(int i = 0; i < n; i++) y[i] *= -1;
        int t = 0;
        for(int i = 0; i < n; i++) fa[i] = -1;
        for(int i = 0; i < n; i++) next[i] = -1;
        for(int i = n - 1; i >= 0; i--)
        {
            node p(x[i], y[i], t, i);
            iter = s.lower_bound(p);
            if(iter == s.end()) next[i] = -1;
            else { next[i] = iter->p; fa[iter->p] = i; }
            s.insert(p);
            cout << p.x << " " << p.y << endl;
            t++;
        }
        for(iter = s.begin(); iter != s.end(); iter++)         cout << iter->x << " " << iter->y << endl; cout << endl;
        memset(vis, 0, sizeof vis);
        int ANS = 0, bg = n - 1;
        for(int i = 0; i < n; i++)
        if(!vis[i] && fa[i] == -1)
        {
            int tmp = 0;
            int k = i;
            while(k != -1)
            {
                vis[k] = true;
                tmp++;
                k = next[k];
            }
            if(tmp > ANS)
            {
                ANS = tmp;
                bg = i;
            }
        }
        int cnt = 0;
        while(bg != -1)
        {
            ans[cnt++] = bg;
            bg = next[bg];
        }
        printf("%d\n", ANS);
        for(int i = 0; i < cnt; i++) printf("%d ", ans[i] + 1);
        printf("\n");
    }

    return 0;
}
