#include <iostream>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <queue>
#include <set>
//#include<pair>
#include<map>
using namespace std;
int dp[2][1000005];
int n;
int a[1000005];
int b[1000005];
int p,q;
int ans[1000005];
bitset <101>d[1000005];
//map <pair<int,int>,bool>mma;
//map <pair<int,int>,bool>mmb;
int main()
{
    scanf("%d",&n);
    scanf("%d",&p);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    scanf("%d",&q);
    for(int i=0; i<n; i++)
        scanf("%d",&b[i]);
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    int now=0,next=1;
    for(int i=0; i<p; i++)
        d[i].reset();
    for(int i=0; i<n; i++)
    {
//        printf("%d\n",i);
        memset(dp[next],-1,sizeof(dp[next]));
        for(int j=p; j>=0; j--)
        {
            if(dp[now][j]==-1)
                continue;
            dp[next][j]=dp[now][j];
            int x=min(p,j+a[i]);
            int y=min(q,dp[now][j]+b[i]);
//            printf("\t%d %d %d\n",a[i],x,y);
            if(y<dp[next][x]||dp[next][x]==-1)
            {
                dp[next][x]=y;
                d[x]=d[j];
                d[x][i]=1;
            }
        }
        swap(now,next);
//        printf("\t%d\n",dp[now][p]);
        if(dp[now][p]!=-1&&dp[now][p]<q)
        {
            printf("NO\n");
            for(int k=0; k<n; k++)
                printf("%d",d[p][k]?1:0);
            printf("\n");
            return 0;
        }

    }
//    printf("!\n");
//    if(pos==-1)
    swap(a,b);
    swap(p,q);
//        mm.clear();
    for(int i=0; i<p; i++)
        d[i].reset();
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    now=0,next=1;
    for(int i=0; i<n; i++)
    {
//        printf("%d\n",i);
        memset(dp[next],-1,sizeof(dp[next]));
        for(int j=p-1; j>=0; j--)
        {
            if(dp[now][j]==-1)
                continue;
            dp[next][j]=dp[now][j];
            int x=min(p,j+a[i]);
            int y=min(q,dp[now][j]+b[i]);
            if(y<dp[next][x]||dp[next][x]==-1)
            {
                dp[next][x]=y;
                d[x]=d[j];
                d[x][i]=1;
            }
        }

        swap(now,next);
        if(dp[now][p]!=-1&&dp[now][p]<q)
        {
            printf("NO\n");
            for(int k=0; k<n; k++)
                printf("%d",d[p][k]?1:0);
            printf("\n");
            return 0;
        }

    }
    printf("YES\n");
    return 0;
}