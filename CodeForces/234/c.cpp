#include<cstdio>
#include<cmath>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
int n,m,x,y,z,p;
int main()
{
    scanf("%d%d%d%d%d%d",&n,&m,&x,&y,&z,&p);
    x%=4;
    y%=2;
    z%=4;
    if(y&1)
    {
        x=(x+z)%4;
    }
    else
    {
        x=((x-z)%4+4)%4;
    }
    for(int i=0;i<p;i++)
    {
        int nx,ny;
        scanf("%d%d",&nx,&ny);
        int dx=nx-1;
        int dy=ny-1;
        int lx,ly;
        if(x==0)
        {
            lx=nx;
            ly=ny;
        }
        if(x==1)
        {
            lx=1+dy;
            ly=n-dx;
        }
        if(x==2)
        {
            lx=n-dx;
            ly=m-dy;
        }
        if(x==3)
        {
            lx=m-dy;
            ly=1+dx;
        }
        if(y)
        {
            if(x%2==0)
            {
               ly=m-(ly-1);
            }
            else
            {
                ly=n-(ly-1);
            }
        }
        printf("%d %d\n",lx,ly);
    }
    return 0;
}
