#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
#define LL long long
const int N = 100010;

int x[N * 2];
int a[N];
int b[N];
int f1[N * 2], f2[N * 2], f3[N * 2];
int n;
int nn;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
    for(int i = 0; i < n; i++)
    {
        x[i] = a[i]; x[i + n] = b[i];
    }
    sort(x, x + 2 * n);
    nn = unique(x, x + 2 * n) - x;
    for(int i = 0; i < n; i++)
    {
        a[i] = lower_bound(x, x + nn, a[i]) - x;
        b[i] = lower_bound(x, x + nn, b[i]) - x;
    }
    memset(f1, 0, sizeof f1);
    memset(f2, 0, sizeof f2);
    memset(f3, 0, sizeof f3);
    for(int i = 0; i < n; i++)
    {
        f1[a[i]]++;
        f2[b[i]]++;
        if(a[i] == b[i]) f3[a[i]]++;
    }
    int ans = 2 * n;
    int t = (n >> 1) + (n & 1);
    for(int i = 0; i < nn; i++)
    {
        int p = f1[i] - f3[i];
        int q = f2[i] - f3[i];
        int r = f3[i];
        if(p + r >= t) { ans = 0; break; }
        if(p + q + r >= t) ans = min(ans, t - p - r);
    }
    if(ans == n * 2) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
