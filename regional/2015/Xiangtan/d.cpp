#include<stdio.h>
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
//#define eps 1e-14
//bool zero(double x)
//{
//    if(fabs(x)<=eps)
//        return true;
//    return false;
//}
//int sign(double x)
//{
//    if(zero(x))
//        return 0;
//    if(x>0)return 1;
//    return -1;
//}
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        double tmp;
        scanf("%lf",&tmp);
        double det=1e9;
        int ansfz=0,ansfm=1;
        for(int i=1; i<=1000; i++)
        {
            for(int j=-2; j<=2; j++)
            {
                int fz=(int)(i*tmp)+j;
                double dt=fabs((double)fz/i-tmp);
                //                printf("%d %f\n",fz,dt);
                if(dt<det)
                {
                    det=dt;
                    ansfz=fz;
                    ansfm=i;
                }
            }
        }
        int gd=gcd(ansfz,ansfm);
        printf("%d/%d\n",ansfz/gd,ansfm/gd);
    }
    return 0;
}
