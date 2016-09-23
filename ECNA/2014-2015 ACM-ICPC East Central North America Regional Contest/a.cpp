#include<cstdio>
#include<cmath>
using namespace std;
int n1,n2;
long long a1[11],a2[11];
struct obj
{
    long long fz,fm;
    obj() {}
    obj(long long a,long long b)
    {
        fz=a;
        fm=b;
    }
    void output()
    {
        printf("%I64d %I64d\n",fz,fm);
    }
};
long long gcd(long long a,long long b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
obj add(obj a,obj b)
{
    obj ans=obj(a.fz*b.fm+b.fz*a.fm,a.fm*b.fm);
    long long gd=gcd(abs(ans.fz),abs(ans.fm));
    ans.fz/=gd;
    ans.fm/=gd;
    if(ans.fm<0)
    {
        ans.fm*=-1;
        ans.fz*=-1;
    }
    return ans;
}
obj sub(obj a,obj b)
{
    obj ans=obj(a.fz*b.fm-b.fz*a.fm,a.fm*b.fm);
    long long gd=gcd(abs(ans.fz),abs(ans.fm));
    ans.fz/=gd;
    ans.fm/=gd;
    if(ans.fm<0)
    {
        ans.fm*=-1;
        ans.fz*=-1;
    }
    return ans;
}
obj mult(obj a,obj b)
{
    obj ans=obj(a.fz*b.fz,a.fm*b.fm);
    long long gd=gcd(abs(ans.fz),abs(ans.fm));
    ans.fz/=gd;
    ans.fm/=gd;
    if(ans.fm<0)
    {
        ans.fm*=-1;
        ans.fz*=-1;
    }
    return ans;
}
obj divide(obj a,obj b)
{
    obj ans=obj(a.fz*b.fm,b.fz*a.fm);
    long long gd=gcd(abs(ans.fz),abs(ans.fm));
    ans.fz/=gd;
    ans.fm/=gd;
    if(ans.fm<0)
    {
        ans.fm*=-1;
        ans.fz*=-1;
    }
    return ans;
}
long long ans[100005];
void output(obj x)
{

    ans[0]=x.fz/x.fm;
    x.fz%=x.fm;
    if(x.fz<0)
    {
        ans[0]--;
        x.fz+=x.fm;
    }
    int head=1;
    while(x.fz)
    {
        ans[head++]=x.fm/x.fz;
        long long tmp=x.fm%x.fz;
        x.fm=x.fz;
        x.fz=tmp;
    }
    for(int i=0; i<head; i++)
        printf("%I64d ",ans[i]);
    printf("\n");
}
int main()
{
    int cas=1;
//    output(obj(5,4));
    while(1)
    {
        scanf("%d%d",&n1,&n2);
        if(n1==0&&n2==0)break;
        for(int i=0; i<n1; i++)scanf("%I64d",&a1[i]);
        for(int i=0; i<n2; i++)scanf("%I64d",&a2[i]);
        obj num1,num2;
        num1=obj(a1[n1-1],1);
        for(int i=n1-2; i>=0; i--)
        {
            num1=obj(num1.fm+num1.fz*a1[i],num1.fz);
            long long gd=gcd(abs(num1.fz),abs(num1.fm));
            num1.fz/=gd;
            num1.fm/=gd;
            if(num1.fm<0)
            {
                num1.fz*=-1;
                num1.fm*=-1;
            }
        }
        num2=obj(a2[n2-1],1);
        for(int i=n2-2; i>=0; i--)
        {
            num2=obj(num2.fm+num2.fz*a2[i],num2.fz);
            long long gd=gcd(abs(num2.fz),abs(num2.fm));
            num2.fz/=gd;
            num2.fm/=gd;
            if(num2.fm<0)
            {
                num2.fz*=-1;
                num2.fm*=-1;
            }
        }
        printf("Case %d:\n",cas++);
        output(add(num1,num2));
        output(sub(num1,num2));
        output(mult(num1,num2));
        output(divide(num1,num2));
    }
    return 0;
}
