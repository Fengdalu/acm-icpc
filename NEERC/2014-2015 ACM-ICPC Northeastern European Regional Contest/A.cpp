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
#define eps 1e-10
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define zero(x) ((fabs(x))<eps)
#define sign(x) ((x)<-eps?-1:((x)>eps))

int main()
{
    freopen("alter.in","r",stdin);
    freopen("alter.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    if(n%2==0&&m%2==0)
    {
        printf("%d\n",n/2+m/2);
        for(int i=1;i<=n;i+=2)
        {
            printf("%d %d %d %d\n",i,1,i,m);
        }
        for(int j=2;j<=m;j+=2)
        {
            printf("%d %d %d %d\n",1,j,n,j);
        }
    }
    else if(n%2==0&&m%2==1)
    {
        printf("%d\n",n/2+m/2);
        for(int j=2;j<=m;j+=2)
        {
            printf("%d %d %d %d\n",1,j,n,j);
        }
        for(int i=1;i<=n;i+=2)
        {
            printf("%d %d %d %d\n",i,1,i,m);
        }
    }
    else if(n%2==1&&m%2==0)
    {
        printf("%d\n",n/2+m/2);
        for(int i=2;i<=n;i+=2)
        {
            printf("%d %d %d %d\n",i,1,i,m);
        }
        for(int j=1;j<=m;j+=2)
        {
            printf("%d %d %d %d\n",1,j,n,j);
        }
    }
    else
    {
        printf("%d\n",n/2+m/2);
        for(int i=2;i<=n;i+=2)
        {
            printf("%d %d %d %d\n",i,1,i,m);
        }
        for(int j=2;j<=m;j+=2)
        {
            printf("%d %d %d %d\n",1,j,n,j);
        }
    }
    fclose(stdout);
    return 0;
}