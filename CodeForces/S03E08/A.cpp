#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8
const int maxn=10005;
bool notprime[maxn];
int prime[maxn],prinum;
int ans[maxn];
void init()
{
    for(int i=2;i<maxn;i++)
    {
        if(notprime[i])continue;
        prime[prinum++]=i;
        for(int j=2*i;j<maxn;j+=i)
            notprime[j]=1;
    }
    for(int i=0;i<prinum;i++)
    {
        int sum=0;
        for(int j=i;j<prinum;j++)
        {
            sum+=prime[j];
            if(sum>=maxn)break;
            ans[sum]++;
        }
    }
}

int main()
{
    init();
    int n;
    while(scanf("%d",&n),n)
    {
        printf("%d\n",ans[n]);
    }
    return 0;
}
