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
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) (a<0?-a:a)
#define SIZE 1000005
#define INF 0x7fffffff

struct ttt
{
    double tim;
    double dis;
}d[100005];
bool cmp(ttt a,ttt b)
{
    return a.tim<b.tim;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&d[i].tim,&d[i].dis);
        }
        sort(d,d+n,cmp);
        double ans=0.0;
        for(int i=1;i<n;i++)
        {
            double tmp=fabs(d[i].dis-d[i-1].dis)/(d[i].tim-d[i-1].tim);
            ans=MAX(ans,tmp);
        }

        printf("Case #%d: %.2f\n",cas,ans);
    }
    return 0;
}