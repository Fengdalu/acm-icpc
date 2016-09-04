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
vector<long long>vec[11];
int siz[11];
int num[7]={2,3,5,7,11,13};
int val[1<<6];
void init(long long x,int i)
{
    long long t=1;
    while(t<=1e9)
    {
        vec[i].push_back(t);
        t*=x;
    }
}
int n;
int ans;
void dfs(int pos,long long tmp,int sig)
{
    if(tmp>n)
        return ;
    if(pos==6)
    {
        if(sig==1)
            return ;
        else
        {
            int N=n/tmp;
            for(int i=0;i<(1<<6);i++)
            {
                ans+=N/val[i];
            }
            return ;
        }
    }
    else
    {
        for(int i=0;i<siz[pos];i++)
        {
            dfs(pos+1,tmp*vec[pos][i],(sig+i)%2);
        }
    }
}
int main()
{
    init(2,0);
    init(3,1);
    init(5,2);
    init(7,3);
    init(11,4);
    init(13,5);
    for(int i=0;i<6;i++)
    {
        siz[i]=vec[i].size();
        //        printf("%d\n",siz[i]);
    }
    for(int i=0;i<(1<<6);i++)
    {
        int sig=1;
        int vl=1;
        for(int j=0;j<6;j++)
        {
            if(i&(1<<j))
            {
                vl*=num[j];
                sig*=-1;
            }
        }
        val[i]=vl*sig;
    }
    int T;
    scanf("%d",&T);
    while(T--)
    {
        ans=0;
        scanf("%d",&n);
        dfs(0,1,0);
        printf("%d\n",ans);
    }
    return 0;
}
