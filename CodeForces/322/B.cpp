//#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) (a<0?-a:a)
#define SIZE 1000005
#define INF 0x7fffffff
map<long long ,bool>mmm;
int n;
long long num[42];
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        memset(num,0,sizeof(num));
        mmm.clear();

        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%lld",&num[i]);
            mmm[num[i]]=true;
        }
        if(n==1)
        {
            printf("Case #%d: 0\n",cas);
            continue;
        }
        sort(num,num+n);
        int ans=n-1;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                long long d=num[j]-num[i];
                if(d==0)
                    continue;
                int has=0;
//                if(d==0)
//                    has=mmm[num[i]];
//                else
                {
                    long long hed=num[j]-d*(n-1);
                    for(;hed<=num[i];hed+=d)
                    {
                        int tmp=0;
                        for(int tt=0;tt<n;tt++)
                            if(mmm[hed+d*tt])
                            tmp++;
                        has=MAX(has,tmp);
                    }
                }
//                printf("%lld %lld %d\n",num[i],num[j],has);
                ans=MIN(ans,n-has);
            }
        }

        for(int i=0; i<n; i++)
            mmm[num[i]]=false;

        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
