#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdio>
using namespace std;

struct node
{
    int x, p, n;
}f[100010];
bool vis[100010];
int n;
long long ans;

int cmp(node a, node b)
{
    return a.x < b.x;
}
int cmp1(node a, node b)
{
    return a.n < b.n;
}
int main()
{
    scanf("%d", &n); for(int i = 0; i < n; i++) scanf("%d", &f[i].x);
    for(int i = 0; i < n; i++) f[i].n = i;
    sort(f, f + n, cmp);
    for(int i = 0; i < n; i++) f[i].p = i;
    sort(f, f + n, cmp1);
    memset(vis, 0, sizeof vis);
    ans = 0;
    int mm = 20000;
    for(int i = 0; i < n; i++) mm = min(mm, f[i].x);

    for(int i = 0; i < n; i++)
    if(!vis[i])
    {
        int m = 200000;
        int k = i, cc = 0;
        while(!vis[k])
        {
            vis[k] = true;
            m = min(f[k].x, m);
            cc++;
            ans += (long long)f[k].x;
            k = f[k].p;
        }
        //cout <<m + mm * cc << " " <<cc << endl;
        ans += min((long long)(m + mm * cc + mm), (long long)(cc - 2) * m);
    }
    cout << ans << endl;
    return 0;
}
