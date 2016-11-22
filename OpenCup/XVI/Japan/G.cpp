#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
long long A,B,C;
struct node
{
    int x,y,z;
};
bool inrec(int x,int y,int z)
{
    if(x>=0&&x<A&&y<B&&y>=0&&z<C&&z>=0)
    return true;
    return false;
}
bool connect(node a,node b)
{
    if(a.x==b.x&&a.y==b.y&&abs(a.z-b.z)<=1)
    return true;
    if(a.y==b.y&&a.z==b.z&&abs(a.x-b.x)<=1)
    return true;
    if(a.z==b.z&&a.x==b.x&&abs(a.y-b.y)<=1)
    return true;
    return false;
}
int dx[6]={0,0,0,0,1,-1};
int dy[6]={1,-1,0,0,0,0};
int dz[6]={0,0,1,-1,0,0};
int n;
node p[1005];
int main()
{
    cin >> A >> B >> C;
    //scanf("%lld%lld%lld",&A,&B,&C);
    long long ans=A*B*2+B*C*2+C*A*2;
    cin >> n ;
    for(int i=0;i<n;i++)
    {
        cin >> p[i].x >> p[i].y >> p[i].z;
    }
    for(int i=0;i<n;i++)
    {
        int face=0;
        for(int k=0;k<6;k++)
        {
            int nx=p[i].x+dx[k];
            int ny=p[i].y+dy[k];
            int nz=p[i].z+dz[k];
            if(inrec(nx,ny,nz))
            face++;
        }
        for(int j=0;j<i;j++)
        {
            if(connect(p[i],p[j]))
            face--;
        }
        ans=ans-(6-face-face);
    }
    cout << ans << endl;
    return 0;
}
