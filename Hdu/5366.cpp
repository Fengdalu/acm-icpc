#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL long long


LL f[100];

void init()
{
    memset(f, 0, sizeof f);
    f[1] = 2; f[2] = 3; f[3] = 4;
    for(int i = 4; i < 90; i++) f[i] = f[i - 1] + f[i - 3];
}

int main()
{
    init();
    int n;
    while(~scanf("%d", &n))
    {
        printf("%I64d\n", f[n] - 1);
    }
    return 0;
}
