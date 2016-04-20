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
#define SIZE 22
int n;
int p[200005];
double cal(double bpos)
{
    double ans=0.0;
    for(int i=0;i<n;i++)
    {
        ans=ans+sqrt(1+(bpos+i-p[i])*(bpos+i-p[i]));
    }
    return ans;
}
int main()
{
    freopen("make-a-row.in","r",stdin);
    freopen("make-a-row.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<2*n;i++)
        scanf("%d",&p[i]);
    n*=2;
    sort(p,p+n);
    double l=-1e9,r=1e9;
    int tim=100;
    while(tim--)
    {
        double mid=(l+r)/2.0;
        double midmid=(mid+r)/2.0;
        double vm=cal(mid);
        double vmm=cal(midmid);
        if(vm<vmm)
            r=midmid;
        else
            l=mid;
    }
    printf("%.12f\n",cal(l));
    return 0;
}
