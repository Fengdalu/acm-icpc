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
#define eps 1e-8
int vis[22];
int typ[22];
int num[22];
int dp[2][1<<16][16];
int n;
int _inf=-2e9;
int ones[1<<16];
void init()
{
    for(int i=0;i<(1<<16);i++)
    {
        int t=i;
        while(t)
        {
            ones[i]+=t%2;
            t/=2;
        }
    }
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        memset(vis,-1,sizeof(vis));
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&num[i]);
            scanf("%d",&typ[i]);
            if(typ[i]!=-1)
                vis[typ[i]]=i;
        }
        for(int i=0; i<2; i++)for(int j=0; j<(1<<n); j++)for(int k=0; k<n; k++)
            dp[i][j][k]=_inf;
        if(vis[0]==-1)
        {
            for(int i=0; i<n; i++)if(typ[i]==-1)
            {
                dp[0][1<<i][i]=0;
            }
        }
        else
        {
            dp[0][1<<(vis[0])][vis[0]]=0;
        }
        int now=0,next=1;
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<(1<<n); j++)for(int k=0; k<n; k++)
                dp[next][j][k]=_inf;
            for(int state=0; state<(1<<n); state++)
            {
                if(ones[state]!=i)
                    continue;
                if(vis[i]!=-1)
                    if(state&(1<<vis[i]))
                        continue;
                for(int tail=0; tail<n; tail++)
                {
                    if(dp[now][state][tail]==_inf)
                        continue;
                    if(vis[i]==-1)
                    {
                        for(int j=0; j<n; j++)
                        {
                            if((1<<j)&state)
                                continue;
                            if(typ[j]!=-1)
                                continue;
                            dp[next][state|(1<<j)][j]=max(dp[next][state|(1<<j)][j],dp[now][state][tail]+num[tail]*num[j]);
                        }
                    }
                    else
                    {
                        int j=vis[i];
                        dp[next][state|(1<<j)][j]=max(dp[next][state|(1<<j)][j],dp[now][state][tail]+num[tail]*num[j]);
                    }
                }
            }
            swap(now,next);
        }
        int ans=_inf;
        for(int i=0; i<n; i++)
        {
            ans=max(ans,dp[now][(1<<n)-1][i]);
        }
        printf("Case #%d:\n",cas);
        printf("%d\n",ans);
    }
    return 0;
}
