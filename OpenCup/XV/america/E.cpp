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
#define SIZE 1000005
bool notprime[SIZE];
int prime[SIZE],prinum;
void getprime()
{
    notprime[1]=1;
    for(int i=2; i<SIZE; i++)
    {
        if(notprime[i])
            continue;
        prime[prinum++]=i;
        for(int j=2*i; j<SIZE; j+=i)
            notprime[j]=1;
    }
}
int maxp[SIZE];
void init()
{
    getprime();
    maxp[1]=-1;
    for(int i=0; i<prinum; i++)
    {
        for(int j=prime[i]; j<SIZE; j+=prime[i])
        {
            maxp[j]=prime[i];
        }
    }
}
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int n,k;
int num[SIZE];
bool check(int x)
{
    int ans=0;
    int GD=num[0];
    for(int i=0; i<n; i++)
    {
        if(i==n-1)
        {
            ans++;
            break;
        }
        int tmp=gcd(GD,num[i+1]);
        if(tmp<x)
        {
            ans++;
            GD=num[i+1];
        }
        else
        {
            GD=tmp;
        }
    }
    return ans<=k;
}
int main()
{
    init();
    scanf("%d%d",&n,&k);
    int l=1,r=1e9;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&num[i]);
        r=min(r,maxp[num[i]]);
    }
    int flag=0;
    while(l<r)
    {
        int mid=(l+r+1)/2;
        if(check(mid))
        {
            flag=1;
            l=mid;
        }
        else
            r=mid-1;
    }
    if(flag)
    {
        while(notprime[l]&&l>0)l--;
        printf("%d\n",l);
    }
    else
        printf("0");
    return 0;
}
