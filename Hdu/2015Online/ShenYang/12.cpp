#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define LL long long
#define N 5000010
LL t[N];
LL a, b;
int n;

int main()
{
    int _T;  scanf("%d", &_T);
    for(int ii = 1; ii <= _T; ii++)
    {
        scanf("%d%I64d%I64d", &n, &a, &b);
        for(int i = 0; i < n; i++) scanf("%I64d", &t[i]);
        sort(t, t + n);
        LL tmp;
        LL ans;
        for(int i = 0; i < n; i++)
        {
            tmp = a * t[i] * t[i];
            if(i == 0)
            {
                ans = max(tmp + b * t[1], tmp + b * t[n - 1]);
            }
            else if(i == n - 1)
            {
                ans = max(ans, tmp + b * t[n - 2]);
                ans = max(ans, tmp + b * t[0]);
            }
            else
            {
                ans = max(ans, tmp + b * t[0]);
                ans = max(ans, tmp + b * t[n - 1]);
            }
        }
        printf("Case #%d: %I64d\n", ii, ans);
    }
}