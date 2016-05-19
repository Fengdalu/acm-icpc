#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#define LL long long
#define rep(i, j) for (int i = 0; i <j; i++)
#define PB(i) push_back(i)
#define SZ size()
#define MOD 40000000
#define N 10
using namespace std;

struct obj
{
    int cnt;
    int val;
}f[MOD];
int cnt;
int k[N], p[N];
int n, m;
int mid;
LL ans;
LL find(int sum)
{
    int l = 0, r = cnt - 1;
    while(l < r - 1)
    {
        int mid = (l + r) >> 1;
        if (f[mid].val < sum) l = mid;
        else r = mid;
    }
    if (f[l].val == sum) return (long long)f[l].cnt;
    if (f[r].val == sum) return (long long)f[r].cnt;
    return 0;
}

void dfs(int d, int sum)
{
    if (d == mid) {cnt++; f[cnt].cnt = 1; f[cnt].val = sum; return;}
    for (int i = 1; i <= m; i++)
    {
        dfs(d + 1, sum + k[d] * pow(i, p[d]));
    }
}

void dfs1(int d, int sum)
{
    if (d == n) {ans = ans + find(-sum); return; }
    for (int i = 1; i <= m; i++)
    {
        dfs1(d + 1, sum + k[d] * pow(i, p[d]));
    }
}

int cmp(obj a, obj b)
{
    return a.val < b.val;
}
int main()
{
    cnt = 0;
    scanf("%d%d", &n, &m);
    rep(i, n) scanf("%d%d", &k[i], &p[i]);
    mid = n >> 1;
    cnt = -1;
    dfs(0, 0);
    cnt++;
    sort(f, f + cnt, cmp);
    int j = -1;
    rep(i, cnt)
    {
        if (j == -1 || f[j].val != f[i].val) f[++j] = f[i];
        else f[j].cnt++;
    }
    cnt = j + 1;
    ans = 0;
    dfs1(mid, 0);
    cout << ans <<endl;
}