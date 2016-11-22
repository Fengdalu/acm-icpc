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
long long c[101][101];
void init()
{
    c[0][0]=1;
    for(int i=1;i<=20;i++)
    {
        c[i][0]=1;
        for(int j=1;j<=i;j++)
            c[i][j]=c[i-1][j-1]+c[i-1][j];
    }
}
int main()
{
    freopen("popcorn.in","r",stdin);
    init();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        printf("%I64d\n",c[n][m]);
    }
    return 0;
}
