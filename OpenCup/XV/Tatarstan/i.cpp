#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
double eps=1e-8;
int sign(double x)
{
    if(fabs(x)<=eps)
        return 0;
    if(x>0)
        return 1;
    return -1;
}
long long n;
int m;
vector<long long>ans;
long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
void solve(int k)
{
    if(n==0)
    {
        ans.push_back(k-1);
        return ;
    }
    if(k==1)
    {
        ans.push_back(n);
        n=0;
        return ;
    }
    else if(k==2)
    {
        long long l=k,r=1e9;
        while(l<r)
        {
            long long mid=(l+r+1)/2;
            long long val=mid*(mid-1)/2;
            if(val>n)
                r=mid-1;
            else
                l=mid;
        }
        ans.push_back(l);
        n-=(l*(l-1)/2);
        return ;
    }
    long long C=1;
    long long nk=k;
    while(1)
    {
        double cc=(double)C*(nk+1)/(nk-k+1);
        if(sign(cc-n)==1)
        {
//            printf("%I64d %I64d\n",C,n/(nk+1)*(nk-k+1));
//            printf("%I64d %I64d\n",n,nk-k+1);
//            printf("%I64d %I64d\n",C*(nk+1),n*(nk-k+1));
//            printf("\n");
            n-=C;
            break;
        }
        else
        {
            long long fz=nk+1;
            long long fm=nk-k+1;
            long long gd1=gcd(fz,fm);
            fz/=gd1;
            fm/=gd1;
            long long gd2=gcd(C,fm);
            C/=gd2;
            fm/=gd2;
            C=C*fz/fm;
//            printf("%I64d\n",C);
            nk++;
        }
    }
    ans.push_back(nk);
}
int main()
{
//    freopen("1.txt","w",stdout);
    scanf("%lld%d",&n,&m);
    for(int i=m;i>=1;i--)
    {
        solve(i);
    }
//    printf("%I64d\n",n);
    for(int i=0;i<m;i++)
        printf("%lld ",ans[i]);
    printf("\n");
    return 0;
}
///10000000000000000
