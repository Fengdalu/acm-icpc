#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define PII pair<int, int>
#define AA first
#define BB second
#define SZ size()
#define PB(x) push_back(x)
#define SZ size()
#define CLR clear()

#define LL long long
#define N 16

LL f[25][1 << N];
LL pp[25];
char s[2 * N];
LL b, K;
int n;

LL trans(char s)
{
    if('0' <= s && s <= '9') return s - '0';
    return s - 'A' + 10;
}

int main()
{
   int _T; scanf("%d", &_T);
    for(int CAS = 1; CAS <= _T; CAS++)
    {
        scanf("%d%d", &b, &K);
        scanf("%s", s);
        n = strlen(s);

        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for(int i = 0; i < (1 << n); i++)
        {
            for(int j = 0; j < n; j++)
            if((i & (1 << j)) == 0)
            {
                for(int k = 0; k < K; k++)
                {
                    f[(b * k + trans(s[j])) % K][i | (1 << j)] += f[k][i];
                }
            }
        }
        printf("Case %d: %lld\n", CAS, f[0][(1 << n) - 1]);
    }
    return 0;
}
