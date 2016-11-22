#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define eps 1e-8
int step[100005];
bool vis[100005];
int d[100005];
int n;
vector<int>vec[100005];
void bfs(int pos)
{
    queue<int>q;
    q.push(pos);
    vis[pos]=1;
    while(!q.empty())
    {
        int head=q.front();
        q.pop();
        for(int i=0;i<vec[head].size();i++)
        {
            int nxt=vec[head][i];
            if(vis[nxt])continue;
            vis[nxt]=1;
            step[nxt]=step[head]+1;
            q.push(nxt);
        }
    }
}
int main()
{
    freopen("jumping.in","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(step,-1,sizeof(step));
        memset(vis,0,sizeof(vis));
        scanf("%d",&n);
        for(int i=1; i<=n; i++)vec[i].clear();
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&d[i]);
            if(i+d[i]<=n)
                vec[i+d[i]].push_back(i);
            if(i-d[i]>=1)
                vec[i-d[i]].push_back(i);
        }
        step[n]=0;
        vis[n]=1;
        bfs(n);
        for(int i=1;i<=n;i++)
            printf("%d\n",step[i]);
    }
    return 0;
}
