#include <bits/stdc++.h>

using namespace std;

double qpow(double x,int k)
{
    double ans=1.0;
    while(k)
    {
        if(k&1)
            ans=ans*x;
        k>>=1;
        x=x*x;
    }
    return ans;
}
int n;
int cnt[15];
double p[15];
double pp[15];
double ans[15];
double pre[15];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)scanf("%d%lf",&cnt[i],&p[i]),pp[i]=p[i];
        if(n==1)
        {
            printf("1.000000\n");
            continue;
        }
        memset(pre,0,sizeof(pre));
        memset(ans,0,sizeof(ans));
        for(int i=1; i<=1000; i++)
        {
            for(int j=0; j<n; j++)
            {
                double val=1.0;
                for(int k=0; k<n; k++)
                {
                    if(j==k)continue;
                    val*=qpow(1-p[k],cnt[k]);
                }
                double now=val-pre[j];
                pre[j]=val;
                ans[j]+=now*(1.0-qpow(1.0-p[j],cnt[j]));
            }
            for(int j=0;j<n;j++)
                p[j]*=pp[j];
        }
        for(int i=0; i<n; i++)
        {
            if(i)
                printf(" ");
            printf("%f",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
