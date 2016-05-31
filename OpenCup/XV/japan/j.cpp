#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long mod=1e9+7;
long long dp[2][90005][2];
long long qpow(long long x,int k)
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
int l[305];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&l[i]);
    int s;
    scanf("%d",&s);
    dp[0][0][0]=1;
    long long ans=0;
    int now=0,next=1;
    for(int i=0;i<n;i++)
    {
        memset(dp[next],0,sizeof(dp[next]));
        for(int j=0;j<=90000;j++)
        {
            for(int k=0;k<2;k++)
            {
                if(dp[now][j][k]==0)
                    continue;
                dp[next][j][k]+=dp[now][j][k];
                dp[next][j][k]%=mod;
                if(j+l[i]<=s){
                dp[next][j+l[i]][k^1]+=dp[now][j][k];
                dp[next][j+l[i]][k^1]%=mod;}
            }
        }
        swap(now,next);
    }
    for(int i=0;i<=s;i++)
    {
        ans=ans+(dp[now][i][0]-dp[now][i][1])*qpow(s-i,n)%mod;
    }
    printf("%I64d\n",(ans%mod+mod)%mod);
    return 0;
}
