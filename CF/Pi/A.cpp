#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;


int f[200000];
int main()
{
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &f[i]);
    printf("%d %d\n", f[1] - f[0], f[n - 1] - f[0]);
    for(int i = 1; i < n - 1; i++)
    {
        int a, b;
        a = min(f[i] - f[i - 1], f[i + 1] - f[i]);
        b = max(f[i] - f[0], f[n - 1] - f[i]);
        printf("%d %d\n", a, b);
    }
    printf("%d %d\n", f[n - 1] - f[n - 2], f[n - 1] - f[0]);
    return 0;
}
