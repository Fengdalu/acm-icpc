#include<bits/stdc++.h>
using namespace std;
const int N = 1e7+2;
int f[N];
int g[N];
int two[N];
int main()
{
    two[0]=1;
    for(int i=1; i<N; i++)
    {
        two[i]=(two[i-1] << 1) % 100000;
    }
    int n,k;
    scanf("%d%d",&n,&k);
    if(k==1)
    {
        printf("0\n");
        return 0;
    }
    for(int i=0; i<k; i++)
    {
        g[i]=0;
        f[i]=two[i];
    }
    g[k]=2;
    f[k]=(two[k]-2+100000)%100000;
    for(int i=k+1; i<=n; i++)
    {
        g[i]=(g[i-1]*2+f[i-k])%100000;
        f[i]=(two[i]-g[i]+100000)%100000;
    }
    printf("%d\n",f[n]);
    return 0;
}
