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
#define LL long long
#define pii pair<int,int>
bool check(long long n,long long d1,long long d2,long long k)
{
    if(max(d1,d2)<=n/3)
    {
        if(k>=d1+d2&&n-k>=max(d1,d2)+abs(d1-d2)&&(n-k+d1+d2)%3==0)
            return true;
        if(n-k>=d1+d2&&k>=max(d1,d2)+abs(d1-d2)&&(n-k-d1-d2)%3==0)
            return true;
    }
    if(d1+d2<=n/3)
    {
        if(k>=d1+d1+d2&&(n-k)>=d2+d2+d1&&(k-d1-d1-d2)%3==0)
            return true;
        if(k>=d2+d2+d1&&(n-k)>=d1+d1+d2&&(k-d2-d2-d1)%3==0)
            return true;
    }
    return false;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n,k,d1,d2;
        scanf("%I64d%I64d%I64d%I64d",&n,&k,&d1,&d2);
        if(n%3==0)
        {
            if(check(n,d1,d2,k))
                puts("yes");
            else
                puts("no");
        }
        else
            puts("no");
    }
    return 0;
}
