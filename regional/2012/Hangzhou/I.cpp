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
#define zero(x) (fabs(x)<=eps)
#define MIN(x,y) (((x)<(y))?(x):(y))
#define MAX(x,y) (((x)>(y))?(x):(y))

const double pi=acos(-1.0);

int val[11]={16,7,8,1,1,2,3};
int num[11];
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        memset(num,0,sizeof(num));
        int n;
        int ans1=0;
        int ans2=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            char ch;
            scanf(" %c",&ch);
            num[ch-'A']++;
        }
        for(int i=0;i<7;i++)
            ans1=ans1+val[i]*num[i];
        if(num[1]&&num[2]);
        else
            ans1=MAX(1,ans1-1);

        memset(num,0,sizeof(num));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            char ch;
            scanf(" %c",&ch);
            num[ch-'A']++;
        }
        for(int i=0;i<7;i++)
            ans2=ans2+val[i]*num[i];
        if(num[1]&&num[2]);
        else
            ans2=MAX(1,ans2-1);

        if(ans1>ans2)
        {
            printf("red\n");
        }
        else if(ans1==ans2)
            printf("tie\n");
        else
            printf("black\n");
    }
    return 0;
}