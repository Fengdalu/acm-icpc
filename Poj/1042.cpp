#include <iostream>
#include <cstdio>
#include <cstring>
#define rep(i, j) for (int i = 0; i < j; i++)
using namespace std;

int f[33], d[33];
int t[33];
int tmp[33];
int tt[33], att[33];

int main()
{
    while(true)
    {
        int h;
        int n;
        scanf("%d", &n);
        if (n == 0) break;
        scanf("%d", &h);
        h = h * 60;
        rep(i, n) scanf("%d", &f[i]);
        rep(i, n) scanf("%d", &d[i]);
        rep(i, n - 1) scanf("%d", &t[i]);
        int ans = -1;
        rep(i, n)
        {
            int l = h;
            int sum = 0;
            rep(j, i) l -= t[j] * 5;
            rep(j, n) tmp[j] = f[j];
            memset(tt, 0, sizeof tt);
            while(l > 0)
            {
                int pos = -1, m = 0;
                rep(j, i + 1)
                {
                    if (tmp[j] > m) {m = tmp[j]; pos = j;}
                }
                if (pos == -1) break;
                l -= 5;
                sum += tmp[pos];
                tmp[pos] -= d[pos];
                if (tmp[pos] < 0) tmp[pos] = 0;
                tt[pos] += 5;
            }
            if (l) tt[0] += l;
            if (sum > ans) 
            {
                rep(j, n) att[j] = tt[j]; ans = sum;
            }
        }
        rep(i, n) if(i != n - 1) printf("%d, ", att[i]); else printf("%d\n", att[i]);
        printf("Number of fish expected: %d\n", ans);
        putchar('\n');
    }
}