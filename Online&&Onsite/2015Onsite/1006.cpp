#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100010
int c[N], a[N], b[N];
int n;

int main()
{
    int _T; scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS++)
    {
        scanf("%d", &n);
        bool flg = false;
        for(int i = 1; i <= n; i++) scanf("%d", &c[i]);

        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);

        for(int i = 1; i <= n; i++) if(i == 1 || c[i - 1] < c[i]) a[i] = 1; else a[i] = a[i - 1] + 1;
        for(int i = n; i >= 1; i--) if(i == n || c[i] < c[i + 1]) b[i] = 1; else b[i] = b[i + 1] + 1;
        flg = flg | (a[n] == n) | (b[1] == n) | (b[2] == n - 1) | (a[n - 1] == n - 1);

        for(int i = 2; i < n; i++) if(a[i - 1] + b[i + 1] == n - 1 && c[i - 1] >= c[i + 1]) flg = true;

        reverse(c + 1, c + n + 1);

        for(int i = 1; i <= n; i++) if(i == 1 || c[i - 1] < c[i]) a[i] = 1; else a[i] = a[i - 1] + 1;
        for(int i = n; i >= 1; i--) if(i == n || c[i] < c[i + 1]) b[i] = 1; else b[i] = b[i + 1] + 1;
        flg = flg | (a[n] == n) | (b[1] == n) | (b[2] == n - 1) | (a[n - 1] == n - 1);
        for(int i = 2; i < n; i++) if(a[i - 1] + b[i + 1] == n - 1 && c[i - 1] >= c[i + 1]) flg = true;

        if(flg) printf("YES\n"); else printf("NO\n");
    }
    return 0;
}