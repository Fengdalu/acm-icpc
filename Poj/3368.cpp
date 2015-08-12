#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;
#define AA first
#define BB second
#define N 100010

int f[N][100];
int a[N];
int pre[N];
int n, q;


int qpow(int x, int y)
{
    int ans = 1;
    while(y)
    {
        if(y & 1) ans *= x;
        x *= x; y /= 2;
    }
    return ans;
}

int main()
{
//    freopen("input.txt", "r", stdin);
    while(true)
    {
        scanf("%d", &n);
        if(n) scanf("%d", &q); else break;

        int p, x;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            a[i] = x;
            if(i == 0 || p != x) f[i][0] = 1;
            else f[i][0] = f[i - 1][0] + 1;
            p = x;
        }
//        for(int i = 0; i < n; i++) cout << f[i][0] << " "; cout << endl;
        for(int j = 0; j < 20; j++)
            for(int i = 0; i < n; i++)
            if(i + (1 << (j + 1)) <= n)
            {
                f[i][j + 1] = max(f[i][j], f[i + (1 << j)][j]);
            }

        pre[n - 1] = n - 1;
        for(int i = n - 2; i >= 0; i--)
        {
            if(a[i + 1] == a[i]) pre[i] = pre[i + 1]; else pre[i] = i;
        }
//        for(int i = 0; i < n; i++) cout << pre[i] << " "; cout << endl;
        int ans = 0;
        for(int i = 0; i < q; i++)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            l--; r--;
            ans = 0;
            if(pre[l] >= r) ans = max(ans, r - l + 1);
            else
            {
                ans = max(ans, pre[l] - l + 1);
                l = pre[l] + 1;
                int k = log2(r - l + 1);
//                cout << l << " " << r << endl;
                ans = max(ans, max(f[l][k], f[r - qpow(2, k) + 1][k]));
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
