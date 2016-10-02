#include<stdio.h>
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
const long long mod=1e9+7;
const int maxn=2000005;
long long fac[maxn];
long long inv[maxn];
long long ifac[maxn];
void init()
{
    fac[0]=inv[0]=ifac[0]=1;
    fac[1]=inv[1]=ifac[1]=1;
    for(int i=2;i<maxn;i++)
    {
        fac[i]=fac[i-1]*i%mod;
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
        ifac[i]=ifac[i-1]*inv[i]%mod;
    }
}
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
//long long C(long long n,long long m,long long mod)
//{
//    if(m*2>n)
//        return C(n,n-m,mod);
//    long long fz=1;
//    long long fm=1;
//    for(long long i=1;i<=m;i++)
//    {
//        fz=fz*(n-i+1)%mod;
//        fm=fm*i%mod;
//    }
//    long long ans=fz*qpow(fm,mod-2,mod)%mod;
//    return ans;
//}
long long C(long long n,long long m,long long mod)
{
    return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int n;
vector<int>vec[100005];
map<pair<int,int> ,int>mp;
vector<int>son[100005];
int fa[100005];
void dfs(int rt)
{
    for(int i=0;i<vec[rt].size();i++)
    {
        int nxt=vec[rt][i];
        if(fa[rt]!=nxt)
        {
            fa[nxt]=rt;
            son[rt].push_back(nxt);
            dfs(nxt);
        }
    }
}
long long ans=1;
long long dfs2(int rt)
{
    long long sum=0;
    int tot=0;
    for(int i=0;i<son[rt].size();i++)
    {
        int nxt=son[rt][i];
        int cnt=mp[make_pair(rt,nxt)];
        tot+=cnt;
        sum+=cnt;
        ans*=C(dfs2(nxt)+cnt-1,cnt-1,mod);
        ans%=mod;
    }
    ans*=fac[tot];
    ans%=mod;
    return sum;
}
int main()
{
    init();
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        ans=ans*fac[c*2]%mod*ifac[c]%mod;
        vec[a].push_back(b);
        vec[b].push_back(a);
        mp[make_pair(a,b)]=c;
        mp[make_pair(b,a)]=c;
    }
    dfs(1);
    dfs2(1);
    printf("%lld\n",ans);
    return 0;
}
/*
4
1 2 2
2 3 1
2 4 1
*/
