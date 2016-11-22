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
long long ans=-1;
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;)
    {
        int j=n/(n/i);

        if(j>k)
        {
            long long tmp=1LL*n/i*m;
            if(tmp>ans)
                ans=tmp;
            break;
        }
        int res=k-j+1+1;
//        printf("%d %d %d %d\n",i,j,n/i,res);
        if(res>m);
        else
        {
            long long tmp=1LL*(n/i)*(m/res);
            if(tmp>ans)
                ans=tmp;
        }
        i=j+1;
    }
    printf("%I64d\n",ans);
    return 0;
}
