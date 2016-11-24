#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=200005;
const int MAXM=20005;

struct Point
{
    int x[2],c,id;
    bool operator < (const Point &t)const
    {
        return c<t.c;
    }
    bool operator == (const Point &t)const
    {
        return x[0]==t.x[0] && x[1]==t.x[1];
    }
    ll dis(const Point &t)const
    {
        ll res=0;
        for(int i=0;i<2;i++)
            res+=1LL*(x[i]-t.x[i])*(x[i]-t.x[i]);
        return res;
    }
}p[MAXN],tp[MAXN],q[MAXM];
struct node
{
    node *son[2];
    int ext,has;
    Point t;
    void pushUp()
    {
        has=ext|son[0]->has|son[1]->has;
    }
}s[MAXN],*rt,*null;
int tot;
void init()
{
    tot=0;
    rt=null;
}
node* newnode(Point _t)
{
    node* now=&s[tot++];
    now->son[0]=null;
    now->son[1]=null;
    now->ext=0;
    now->t=_t;
    return now;
}
void build(Point t[],int n,node* &u,int dep)
{
    if(n==0)return;
    swap(t[rand()%n],t[n-1]);
    int p=0;
    for(int i=0;i<n-1;i++)
        if(t[i].x[dep]<t[n-1].x[dep])
            swap(t[p++],t[i]);
    swap(t[p],t[n-1]);
    u=newnode(t[p]);
    build(t,p,u->son[0],dep^1);
    build(t+p+1,n-1-p,u->son[1],dep^1);
}
void add(Point t,node* u,int dep)
{
    if(u==null)return;
    if(t==u->t)
    {
        u->ext=1;
        u->has=1;
        return;
    }
    int dir=t.x[dep]>u->t.x[dep];
    add(t,u->son[dir],dep^1);
    u->pushUp();
}
void query(Point t,node* u,int dep,pair<ll,int> &res)
{
    if(u==null || !u->has)return;
    if(u->ext)res=min(res,make_pair(t.dis(u->t),u->t.id));
    int dir=t.x[dep]>u->t.x[dep];
    query(t,u->son[dir],dep^1,res);
    if(1LL*(t.x[dep]-u->t.x[dep])*(t.x[dep]-u->t.x[dep])<=res.first)
        query(t,u->son[dir^1],dep^1,res);
}
int res[MAXN];
int main()
{
  freopen("a.in", "r", stdin);
  freopen("a1.out", "w", stdout);
    srand(time(NULL));
    null=new node;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",&p[i].x[0],&p[i].x[1],&p[i].c),p[i].id=i;
        for(int i=1;i<=n;i++)
            tp[i]=p[i];
        for(int i=1;i<=m;i++)
            scanf("%d%d%d",&q[i].x[0],&q[i].x[1],&q[i].c),q[i].id=i;
        init();
        build(p+1,n,rt,0);
        sort(p+1,p+n+1);
        sort(q+1,q+m+1);
        for(int i=1,j=1;i<=m;i++)
        {
            while(j<=n && p[j].c<=q[i].c)add(p[j++],rt,0);
            pair<ll,int> now=make_pair((1LL<<60)-1,n+1);
            query(q[i],rt,0,now);
            res[q[i].id]=now.second;
        }
        for(int i=1;i<=m;i++)
            printf("%d %d %d\n",tp[res[i]].x[0],tp[res[i]].x[1],tp[res[i]].c);
    }
    return 0;
}
