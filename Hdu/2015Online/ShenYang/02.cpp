#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) (a<0?-a:a)
#define SIZE 100005
#define MOD 1000000007

int getlen(int mod)
{
    int t1=2%mod,t2=10%mod;
    int fib0=t1,fib1=t2;
    int pos=2;
    while(1)
    {
        int tmp;
        tmp=(10*fib1-fib0)%mod+mod;
        tmp%=mod;
//        printf("%I64d %I64d\n",pos,tmp);
        if(fib1==t1&&tmp==t2)
        {
            return pos-1;
        }
        pos++;
        fib0=fib1;
        fib1=tmp;
    }
}

long long qpow(long long x,long long k,long long mod)
{
    long long b = 1;
    while (k > 0)
    {
        if (k & 1)
            b = (b*x)%mod;
        k = k >> 1 ;
        x = (x*x)%mod;
    }
    return b;
}
int n=2;
struct matrix
{
    long long num[5][5];
} E;
matrix mult(matrix a,matrix b,long long mod)
{
    matrix c;
    memset(c.num,0,sizeof(c.num));

    for(int i=0; i<n; i++)
        for(int k=0; k<n; k++)
            for(int j=0; j<n; j++)
                c.num[i][j]+=a.num[i][k]*b.num[k][j];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            c.num[i][j]%=mod;
    return c;
}
matrix qpow(matrix x,int t,long long mod)
{
    matrix b = E;
    while (t > 0)
    {
        if (t & 1)
            b = mult(b,x,mod);
        t = t >> 1 ;
        x = mult(x,x,mod);
    }
    return b;
}
int main()
{
    for(int i=0; i<n; i++)
    {
        E.num[i][i]=1;
    }
//    long long n;
//    scanf("%I64d",&n);
//    printf("%I64d\n",getlen(n));
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        long long x;
        int m;
        scanf("%I64d%d",&x,&m);
        int len=getlen(m);
        long long N=(qpow(2LL,x,len)+1)%len;

//        printf("%I64d\n",N);
        printf("Case #%d: ",cas);
        if(N==0)
            printf("1\n");
        else if(N==1)
            printf("%d\n",9%m);
        else
        {
            matrix d;
            d.num[0][0]=10;
            d.num[1][0]=2;

            matrix tmp;
            tmp.num[0][0]=10;
            tmp.num[1][0]=1;
            tmp.num[0][1]=-1;
            tmp.num[1][1]=0;

            tmp=qpow(tmp,N-1,m);
            d=mult(tmp,d,m);
            printf("%I64d\n",(d.num[0][0]+m-1)%m);
        }
    }
    return 0;
}