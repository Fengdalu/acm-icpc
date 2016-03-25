#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <bitset>
#include <vector>
int lowbit(int x) { return x & (-x); }
const int maxn = 50010;
int n;
struct bitnod{
    int c[maxn];
    void insert(int x, int v) {
        while(x <= n) {
            c[x] += v;
            x += lowbit(x);
        }
    }

    int cal(int x) {
        int ans = 0;
        while(x > 0) {
            ans += c[x];
            x -= lowbit(x);
        }
        return ans;
    }
    void init()
    {
        memset(c,0,sizeof c);
    }
}bit[55];
int sum[22];
int a[maxn];
void init()
{
    sum[0] = 0;
    for(int i = 1; i <= 10; i++) sum[i] = sum[i - 1] + i;
    for(int i = 0; i < 55; i++) bit[i].init();
}
void add(int l, int r, int k, int c)
{
    int t = l % k;
    int s = sum[k - 1] + t;
    bit[s].insert(l, c);
    bit[s].insert(r + 1, -c);
    //printf("ADD %d %d\n",s, bit[s].cal(2));
}
void query(int x)
{
    int ret = a[x];
    int s;
    for(int i = 1; i <= 10; i++)
    {
        s = sum[i - 1] + x % i;
        ret += bit[s].cal(x);
    }
    printf("%d\n",ret);
}
int main() {
    //freopen("A.in", "r", stdin);
    int l,r,q,k,c,x;
    while(~scanf("%d",&n))
    {
        init();
        for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
        scanf("%d",&q);
        for(int i = 0; i < q; i++)
        {
            scanf("%d",&x);
            if(x == 1)
            {
                scanf("%d%d%d%d",&l,&r,&k,&c);
                add(l,r,k,c);
            }
            if(x == 2)
            {
                scanf("%d",&k);
                query(k);
            }
        }
    }
    return 0;
}
