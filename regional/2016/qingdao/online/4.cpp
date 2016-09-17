#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>

int main()
{
    long long l,r;
    while(scanf("%I64d%I64d",&l,&r)!=EOF)
    {
        if(l==0)
        {
            if(r<=1)printf("0\n");
            else if(r<=2)printf("1\n");
            else if(r<=4)printf("2\n");
            else
            {
                long long ans=2;
                r-=3;
                ans+=r/2;
                printf("%I64d\n",ans);
            }
        }
        else if(l==1)
        {
            if(r==1)printf("0\n");
            else if(r<=2)printf("1\n");
            else if(r<=4)printf("2\n");
            else
            {
                long long ans=2;
                r-=3;
                ans+=r/2;
                printf("%I64d\n",ans);
            }
        }
        else if(l==2)
        {
            if(r==2)printf("1\n");
            else if(r<=5)printf("2\n");
            else
            {
                long long ans=2;
                r-=4;
                ans+=r/2;
                printf("%I64d\n",ans);
            }
        }
        else
        {
            if(r<=l+3)printf("2\n");
            else
            {
                long long ans=2;
                r-=(l+2);
                ans+=r/2;
                printf("%I64d\n",ans);
            }
        }
    }
    return 0;
}
