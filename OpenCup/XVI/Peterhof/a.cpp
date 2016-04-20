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
int a,b;
int phi[22];
void geteular()
{
    int i, j;
    memset(phi, 0, sizeof(phi));
    phi[1] = 1;
    for(int i = 2; i < SIZE; i++)
    {
        if(!phi[i])
        {
            for(j = i; j < SIZE; j+=i)
            {
                if(!phi[j]) phi[j] = j;
                phi[j] = phi[j] / i * (i-1);
            }
        }
    }
}
int qpow(int x,int k)
{
    int ans=1;
    while(k)
    {
        if(k&1)
            ans=(ans*x);
        k>>=1;
        x=(x*x);
    }
    return ans;
}
int cal(int n,int mod)
{
    if(n==b)
    {
        return b;
    }
    int k=cal(n+1,phi[mod]);
    if(k>=phi[mod])
        k=k%phi[mod]+phi[mod];
    return qpow(n,k);
}
int main()
{
    freopen("abtower.in","r",stdin);
    freopen("abtower.out","w",stdout);
    geteular();
    scanf("%d%d",&a,&b);
    printf("%d\n",cal(a,10)%10);
    return 0;
}
