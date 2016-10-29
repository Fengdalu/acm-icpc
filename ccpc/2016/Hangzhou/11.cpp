#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;
const int maxn=10000005;
bool notprime[maxn];
int prime[maxn],prinum;
void init()
{
    notprime[0]=notprime[1]=1;
    for(int i=2;i<maxn;i++)
    {
        if(!notprime[i])
        {
            prime[prinum++]=i;
        }
        for(int j=0;j<prinum&&i*prime[j]<maxn;j++)
        {
            notprime[i*prime[j]]=1;
            if(i%prime[j]==0)
            {
                break;
            }
        }
    }
}
const int MAXN=2010;
int uN,vN;//u,v数目
int g[MAXN][MAXN];
int linker[MAXN];
bool used[MAXN];
bool dfs(int u)//从左边开始找增广路径
{
    int v;
    for(v=0;v<vN;v++)//这个顶点编号从0开始，若要从1开始需要修改
      if(g[u][v]&&!used[v])
      {
          used[v]=true;
          if(linker[v]==-1||dfs(linker[v]))
          {//找增广路，反向
              linker[v]=u;
              return true;
          }
      }
    return false;//这个不要忘了，经常忘记这句
}
int hungary()
{
    int res=0;
    int u;
    memset(linker,-1,sizeof(linker));
    for(u=0;u<uN;u++)
    {
        memset(used,0,sizeof(used));
        if(dfs(u)) res++;
    }
    return res;
}
void run(int l,int n)
{
    memset(g,0,sizeof(g));
    uN=n;
    vN=n;
    for(int i=1;i<=n;i++)
    {
        int first=(l+i-1)/i*i;
        for(int j=first;j<=l+n-1;j+=i)
        {
            g[i-1][j-l]=1;
        }
    }
//    printf("(%d %d) (%d %d)\n",1,n,l,l+n-1);
//    puts("");
//    for(int i=0;i<n;i++)
//    {
//        for(int j=0;j<n;j++)
//        printf("%d ",g[i][j]);
//        puts("");
//    }
    int ans=hungary();
    if(ans==n)
        printf("Yes\n");
    else
        printf("No\n");
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int n,s;
        scanf("%d%d",&n,&s);

        printf("Case #%d: ",cas);

//        puts("");
//        run(s,n);
        if(s==0)
        {
            printf("Yes\n");
            continue;
        }
        if(s<=2000)
        {
            if(n<=2000)
            {
                run(s+1,n);
            }
            else
            if(n>=s+1)
                run(n+1,s);
            else
                run(s+1,n);
        }
        else if(n<=2000)
        {
            run(s+1,n);
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}

