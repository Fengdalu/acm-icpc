#include<cmath>
#include<ctime>
#include<cstdio>
#include<vector>
#include<bitset>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long 
#define mod 1000000009
#define inf 1000000000
using namespace std;
ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
int getint(char a)
{
    if(a=='R')return 0;
    if(a=='P')return 1;
    return 2;
}
char getchar(int a)
{
    if(a==0)return 'R';
    if(a==1)return 'P';
    return 'S';
}
struct data{
    int c,to[3];
}fsm[105],a[50005];
int main()
{
    freopen("epic.in","r",stdin);
    freopen("epic.out","w",stdout);
    srand(123);
    n=read();
    char ch[2];
    for(int i=1;i<=n;i++)
    {
        scanf("%s",ch+1);
        fsm[i].c=getint(ch[1]);
        for(int j=0;j<3;j++)
            fsm[i].to[j]=read();
    }
    int c=50000/n;
    for(int i=1;i<=n;i++)
        for(int j=0;j<c;j++)
        {
            int cur=n*j+i,nxt=(j+1)%c;
            for(int k=0;k<3;k++)
                a[cur].to[k]=nxt*n+rand()%n+1;
            a[cur].c=(fsm[i].c+1)%3;
            a[cur].to[fsm[i].c]=j*n+fsm[i].to[a[cur].c];
        }
    printf("%d\n",c*n);
    for(int i=1;i<=c*n;i++)
    {
        printf("%c ",getchar(a[i].c));
        for(int j=0;j<3;j++)
            printf("%d ",a[i].to[j]);
        puts("");
    }
    return 0;
}