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
const double pi=acos(-1.0);
int n;
struct matrix
{
    double num[5][5];
    matrix()
    {
        memset(num,0,sizeof(num));
    }
} m,E;
matrix mult(matrix a,matrix b)
{
    matrix c;
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                c.num[i][j]+=a.num[i][k]*b.num[k][j];
    return c;
}
matrix qpow(matrix x,int t)
{
    matrix b = E;
    while (t > 0)
    {
        if (t & 1)
            b = mult(b,x);
        t = t >> 1 ;
        x = mult(x,x);
    }
    return b;
}
matrix trans(double x,double y,double z)
{
    matrix ans=E;
    ans.num[0][3]=x;
    ans.num[1][3]=y;
    ans.num[2][3]=z;
    return ans;
}
matrix scal(double x,double y,double z)
{
    matrix ans=E;
    ans.num[0][0]*=x;
    ans.num[1][1]*=y;
    ans.num[2][2]*=z;
    return ans;
}
matrix rot(double x,double y,double z,double d)
{
    d=d/180*pi;
    double l=sqrt(x*x+y*y+z*z);
    x/=l;
    y/=l;
    z/=l;
    matrix ans;
    ans.num[0][0]=x*x+(1.0-x*x)*cos(d);
    ans.num[0][1]=x*y*(1.0-cos(d))-z*sin(d);
    ans.num[0][2]=x*z*(1.0-cos(d))+y*sin(d);
    ans.num[1][0]=x*y*(1.0-cos(d))+z*sin(d);
    ans.num[1][1]=y*y+(1.0-y*y)*cos(d);
    ans.num[1][2]=y*z*(1.0-cos(d))-x*sin(d);
    ans.num[2][0]=x*z*(1.0-cos(d))-y*sin(d);
    ans.num[2][1]=y*z*(1.0-cos(d))+x*sin(d);
    ans.num[2][2]=z*z+(1.0-z*z)*cos(d);
    ans.num[3][3]=1.0;
    return ans;
}
matrix A;
void output(matrix T)
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%f ",T.num[i][j]);
        }
        printf("\n");
    }
}
matrix init(matrix B)
{
//    output(B);
    char str[50];
    scanf("%s",str);
//    printf("%s\n",str);
    if(str[0]=='e')
        return B;
    if(str[0]=='r'&&str[1]=='e')
    {
        int k;
        scanf("%d",&k);
        matrix C=init(E);
        C=init(mult(qpow(C,k),B));
        return C;
    }
    if(str[0]=='r'&&str[1]=='o')
    {
//        printf("$");
        double a,b,c,d;
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        matrix C=init(mult(rot(a,b,c,d),B));
        return C;
    }
    if(str[0]=='s')
    {
        double x,y,z;
        scanf("%lf%lf%lf",&x,&y,&z);
        matrix C=init(mult(scal(x,y,z),B));
        return C;
    }
    if(str[0]=='t')
    {
        double x,y,z;
        scanf("%lf%lf%lf",&x,&y,&z);
        matrix C=init(mult(trans(x,y,z),B));
        return C;
    }
}
int main()
{
    n=4;
    for(int i=0;i<4;i++)
        E.num[i][i]=1.0;
//    output(E);
    int m;
    while(scanf("%d",&m),m)
    {
        A=init(E);
//        printf("!");
        for(int i=0;i<m;i++)
        {
            matrix X;
            scanf("%lf%lf%lf",&X.num[0][0],&X.num[1][0],&X.num[2][0]);
            X.num[3][0]=1;
            X=mult(A,X);
            printf("%.2f %.2f %.2f\n",X.num[0][0],X.num[1][0],X.num[2][0]);
        }
        printf("\n");
    }
    return 0;
}