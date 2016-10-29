#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;

long long a[100005];
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        long long sum=0;
        for(int i=0; i<n; i++)
        {
            scanf("%I64d",&a[i]);
            sum+=a[i];
        }
        printf("Case #%d: ",cas);
        if(sum%k==0)
        {
            sum/=k;
            int ans=0;
            long long now=a[0];
            for(int i=1; i<n; i++)
            {
                if(now%sum==0)
                {
                    ans+=(now/sum-1);
                    now%=sum;
                }
                else
                {
                    ans+=now/sum;
                    now%=sum;
                }
                if(now==0)
                {
                    now+=a[i];
                }
                else
                {
                    now+=a[i];
                    ans++;
                }
            }
            if(now%sum==0)
            {
                ans+=(now/sum-1);
                now%=sum;
            }
            else
            {
                ans+=now/sum;
                now%=sum;
            }
            printf("%d\n",ans);
        }
        else
            printf("-1\n");
    }
    return 0;
}
