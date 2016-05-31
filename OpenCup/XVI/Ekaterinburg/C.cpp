#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<vector>
#define C    240
#define TIME 10
#define inf 1<<25
#define LL long long
using namespace std;

int num[1005];

int main()
{
//    while(1)
//    {
        memset(num,0,sizeof(num));
        int n,m;
        scanf("%d%d",&n,&m);
        if(n==1)
            printf("%d\n",m);
        else
        {
            num[1]=m;
            for(int i=2; i<=n; i++)
            {
                int need=(i+1)/2-1;
                int has=0;
                int cost=0;
                for(int j=i-1; j>=1; j--)
                {
                    if(has==need)
                        break;
                    if(num[j]==-1)
                        has++;
                    else if(num[j]==0)
                    {
                        has++;
                        cost++;
                    }

                }
//            printf("%d %d\n",i,cost);
                if(cost>m)
                    num[i]=-1;
                else
                {
                    for(int j=i-1; j>=1; j--)
                    {
                        if(num[j]==-1)
                        {
                            num[j]=0;
                            need--;
                        }
                        else if(num[j]==0&&need>0)
                        {
                            num[j]=1;
                            need--;
                        }
                        else if(num[j]>0)
                            num[j]=0;
                    }
                    num[i]=m-cost;
                }
            }
            for(int i=n; i>=1; i--)
                printf("%d ",num[i]);
            printf("\n");
        }

//    }
    return 0;
}
/*
1 0
        0
1 1
        1
1 2
        2
1 3
        3
1 4
        4
1 5
        5
2 0
        0 0
2 1
        1 0
2 2
        2 0
2 3
        3 0
2 4
        4 0
2 5
        5 0
3 0
        -1 0 0
3 1
        0 0 1
3 2
        1 0 1
3 3
        2 0 1
3 4
        3 0 1
3 5
        4 0 1
4 0
        0 0 0 0
4 1
        0 0 0 0
4 2
        1 0 1 0
4 3
        2 0 1 0
4 4
        3 0 1 0
4 5
        4 0 1 0
*/
