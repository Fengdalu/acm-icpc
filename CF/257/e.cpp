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
const int maxn=100005;
bool notprime[maxn];
int prime[maxn],prinum;
void init()
{
    for(int i=2;i<maxn;i++)
    {
        if(notprime[i])continue;
        prime[prinum++]=i;
        for(int j=2*i;j<maxn;j+=i)
            notprime[j]=1;
    }
}
vector<pair<int,int> >pr;
bool vis[100005];
int main()
{
    init();
    int n;
    scanf("%d",&n);
    for(int i=1;i<maxn&&prime[i]*2<=n;i++)
    {
        vector<int>vec;
        for(int j=1;j*prime[i]<=n;j++)
        {
            if(j==2)continue;
            if(vis[j*prime[i]])continue;
            vec.push_back(j*prime[i]);
            vis[j*prime[i]]=1;
        }
        if(vec.size()%2==0)
        {
            for(int j=0;j<vec.size();j+=2)
            {
                pr.push_back(make_pair(vec[j],vec[j+1]));
            }
        }
        else
        {
            vis[2*prime[i]]=1;
            vec.push_back(2*prime[i]);
            for(int j=0;j<vec.size();j+=2)
            {
                pr.push_back(make_pair(vec[j],vec[j+1]));
            }
        }
    }
    vector<int>two;
    for(int i=2;i<=n;i+=2)if(vis[i]==0)two.push_back(i);
    for(int i=0;i+1<two.size();i+=2)pr.push_back(make_pair(two[i],two[i+1]));
    printf("%d\n",pr.size());
    for(int i=0;i<pr.size();i++)
        printf("%d %d\n",pr[i].first,pr[i].second);
    return 0;
}
