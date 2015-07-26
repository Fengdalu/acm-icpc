#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int T; scanf("%d", &T);
    long long n, m, p, q;
    while(T--)
    {
        scanf("%I64d%I64d%I64d%I64d", &n, &m, &p, &q);
        long long ans = min(n * p, p * (n % m) + q * (n / m));
        ans = min(ans, q * (n / m) + q * (n % m != 0));
        printf("%I64d\n", ans);
    }
    return 0;
}
