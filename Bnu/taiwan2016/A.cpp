include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;
struct node
{
    int type;
    int nxt;

}p[100005];
int nxt[100005][20];
char str[100005];
int n;
vector<int>vec[4];
int type(char ch)
{
    if(ch=='e')return 0;
    if(ch=='a')return 1;
    if(ch=='s')return 2;
    if(ch=='y')return 3;
}
int main()
{
    scanf("%s",str);
    n=strlen(str);
    for(int i=0;i<n;i++)
    {
        p[i].type=type(str[i]);
        vec[p[i].type].push_back(i);
    }
    p[n].nxt=n;
    for(int i=0;i<4;i++)
        vec[i].push_back(n);
    for(int i=0;i<n;i++)
    {
        int tp=(p[i].type+1)%4;
        int nxtpos=lower_bound(vec[tp].begin(),vec[tp].end(),i)-vec[tp].begin();
        p[i].nxt=vec[tp][nxtpos];
    }
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0)
                nxt[j][i]=p[j].nxt;
            else
                nxt[j][i]=nxt[nxt[j][i-1]][i-1];
        }
    }
//    for(int i=0;i<n;i++)
//    {
//        for(int j=0;j<4;j++)
//            printf("%d ",nxt[i][j]);
//        printf("\n");
//    }
    int m;
    scanf("%d",&m);
    while(m--)
    {
        int ans=1;
        int l,r;
        scanf("%d%d",&l,&r);
        l--;
        r--;
        int now=lower_bound(vec[0].begin(),vec[0].end(),l)-vec[0].begin();
        now=vec[0][now];
        if(now>r)
        {
            printf("0\n");
            continue;
        }
        while(1)
        {
//            printf("%d\n",now);
            bool flag=false;
            for(int i=19;i>=0;i--)
            {
                if(nxt[now][i]<=r)
                {
                    flag=true;
                    ans+=(1<<i);
                    now=nxt[now][i];
                    break;
                }
            }
//            printf("%d\n",ans);
            if(flag)continue;
            break;
        }
//        printf("%d\n",ans);
        printf("%d\n",ans/4);
    }
    return 0;
}
