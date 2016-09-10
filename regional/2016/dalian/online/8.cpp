#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int n;
int h[100005];
int dp[100005][20];
int mm[100005];
void init()
{
    mm[0] = -1;
    for(int i = 1; i < 100005; i++)
    {
        if((i & (i - 1)) == 0) mm[i] = mm[i - 1] + 1;
        else mm[i] = mm[i - 1];
    }
    for(int i=0; i<20; i++)
        for(int j=0; j<n; j++)
        {
            if(i==0)
                dp[j][i]=h[j];
            else if(j+(1<<i)-1<n)
            {
                dp[j][i]=min(dp[j][i-1],dp[j+(1<<(i-1))][i-1]);
            }
        }
}
int query(int l,int r)
{
    int two=mm[r-l+1];
    return min(dp[l][two],dp[r-(1<<two)+1][two]);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)scanf("%d",&h[i]);
        init();
        int q;
        scanf("%d",&q);
        for(int i=0; i<q; i++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            l--;
            r--;
            int nowv=h[l];
            int pr=l+1;
            while(pr<=r)
            {
                int L=pr,R=r+1;
                bool ok=false;
                while(L<R)
                {
                    int mid=(L+R)/2;
                    if(query(pr,mid)<=nowv)
                    {
                        ok=true;
                        R=mid;
                    }
                    else
                        L=mid+1;
                }
                if(ok)
                {
                    nowv=nowv%h[L];
                    pr=L+1;
                }
                else
                    break;
            }
            printf("%d\n",nowv);
        }
    }
    return 0;
}
