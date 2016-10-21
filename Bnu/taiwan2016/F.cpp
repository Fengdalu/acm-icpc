#include <cstring>
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
const long long mod=20160519;
const long long mod2=26880696;
struct matrix
{
    long long num[2][2];
    matrix()
    {
        memset(num,0,sizeof(num));
    }
}E,A;
matrix mult(matrix a,matrix b,long long mod)
{
    matrix c;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
                c.num[i][j]+=a.num[i][k]*b.num[k][j];
            c.num[i][j]%=mod;
        }
    }
    return c;
}
matrix qpow(matrix a,long long k,long long mod)
{
    matrix ans=E;
    while(k)
    {
        if(k&1)ans=mult(ans,a,mod);
        k>>=1;
        a=mult(a,a,mod);
    }
    return ans;
}
long long run(int n)
{
    matrix X;
    X.num[1][0]=1;
    matrix ans1=mult(qpow(A,n,mod2),X,mod2);
    long long n2=ans1.num[0][0];
    matrix ans2=mult(qpow(A,n2,mod),X,mod);
    return ans2.num[0][0];
}
int main()
{
    for(int i=0;i<2;i++)E.num[i][i]=1;
    A.num[0][1]=1;
    A.num[1][0]=1;
    A.num[1][1]=1;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        printf("%lld\n",run(n));
    }
    return 0;
}
