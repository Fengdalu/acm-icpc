#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
#define LL long long
#define N 200010

struct seg
{
    LL l, r;
    LL id;
    seg(){}
    seg(LL l, LL r): l(l), r(r){}
    bool operator < (const seg &s) const
    {
        return r == s.r ? l < s.r : r < s.r;
    }
}s[N];
struct node
{
    LL c, id;
    node(){}
    node(LL c, LL id): c(c), id(id){}
    int operator < (const node &a) const
    {
        return c == a.c ? id < a.id : c < a.c;
    }
};

LL l[N], r[N];
LL ans[N];
set<node>f;
set<node>::iterator iter;

int main()
{
    int n, m; scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        scanf("%I64d%I64d", &l[i], &r[i]);
    }
    for(int i = 0; i < n - 1; i++)
    {
        s[i].l = l[i + 1] - r[i];
        s[i].r = r[i + 1] - l[i];
        s[i].id = i;
    }
    sort(s, s + n - 1);
    f.clear();
    for(int i = 0; i < m; i++)
    {
        LL tmp;
        scanf("%I64d", &tmp);
        f.insert(node(tmp, i));
    }
    bool flg = true;
    for(int i = 0; i < n - 1; i++)
    {
        iter = f.lower_bound(node(s[i].l, -1));
        if(iter == f.end() || iter->c > s[i].r) { flg = false; break; }
        ans[s[i].id] = iter->id;
        f.erase(iter);
    }
    if(!flg) { printf("No\n"); }
    else { printf("Yes\n"); for(int i = 0; i < n - 1; i++){ printf("%I64d ", ans[i] + 1); } }
    return 0;
}
