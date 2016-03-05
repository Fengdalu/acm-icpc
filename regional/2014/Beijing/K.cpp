#include <iostream>
#include <cstdio>
using namespace std;

int a[1000100];
int n;

int main()
{
    int T; scanf("%d", &T);
    for(int ii = 1; ii <= T; ii++)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        int ans = 0;
        int MIN = n + 1;
        for(int i = n - 1; i >= 0; i--)
        {
            if(a[i] > MIN)
            {
                ans ++;
            }
            else
            {
                MIN = a[i];
            }
        }
        printf("Case #%d: %d\n", ii, ans);
    }
    return 0;
}