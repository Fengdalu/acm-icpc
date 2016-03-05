#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) (a<0?-a:a)
#define SIZE 100005
long long d,x,y;
long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    else
    {
        long long ret=exgcd(b,a%b,x,y);
        long long temp=x;
        x=y;
        y=temp-a/b*y;
        return ret;
    }
}
long long C(long long n,long long m,long long mod)
{
    long long fz=1;
    long long fm=1;
    for(long long i=1;i<=m;i++)
    {
        fz=fz*(n-i+1)%mod;
        fm=fm*i%mod;
    }
    exgcd(fm,mod,x,y);
    x=(x%mod+mod)%mod;
    long long ans=fz*x%mod;
    return ans;
}
long long lucas(long long n,long long m,long long mod)
{
    if(m>n)
    return 0;
    if(m==0)
    return 1;
    return C(n%mod,m%mod,mod)*lucas(n/mod,m/mod,mod)%mod;
}

long long qadd(long long a,long long b,long long mod)
{
    if(b==0)
    return 0;
    if(b%2==1)
    {
        long long tmp=qadd(a,b/2,mod);
        return ((tmp+tmp)%mod+a)%mod;
    }
    else
    {
        long long tmp=qadd(a,b/2,mod);
        return (tmp+tmp)%mod;
    }
}

long long china(long long n,long long a[],long long m[])
{
    long long M=1,d,y,x;
    long long ans=0;
    for(int i=0; i<n; i++)
        M*=m[i];
    for(int i=0; i<n; i++)
    {
        long long w=M/m[i];
        d=exgcd(m[i],w,x,y);

        long long tmp=m[i]/d;
        y=(y%tmp+tmp)%tmp;

        long long tmp1=qadd(y,w,M);
        long long tmp2=qadd(tmp1,a[i],M);

        ans=(ans+tmp2)%M;


//        printf("%I64d\n",ans);
    }
    return ans;
}

long long a[22];
long long mod[22];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long n,m,k;
        scanf("%I64d%I64d%I64d",&n,&m,&k);
        for(int i=0;i<k;i++)
        {
            scanf("%I64d",&mod[i]);
            a[i]=lucas(n,m,mod[i]);
        }
//        for(int i=0;i<k;i++)
//        {
//            printf("%I64d %I64d\n",mod[i],a[i]);
//        }
        long long ans=china(k,a,mod);
        printf("%I64d\n",ans);
    }
    return 0;
}
//100
//20 5 6
//3 5 7 11 13 17