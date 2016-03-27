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
#define eps 1e-12
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
vector <int>vec;
int siz;
int n,m;
long double qpow(long double x,long long k)
{
    long double ans=(long double)1.0;
    while(k)
    {
        if(k&1)
            ans=ans*x;
        k>>=1;
        x=x*x;
    }
    return ans;
}
long long cal(long long i,long long x)
{
    if(i==1)
        return x-1;
    if((1ULL<<i)>x)
        return 0;
    long long ans=(long long)(exp(log((double)x)/i)+eps);
    long double tans=ans;
    while(qpow(tans,i)<=(long double)x)tans++;
    return (long long)tans-2;
}
int num[55];
int sign[64];
bool check(long long x)
{
    long long ans=1;
    for(int i=1;i<64;i++)
    {
        if(sign[i]!=0)
        ans=ans+cal(i,x)*sign[i];
    }
    return ans>=n;
}
void dfs(int pos,int sig,long long LCM)
{
    if(LCM>=64)
        return ;
    if(pos==siz)
    {
        sign[LCM]+=sig;
        return ;
    }
    dfs(pos+1,sig,LCM);
    if(LCM==0)
        LCM=1;
    dfs(pos+1,sig*-1,lcm(LCM,vec[pos]));
}
int main()
{
//    printf("%I64d\n",cal(3,8));
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(sign,0,sizeof(sign));
        vec.clear();
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d",&num[i]);
        }
        sort(num,num+m);
        for(int i=0;i<m;i++)
        {
            int flag=0;
            for(int j=0;j<vec.size();j++)
            {
                if(num[i]%vec[j]==0)
                {
                    flag=1;
                    break;
                }
            }
            if(!flag)
                vec.push_back(num[i]);
        }
        siz=vec.size();
        dfs(0,-1,0);
//        for(int i=1;i<64;i++)
//            printf("%d %d\n",i,sign[i]);
        long long l=1,r=1e17;
        while(l<r)
        {
            long long mid=(l+r)/2;
            if(check(mid))
                r=mid;
            else
                l=mid+1;
        }
        printf("%lld\n",r);
    }
    return 0;
}

