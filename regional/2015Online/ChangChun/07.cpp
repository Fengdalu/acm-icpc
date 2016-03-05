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
#define N 10010

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
    //freopen("input.txt", "r", stdin);
    int T; scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        memset(f, 0, sizeof f);
        for(int i = 1; i <= n; i++) scanf("%d", &f[i][0]);


        int p, x;
        for(int j = 0; j < 20; j++)
            for(int i = 1; i <= n; i++)
            if(i + (1 << (j + 1)) <= n + 1)
            {
                f[i][j + 1] = max(f[i][j], f[i + (1 << j)][j]);
            }

        scanf("%d", &q);
        for(int i = 0; i < q; i++)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            int ans = 0;
                int k = log2(r - l + 1);
//                cout << l << " " << r << endl;
                ans = max(ans, max(f[l][k], f[r - qpow(2, k) + 1][k]));
            printf("%d\n", ans);
        }
    }
    return 0;
}