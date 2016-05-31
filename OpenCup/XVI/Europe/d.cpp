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
long long mod=1e9+7;
int n,m;
char str[300005];
long long qpow(long long x,int k,long long mod)
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
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s",str);
    int num=0;
    int res=0;
    for(int i=0;i<n;i++)
    {
        res=(res*10+str[i]-'0')%m;
        if(res==0)
            num++;
    }
    if(res!=0)
        printf("0\n");
    else
    {
        printf("%I64d\n",qpow(2,num-1,mod));
    }
    return 0;
}
