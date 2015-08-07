#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <cmath>
using namespace std;
#define LL long long
#define N 200000
#define INF 0x3f3f3f
#define PII pair<int, int>
#define AA first
#define BB second
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool vis[N];
int q[N];
struct line
{
    int a; int b; int id;
    line(){}
    line(int a, int b): a(a), b(b) {}
    bool operator < (const line &t) const
    {
        if(b == t.b) return id < t.id;
        return b < t.b;
    }
};
set<line>s;
set<line>::iterator iter;
line f[N];
int n;

int cmp(const line &a, const line &b)
{
    if(a.a == b.a) return a.b < b.b;
    return a.a < b.a;
}

int main()
{
//    freopen("input.txt", "r", stdin);
    int T; scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &f[i].a);
        for(int i = 0; i < n; i++) scanf("%d", &f[i].b);
        for(int i = 0; i < n; i++) f[i].id = i;
        sort(f, f + n, cmp);

        int k = 0;
        int p = 0;
        int ans = 0;
        int l = 0;
        s.clear();
        memset(vis, 0, sizeof vis);
        while(true)
        {
            while(s.size() && s.begin()->b < p) s.erase(s.begin());
            while(k < n && f[k].a <= p) { s.insert(f[k]); k++; }
            iter = s.lower_bound(line(p, p));
            if(iter == s.end()) break;
            else
            {
                ans++;
                p++;
                q[l++] = iter->id;
                vis[iter->id] = true;
//                cout << iter->a << " " << iter->b << endl;
                s.erase(iter);
            }
        }
        for(int i = 0; i < n; i++) if(!vis[i]) q[l++] = i;
        printf("%d\n", ans);
        for(int i = 0; i < n; i++) printf("%d ", q[i] + 1);
        printf("\n");
    }
}
