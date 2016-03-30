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
#define eps 1e-7
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)<0?-(a):(a))

struct wire
{
    int s,rho,sigma;
    double w;
};
bool cmp(wire a,wire b)
{
    return a.s*a.rho<b.s*b.rho;
}
int d,n;
wire nod[100005];
bool check(double w)
{
    double h=0;
    double tw=w;
    for(int i=0;i<n;i++)
    {
        if(nod[i].w>tw)
        {
            h+=(nod[i].w-tw)/nod[i].rho/nod[i].s;
            tw=nod[i].w;
        }
    }
    return h>=d;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d",&d,&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&nod[i].s,&nod[i].rho,&nod[i].sigma);
        nod[i].w=nod[i].s*nod[i].sigma;
    }
    sort(nod,nod+n,cmp);
    double l=0.0,r=1e7;
    int tim=50;
    while(tim--)
    {
        double mid=(l+r)/2;
        if(check(mid))
            l=mid;
        else
            r=mid;
    }
    printf("%f\n",l);
    return 0;
}
