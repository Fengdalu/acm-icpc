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
#define SIZE 1000005

map <int,int>mp;
int pos[100005];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<=n;i++)
    {
        scanf("%d",&pos[i]);
    }
    int len=pos[n]/k;
    for(int i=0;i<n;i++)
    {
        mp[pos[i]%len]++;
    }
    map <int,int>::iterator iter;
        int flag=0;
    for(iter=mp.begin();iter!=mp.end();iter++)
    {
        if(iter->second==k)
        {
            flag=1;
            break;
        }
    }
    printf("%d\n",flag);
    return 0;
}
