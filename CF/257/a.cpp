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
int n,m;
queue<pair<int,int> >q;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        q.push(make_pair(x,i));
    }
    while(!q.empty())
    {
        if(q.size()==1)
        {
            printf("%d\n",q.front().second);
            return 0;
        }
        pair<int,int>head=q.front();
        q.pop();
        head.first-=m;
        if(head.first>0)
            q.push(head);
    }

    return 0;
}
