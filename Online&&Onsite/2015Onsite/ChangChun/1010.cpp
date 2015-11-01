#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 1010

int n, a[N];

int main()
{
    int _T; scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS++)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        reverse(a + 1, a + n + 1);
        int ans = 0;
        for(int k = 1; k <= n; k++)
            for(int i = 1; i <= n; i++)
            {
                if(a[i] < ans / 4 && a[k] < ans / 4) continue;
                for(int j = i + 1; j <= n; j++)
                if(k != i && k != j) ans = max(ans, (a[i] + a[j]) ^ a[k]);
            }
        printf("%d\n", ans);
    }
    return 0;
}