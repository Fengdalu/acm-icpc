#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MOD (1 << 30)
#define LL long long
#define N 300000
#define INF 1e30

LL f[N][2];
char s[N];
int a[N];
int n;

int main()
{
    int CASE; scanf("%d", &CASE);
    int T = 0;
    while(CASE--)
    {
        scanf("%s", s);
        n = strlen(s);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
//        reverse(s, s + n);
//        reverse(a, a + n);

        for(int i = 0; i < n; i++) f[i][0] = f[i][1] = -INF;
        if(s[0] == '1') f[0][1] = a[0];
        else if(s[0] == '0') f[0][0] = 0;
        else { f[0][1] = a[0]; f[0][0] = 0; }

        for(int i = 1; i < n; i++)
        {
            if(s[i] == '1') f[i][1] = max(f[i - 1][0] + a[i], f[i - 1][1]);
            else if(s[i] == '0') f[i][0] = max(f[i - 1][1] + a[i], f[i - 1][0]);
            else
            {
                f[i][1] = max(f[i - 1][0] + a[i], f[i - 1][1]);
                f[i][0] = max(f[i - 1][1] + a[i], f[i - 1][0]);
            }
        }
        printf("Case #%d: %I64d\n", ++T, max(f[n - 1][0], f[n - 1][1]));
    }
    return 0;
}
