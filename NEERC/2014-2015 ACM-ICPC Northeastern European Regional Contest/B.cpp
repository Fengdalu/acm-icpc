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

struct ggd
{
    int pos;
    int a,b;
    double g;
    double need;
}gd[100005];

bool cmp(ggd g1,ggd g2)
{
    return g1.a*g2.b>g1.b*g2.a;
}
bool cmp2(ggd g1,ggd g2)
{
    return g1.pos<g2.pos;
}
int main()
{
    freopen("burrito.in","r",stdin);
    freopen("burrito.out","w",stdout);
    int n;
    double A,B;
    scanf("%d%lf%lf",&n,&A,&B);
    for(int i=0;i<n;i++)
    {
        scanf("%lf%d%d",&gd[i].g,&gd[i].a,&gd[i].b);
        gd[i].pos=i;
        gd[i].need=0.0;
    }
    sort(gd,gd+n,cmp);
    double hasa=0.0;
    double hasb=0.0;
    for(int i=0;i<n;i++)
    {
        double tmp=MIN((B-hasb)/gd[i].b,gd[i].g);
        gd[i].need=tmp;
        hasb+=gd[i].need*gd[i].b;
        hasa+=gd[i].need*gd[i].a;
    }
    if(hasa<A)
        printf("-1 -1\n");
    else
    {
        sort(gd,gd+n,cmp2);
        printf("%f %f\n",hasa,hasb);
        for(int i=0;i<n;i++)
            printf("%f ",gd[i].need);
    }
    fclose(stdout);
    return 0;