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
#define eps 1e-5
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define zero(x) ((fabs(x))<eps)
#define sign(x) ((x)<-eps?-1:((x)>eps))
#define SZ size()
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
#define _POJ_ www.baidu.com
#define DH 1991001
map <int,int>mm;
vector <int> has;
vector <int> ans;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n*n;i++)
    {
        int t;
        scanf("%d",&t);
        if(!mm[t])
            has.push_back(t);
        mm[t]++;
    }
    sort(has.begin(),has.end());
    reverse(has.begin(),has.end());
    for(int i=1;i*i<=mm[has[0]];i++)
    {
        ans.push_back(has[0]);
    }
    mm[has[0]]=0;
    for(int i=1;i<has.size();i++)
    {
        if(mm[has[i]]==0)
            continue;
        else
        {
            while(mm[has[i]]!=0)
            {

                for(int j=0;j<ans.size();j++)
                    mm[gcd(ans[j],has[i])]-=2;
                mm[has[i]]--;
                ans.push_back(has[i]);
            }
        }
    }
    for(int i=0;i<ans.size();i++)
        printf("%d ",ans[i]);
    printf("\n");
    return 0;
}
