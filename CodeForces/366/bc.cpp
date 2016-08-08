#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1e4+10;
int sg[maxn],vis[maxn];
void init()
{
    int i,j,k;
    sg[0]=1, sg[1]=0;
    for(i=2;i<=1000;i++)
    {
        memset(vis,0,sizeof(vis));
        for(j=1;j<i;j++)
        vis[sg[j]^sg[i-j]]=1;  //拆分
        for(j=0;j<i;j++)
        vis[sg[j]]=1;         //取石子
        for(j=0;;j++)
        if(!vis[j])break;
        sg[i]=j;
    }
    for(i=1;i<=20;i++)
    cout << i << " " <<sg[i]<<endl;
}
int main()
{
    init();
}
