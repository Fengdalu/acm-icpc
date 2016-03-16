#include<cstdio>
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
int n,m,l,r;
int num[101];
double mat[101][202];
void init()
{
    memset(mat,0,sizeof(mat));
    for(int siz=1;siz<=100;siz++)
    {
        mat[siz][siz%n]+=0.5;
        mat[siz][(n-siz%n)%n]+=0.5;
    }
}
void mult(double a[],double b[],double c[])
{
    double d[202];
    memset(d,0,sizeof(d));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            d[i]=d[i]+a[j]*b[(j-i+n)%n];
        }
    }
    for(int i=0;i<n;i++)
    c[i]=d[i];
}
void qpow(double x[],int k,double ans[])
{
    ans[0]=1.0;
    while(k)
    {
        if(k&1)
        mult(ans,x,ans);
        k>>=1;
        mult(x,x,x);
    }
}
double ans[202];
int main()
{
    while(1)
    {
        scanf("%d%d%d%d",&n,&m,&l,&r);
        memset(num,0,sizeof(num));
        if(n==0&&m==0&&l==0&&r==0)
            break;
        for(int i=0; i<m; i++)
        {
            int w;
            scanf("%d",&w);
            num[w]++;
        }
        init();
        memset(ans,0,sizeof(ans));
        ans[0]=1.0;
        for(int i=1;i<=100;i++)
        {
            if(num[i])
            {
                double K[202];
                memset(K,0,sizeof(K));
                qpow(mat[i],num[i],K);
                mult(K,ans,ans);
            }
        }
        double tans=0.0;
        for(int i=l-1;i<=r-1;i++)
        {
            tans=tans+ans[(n-i)%n];
        }
        printf("%.4f\n",tans);
    }
    return 0;
}
Distributed under GPLv3. | Project Homepage | Developer: 51isoft crccw | Current Style: Cerulean.

Select Style:   Fluid Width?
 