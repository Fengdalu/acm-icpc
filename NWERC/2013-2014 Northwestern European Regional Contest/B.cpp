#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int e,v;
int s[460];
bool c[460][460];
int start,ended;
bool visit[460];
int maxinum;
bool check(int p)
{
    for(int i=1;i<=e;i++)
    {
        if(visit[i])
        {
            if(c[i][p]==0)
                return 0;
        }
    }
    return 1;
}
void dfs(int k,int sum)
{
    maxinum=max(maxinum,sum);
    for(int i=k;i<=e;i++)
    {
        if(visit[i])continue;
        if(check(i))
        {
            visit[i]=1;
            dfs(i,sum+s[i]);
            visit[i]=0;
        }
    }
}
int main()
{
    int i,j;
    while(scanf("%d%d",&e,&v)!=EOF)
    {
        maxinum=0;
        for(i=1;i<=e;i++)
            scanf("%d",&s[i]);
        memset(c,0,sizeof(c));
        memset(visit,0,sizeof(visit));
        for(i=1;i<=v;i++)
        {
            scanf("%d%d",&start,&ended);
            c[start][ended]=1;
            c[ended][start]=1;
        }
        dfs(1,0);
        printf("%d\n",maxinum);
    }
    return 0;
}