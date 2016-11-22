#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define LL long long
#define pii pair<int,int>
const long long mod=1e9+7;
long long qpow(long long x,long long k)
{
    x%=mod;
    long long ans=1;
    while(k)
    {
        if(k&1)
            ans=ans*x%mod;
        k>>=1;
        x=x*x%mod;
    }
    return ans;
}
long long inv(long long x)
{
    return qpow(x,mod-2);
}
long long C(long long n,long long m)
{
    if(n<m)
        return 0;
    long long fz=1;
    long long fm=1;
    for(int i=0;i<m;i++)
    {
        fz=fz*((n-i)%mod)%mod;
        fm=fm*((m-i)%mod)%mod;
    }
    return fz*inv(fm)%mod;
}
int n;
long long s;
long long f[22];
int main()
{
    scanf("%d%I64d",&n,&s);
    for(int i=0;i<n;i++)
    {
        scanf("%I64d",&f[i]);
    }
    long long ans=0;
    for(int i=0;i<(1<<n);i++)
    {
        long long ns=s;
        long long sig=1;
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
            {
                sig*=-1;
                ns-=(f[j]+1);
            }
        }
//        printf("%d %I64d\n",i,ns);
        ans+=sig*C(ns+n-1,n-1);
        ans=(ans%mod+mod)%mod;
    }
    printf("%I64d\n",(ans%mod+mod)%mod);
    return 0;
}
