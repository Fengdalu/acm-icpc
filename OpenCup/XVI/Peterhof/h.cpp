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
bool zero(double x)
{
    if(fabs(x)<=eps)
        return true;
    return false;
}
int sign(double x)
{
    if(zero(x))
        return 0;
    if(x>0)
        return 1;
    return -1;
}
int n;
struct seg
{
    int l,r;
};
bool cmp(seg a,seg b)
{
    if(a.l==b.l)
        return a.r<b.r;
    return a.l<b.l;
}
seg s[55];
int p1,p2;
double F(double x)
{
    double ans=x/(s[p1].r-s[p1].l);
    ans=ans*(s[p2].r-max(x,(double)s[p2].l))/(s[p2].r-s[p2].l);
    for(int i=0; i<n; i++)
    {
        if(i==p1||i==p2)
            continue;
        if(sign(x-s[i].r)>=0)
            ;
        else
            ans=ans*(x-s[i].l)/(s[i].r-s[i].l);
    }
    return ans;
}
double simpson(double L,double R)
{
    double mid=(L+R)/2.0;
    return (F(L)+4.0*F(mid)+F(R))*(R-L)/6.0;
}
double INT(double L,double R)
{
    double mid=(L+R)/2.0;
    double sum=simpson(L,R);
    double sum1=simpson(L,mid);
    double sum2=simpson(mid,R);
    if(zero(sum-sum1-sum2))
        return sum;
    else
        return INT(L,mid)+INT(mid,R);
}
bool check(int l,int r)
{
    for(int i=0;i<n;i++)
    {
        if(i==p1||i==p2)
            continue;
        if(s[i].l>r)
            return true;
    }
    return false;
}
int main()
{
//    printf("%f\n",7/36.0);
    freopen("secondmax.in","r",stdin);
    freopen("secondmax.out","w",stdout);

    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d%d",&s[i].l,&s[i].r);
    }
    sort(s,s+n,cmp);
//    printf("\n");
//    for(int i=0;i<n;i++)
//    {
//        printf("%d %d\n",s[i].l,s[i].r);
//    }
    int L=s[n-2].l;
    double ans=0.0;
    for(int i=0; i<n; i++)
    {
        if(s[i].r<L)
            continue;
        for(int j=0; j<n; j++)
        {
            if(i==j)
                continue;
            if(s[j].r<L)
                continue;
            p1=i;
            p2=j;
//            ans=ans+INT(max(L,s[i].l),min(s[i].r,s[j].r));
//            int L1,R1,L2,R2;
//            L1=max(L,s[i].l);
//            R1=min(s[i].r,s[j].l);
//            R1=max(L1,R1);
//            L2=R1;
//            R2=min(s[i].r,s[j].r);
//            R2=min(L2,R2);
            int tl=-1e9;
            for(int k=0;k<n;k++)
            {
                if(k==j)
                    continue;
                tl=max(tl,s[k].l);
            }
            int tr=min(s[i].r,s[j].r);

            if(tr<tl||check(tl,tr))
                continue;
            double d=(tr-tl)/50.0;
            for(int k=0;k<50;k++)
                ans=ans+INT(tl+k*d,tl+(k+1)*d);
//            ans=ans+INT(tl,tr);
//            ans=ans+INT(L1,R1)+INT(L2,R2);
//            printf("%d %d\n",i,j);
//            printf("\t%f \n",INT(tl,tr));
//            printf("\t%d %d %f\n",tl,tr,ans);
//            printf("%f %f\n",INT(L1,R1),INT(L2,R2));
//            printf(" %d %d %d %d\n\t%f\n",L1,R1,L2,R2,ans);
//            ans=ans+INT(max(L,s[i].l),min(s[i].r,s[j].r))/(s[i].r-s[i].l);
//            printf("%d %d\n",max(L,s[i].l),min(s[i].r,s[j].r));
//          printf("%d %d %f %f\n",i,j,ans,INT(max(L,s[i].l),min(s[i].r,s[j].r))/(s[i].r-s[i].l));
        }
    }
    printf("%.10f\n",ans);
    return 0;
}

/**
2
1 3
2 5
0 1 1.777778 1.777778
1 0 1.972222 0.194444
1.972222
*/

/**
5
2 9
7 13
3 11
-1 5
-2 2

7.4206349197
*/

/**
8
-12 -9
-10 -8
-7 -4
-5 -2
-5 -2
-6 -3
-7 -1
-8 3

*/
