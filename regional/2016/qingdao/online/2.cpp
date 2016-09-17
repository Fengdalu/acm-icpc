#include<stdio.h>
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

double ans[500005];
void init()
{
    double sum=0;
    for(int i=1;i<=500000;i++)
    {
        sum+=1.0/i/i;
        ans[i]=sum;
    }
}
double cal(int n)
{
    if(n<=500000)
        return ans[n];
    else
        return 1.64493;
}
char str[2000005];
int main()
{
    init();
    while(scanf("%s",&str)!=EOF)
    {
        int n=0;
        int len=strlen(str);
        if(len>9)n=50000000;
        else
        {
            for(int i=0;i<len;i++)
                n=n*10+str[i]-'0';
        }
        n=min(n,50000000);
        printf("%.5f\n",cal(n));
    }
    return 0;
