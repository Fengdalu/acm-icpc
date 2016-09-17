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
int n,W;
int w[105],v[105];
int tw[105],tv[105];
int tn;
pair<int,int>big[105];
int nbig;
pair<int,int>small[105];
int nsmall;
long long ans=0;
int answ=1000000000;
long long ansv=0;
int siz1;pair<int,long long>p1[1<<15];int tsiz1;
int siz2;pair<int,long long>p2[1<<20];int tsiz2;
long long inf=(1LL<<50);
void dfs(int pos,int res,int noww,long long nowv)
{
    if(pos==nbig||res==0)
    {
        if(noww>=answ&&nowv<=ansv)
            return ;
        for(int i=0;i<tsiz1;i++)
        {
            if(noww>W-p1[i].first);
            else
            {
                int res=W-noww-p1[i].first;
                long long av=nowv+p1[i].second;
                int pss=upper_bound(p2,p2+tsiz2,make_pair(res,inf))-p2-1;
                if(pss==-1);
                else
                    av+=p2[pss].second;
                if(av>=ans)
                {
                    ans=av;
                    answ=noww;
                    ansv=nowv;
                }
            }
        }
        return ;
    }
    if(noww>W-big[pos].first)return ;
    dfs(pos+1,res-1,noww+big[pos].first,nowv+big[pos].second);
    dfs(pos+1,res,noww,nowv);
}
int main()
{
    while(scanf("%d%d",&n,&W)!=EOF)
    {
        ans=0;
        tn=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&w[i],&v[i]);
            if(w[i]<W)
            {
                tw[tn]=w[i];
                tv[tn]=v[i];
                tn++;
            }
        }
        nbig=0;
        nsmall=0;
        for(int i=0; i<tn; i++)
        {
            if(3LL*tw[i]>W)
                big[nbig++]=make_pair(tw[i],tv[i]);
            else
                small[nsmall++]=make_pair(tw[i],tv[i]);
        }
        siz1=min(15,nsmall);
        tsiz1=(1<<siz1);
        for(int i=0;i<tsiz1;i++)
        {
            long long sumw=0;
            long long sumv=0;
            for(int j=0;j<siz1;j++)
            {
                if(i&(1<<j))
                {
                    sumw+=small[j].first;
                    sumv+=small[j].second;
                }
            }
            p1[i]=make_pair(sumw,sumv);
        }
        siz2=nsmall-siz1;
        tsiz2=(1<<siz2);
        for(int i=0;i<(1<<siz2);i++)
        {
            long long sumw=0;
            long long sumv=0;
            for(int j=0;j<siz1;j++)
            {
                if(i&(1<<j))
                {
                    sumw+=small[j].first;
                    sumv+=small[j].second;
                }
            }
            p2[i]=make_pair(sumw,sumv);
        }
        sort(p2,p2+tsiz2);
        for(int i=1;i<tsiz2;i++)
        {
            p2[i].second=max(p2[i].second,p2[i-1].second);
        }
        dfs(0,2,0,0);
        printf("%lld\n",ans);
    }
    return 0;
}
