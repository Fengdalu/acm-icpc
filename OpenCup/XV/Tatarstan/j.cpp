#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 1000005
long long n,k,m;
int num[SIZE];
bool notprime[SIZE];
int prime[SIZE],prinum;
void getprime()
{
    for(int i=2; i<SIZE; i++)
    {
        if(notprime[i])
            continue;
        prime[prinum++]=i;
        for(int j=2*i; j<SIZE; j+=i)
            notprime[j]=1;
    }
}
long long qpow(long long x,long long k,long long mod)
{
    long long ans=1;
    while(k)
    {
        if(k&1)
            ans=(ans*x)%mod;
        k>>=1;
        x=(x*x)%mod;
    }
    return ans;
}
long long solve(long long x,int sig)
{
    for(int i=0;i<prinum;i++)
    {
        if(prime[i]>x)
            break;
        long long tmp=0;
        long long tx=x;
        while(tx)
        {
            tmp+=tx/prime[i];
            tx/=prime[i];
        }
        num[prime[i]]+=tmp*sig;
    }
}
long long C(long long n,long long m,long long mod)
{
    if(m==0)
        return 1;
    if(n<m)
        return 0;
    memset(num,0,sizeof(num));
    solve(n,1);
    solve(k,-1);
    solve(n-k,-1);
    long long ans=1;
    for(int i=0;i<prinum;i++)
    {
        if(num[prime[i]]==0)
            continue;
        ans=ans*qpow(prime[i],num[prime[i]],mod)%mod;
    }
    return ans;
}
long long lucas(long long n,long long m,long long mod)
{
//    printf("%lld %lld\n",n,m);
    if(m>n)
        return 0;
    if(m==0)
        return 1;
    return C(n%mod,m%mod,mod)*lucas(n/mod,m/mod,mod)%mod;
}
int main()
{
    getprime();
    scanf("%lld%lld%lld",&n,&k,&m);
    printf("%lld\n",lucas(n,k,m));
    return 0;
}
