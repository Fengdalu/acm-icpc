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

int ans[100005];
int n;
void init()
{
    for(int i=2;i<=n;i++)
        ans[i]=1;
    for(int k=2;k<=n;k++)
    {
//        printf("%d\n",k);
//        if(k%10000==0)
//            printf("%d\n",k);
        long long sum=1;
        long long t=k;
        sum+=t;
        while(sum<=n)
        {
//            printf("%d %d\n",k,sum);
            ans[sum]++;
            t=t*k;
            sum+=t;
        }
    }
}
int main()
{
    scanf("%d",&n);
    init();
    if(n==1)
        printf("0\n");
    else
    {
        long long tans=0;
        for(int i=1;i<=n;i++)
        {
            if(n%i==0)
                tans+=ans[n/i];
        }
        printf("%I64d\n",tans);
    }
    return 0;
}