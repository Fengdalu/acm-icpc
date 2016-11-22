#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define ABS(a) (a<0?-a:a)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define zero(x) (((x)>0?(x):-(x))<eps)
#define sign(x) ((x)<-eps?-1:((x)>eps))
#define dbg(x) cerr << #x << " = " << x << endl;

struct lcl
{
    int pos;
    int len;
    int num[1005];
} l[1005];
bool cmp1(lcl a,lcl b)
{
    return a.len<b.len;
}
bool cmp2(lcl a,lcl b)
{
    return a.pos<b.pos;
}
int main()
{
    freopen("dice.in","r",stdin);
    freopen("dice.out","w",stdout);
    int n;
    scanf("%d",&n);
    int t=0;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&l[i].len);
        t+=l[i].len;
        l[i].pos=i;
    }
    sort(l,l+n,cmp1);
    double ans=0.0;
    for(int i=0;i<n;i++)
    {
        double tmp=0.0;
        for(int j=0;j<l[i].len;j++)
        {
            l[i].num[j]=t;
            tmp+=t;
            t--;
        }
        ans=ans+tmp/l[i].len;
    }
    sort(l,l+n,cmp2);
    printf("%f\n",ans);
    for(int i=0;i<n;i++)
    {
        sort(l[i].num,l[i].num+l[i].len);
        for(int j=0;j<l[i].len;j++)
            printf("%d ",l[i].num[j]);
        printf("\n");
    }

    return 0;
}