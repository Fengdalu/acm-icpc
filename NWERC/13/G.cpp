#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int gcd(int a,int b)
{
    int temp;
    if(a<b)
    {
        temp=a;
        a=b;
        b=temp;
    }
    while(b!=0)
    {
        temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}
int main()
{
    int a,b,c;
    int fenzi,fenmu;
    int g;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        fenzi=a*b;
        fenmu=c-b;
        g=gcd(fenzi,fenmu);
        fenzi/=g;fenmu/=g;
        printf("%d/%d\n",fenzi,fenmu);
    }
    return 0;
}