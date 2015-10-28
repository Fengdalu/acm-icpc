#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL long long
LL C[51][51];
LL fact[51];

int init()
{
    for(int i = 1; i <= 50; i++)
        for(int j = 0; j <= i; j++)
            if(i == 1) C[i][j] = 1;
            else if(j == 0) C[i][j] = 1;
            else C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    for(int i = 0; i <= 50; i++)
        if(!i) fact[i] = 1;
        else fact[i] = fact[i - 1] * (LL)i;
}

int main()
{
    int _T; scanf("%d", &_T);
    init();
    for(int CAS = 1; CAS <= _T; CAS++)
    {
        int n, k; scanf("%d%d", &n, &k);
        if(k > n) printf("Case %d: 0\n", CAS);
        else if(k == n) printf("Case %d: %lld\n", CAS, fact[n]);
        else printf("Case %d: %lld\n", CAS, C[n][k] * C[n][k] * fact[k]);
    }
}
