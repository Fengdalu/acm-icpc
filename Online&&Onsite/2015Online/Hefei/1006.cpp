#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define PII pair<int, int>
#define AA first
#define BB second

int a[200010];
int c[200010];
int f[200010];
int g[200010];
int H[200010];
int cnt;

int n, l;

int lowbit(int x) { return x & (-x); }

int qry(int p)
{
    int ans = 0;
    while(p > 0)
    {
        ans = max(a[p], ans);
        p -= lowbit(p);
    }
    return ans;
}

void insert(int p, int c)
{
    while(p <= n)
    {
        a[p] = max(a[p], c);
        p += lowbit(p);
    }
}


int main()
{
    //freopen("input.txt", "r", stdin);
    int _T; scanf("%d", &_T);
    for(int ii = 1; ii <= _T; ii++)
    {
        scanf("%d%d", &n, &l);
        for(int i = 0; i < n; i++) scanf("%d", &c[i]);
        if(n <= l) { printf("Case #%d: %d\n", ii, 0); continue; }
        memcpy(H, c, sizeof c);
        sort(H, H + n);
        cnt = unique(H, H + n) - H;
        for(int i = 0; i < n; i++) c[i] = lower_bound(H, H + cnt, c[i]) - H + 1;

        memset(a, 0, sizeof a);
        for(int i = 0; i < n; i++)
        {
            f[i] = qry(c[i] - 1) + 1;
            insert(c[i], f[i]);
        }
        for(int i = 0; i < n; i++) c[i] = cnt - c[i] + 1;
        memset(a, 0, sizeof a);
        for(int i = n - 1; i > -1; i--)
        {
            g[i] = qry(c[i] - 1) + 1;
            insert(c[i], g[i]);
        }
        for(int i = 0; i < n; i++) c[i] = cnt - c[i] + 1;
        int ans = g[l];
        memset(a, 0, sizeof a);
        for(int i = l; i < n; i++)
        {
            ans = max(ans, g[i] + qry(c[i] - 1));
            insert(c[i - l], f[i - l]);
        }
//        for(int i = 0; i < n; i++) cout << c[i] << " "; cout << endl;
//        for(int i = 0; i < n; i++) cout  << f[i] << " "; cout << endl;
//        for(int i = 0; i < n; i++) cout << g[i] << " "; cout << endl;

        ans = max(ans, f[n - l - 1]);
        printf("Case #%d: %d\n", ii, ans);
    }
    return 0;
}