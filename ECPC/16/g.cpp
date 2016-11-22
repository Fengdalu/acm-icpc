#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8

long long mod=1e9+7;
long long S[1005][1005];
long long fac[1005];
void init()
{
    S[0][0]=1;
    for(int i=1;i<=1000;i++)
    {
        S[i][0]=0;
        S[i][i]=1;
        for(int j=1;j<i;j++)
        {
            S[i][j]=S[i-1][j-1]+S[i-1][j]*j;
            S[i][j]%=mod;
        }
    }
    fac[0]=1;
    for(int i=1;i<=1000;i++)
        fac[i]=fac[i-1]*i%mod;
}
int main()
{
    freopen("galactic.in","r",stdin);
    init();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if(m>n)
            printf("0\n");
        else
            printf("%I64d\n",S[n][m]*fac[m]%mod);
    }
    return 0;
}
