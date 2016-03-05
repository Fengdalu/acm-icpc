#include <stdio.h>
#include <math.h>
#include<vector>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define max(a,b) (a>b?a:b)
struct tri
{
    double tht[3];
};
struct point
{
    double x,y;
} p[22];
vector <tri>ans;
double xmult(point p1,point p2,point p0)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

double dist(point p1,point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
int viss[522][522];
bool check2(tri a,tri b)
{
    if(fabs(a.tht[0]-b.tht[0])<=eps&&fabs(a.tht[1]-b.tht[1])<=eps)
        return true;
    return false;
}
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
//        vector<point>p;
        ans.clear();
        vector <point>p2;
        memset(viss,0,sizeof(viss));
        for(int i=0; i<n; i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
            if(viss[(int)p[i].x+200][(int)p[i].y+200])
                ;
            else
            {
                viss[(int)p[i].x+200][(int)p[i].y+200]=1;
                p2.push_back(p[i]);
            }
        }
        n=p2.size();
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
                for(int k=j+1; k<n; k++)
                {

//                    printf(" %f %f\n %f %f\n %f %f\n",p[i].x,p[i].y,p[j].x,p[j].y,p[k].x,p[k].y);
//                    printf("%f\n",xmult(p[i],p[j],p[k]));
                    if(fabs(xmult(p2[j],p2[k],p2[i]))<=eps)
                        continue;
//                        printf("!!\n");
                    double a,b,c;
                    a = dist (p2[i], p2[j]);
                    b = dist (p2[i], p2[k]);
                    c = dist (p2[j], p2[k]);
                    tri term;
                    term.tht[0] = (b*b + c*c - a*a)/b/c;
                    term.tht[1] = (a*a + c*c - b*b)/a/c;
                    term.tht[2] = (a*a + b*b - c*c)/a/b;
                    sort(term.tht,term.tht+3);
                    ans.push_back(term);

                }
        int tans=0;
        for(int i=0; i<ans.size(); i++)
        {
            int num=0;
            for(int j=i; j<ans.size(); j++)
            {
//                if(vis[j])continue;
                if(check2(ans[i],ans[j]))
                {
                    num++;
                    tans=max(tans,num);
                }
            }
        }
        printf("%d\n",tans);
    }
    return 0;
}