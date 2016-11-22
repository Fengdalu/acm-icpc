#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define lson(x) ((x) <<1)
#define rson(x) ((x) << 1 | 1)

typedef struct node {
    int l,r;
    int rmax;
}node;

node t[800000];

void build(int root, int l, int r, int w){
    t[root].l = l;
    t[root].r = r;
    t[root].rmax = w;
    if (l == r)
        return;
    int mid = (l+r) >> 1;
    build(lson(root),l,mid,w);
    build(rson(root),mid+1,r,w);
}

inline int cmax (int a, int b)
{
    return a > b ? a : b;
}

inline int cmin (int a, int b)
{
    return a < b ? a : b;
}

void pushup (int root)
{
    t[root].rmax = cmax (t[lson(root)].rmax, t[rson(root)].rmax);
}

int insert (int root, int w){
    if (t[root].l == t[root].r)
    {
        if (t[root].rmax >= w)
        {
            t[root].rmax -= w;
            return t[root].l;
        }
        else
        {
            return -1;
        }
    }
    if (t[lson(root)].rmax >= w)
    {
        int ans = insert(lson(root),w);
        pushup(root);
        return ans;
    }
    else
    {
        int ans = insert(rson(root),w);
        pushup(root);
        return ans;
    }
}

int main()
{
    freopen ("billboard.in","r",stdin);
    freopen("billboard.out","w",stdout);
    int h,w,n;
    scanf("%d%d%d",&h,&w,&n);
    int i;
    int tmp = cmin (h,n+10);
    build(1,1,tmp,w);
    int e;
    for (i = 0; i < n; i++)
    {
        scanf("%d",&e);
        printf("%d\n",insert(1,e));
    }
    return 0;
}