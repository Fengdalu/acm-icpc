#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
#define SIZE 1000005
bool notprime[SIZE];
int prime[SIZE];
int prinum;
void getprime()//prime
{
    notprime[0]=1;
    notprime[1]=1;
    for(int i=2; i<SIZE; i++)
    {
        if(notprime[i])
            continue;
        prime[prinum++]=i;
        for(int j=2*i; j<SIZE; j+=i)
            notprime[j]=1;
    }
}
long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
    return a/gcd(a,b)*b;
}
long long get(long long x)//get phi(x)
{
    long long res=1;
    for(int i=0; i<prinum; i++)
    {
        if(x%prime[i]==0)
        {
            res=lcm(res,prime[i]-1);
            x/=prime[i];
        }
    }
    if(x!=1)
        res=lcm(res,x-1);
    return res;
}

long long N;
long long qpow(long long x,long long k,long long mod)
{
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
bool check(long long k,long long mod)
{
    if(qpow(N,k,mod)==1)
        return true;
    return false;
}

long long getphi(long long x)//get phi(x)
{
    if(x==0)
        return 0;
    long long res=1,t=x;
    for(int i=0; i<prinum; i++)
    {
        if(prime[i]>t/prime[i])
            break;
        if(t%prime[i]==0)
        {
            res*=(prime[i]-1);
            t/=prime[i];
            while(t%prime[i]==0)
            {
                res*=prime[i];
                t/=prime[i];
            }
        }
    }
    if(t>1)
    {
        res*=(t-1);
    }
    return res;
}
int main()
{
    getprime();
    cin >> N ;
    //scanf("%lld",&N);
    if(N==2)
    {
        cout << 1 << endl;
        return 0;
    }
    long long phiN=getphi(N);
    if(gcd(N,phiN)==1)
    {
        long long phi2N1=get(N);
        long long phi2N=getphi(phiN);
        long long ans=(1LL<<60);
//        cout << phi2N << endl;
//        printf("%lld\n",phi2N);
        for(long long i=1; i*i<=phi2N; i++)
        {
//            printf("%d\n",i);
            if(phi2N%i==0)
            {
                if(check(i,phi2N1))
                    ans=min(ans,(long long)i);
                if(check(phi2N/i,phi2N1))
                    ans=min(ans,phi2N/i);
            }
//            cout << N << i << qpow(N,)¡¡<< endl;
        }
//        if(ans==(1LL<<60))
//            cout << -1 << endl;
//        else
            cout << ans << endl;
//        printf("%lld\n",ans);
    }
    else
    {
        cout << -1 << endl;
//        printf("-1");
    }
    return 0;
}
