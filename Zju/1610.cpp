#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

const int N = 10000 * 4 ;
const int COL = 10000; 

using namespace std;

struct obj
{
    int a, b;
    obj *l, *r;
    int c;
    bool flg;
}f[N];
int cnt;
int cc[COL];
int ans[COL];

obj* make(int a, int b)
{  
    int p = ++cnt; 
    f[cnt].a = a; f[cnt].b = b; 
    f[cnt].l = f[cnt].r = NULL;
    f[cnt].c = 0;
    f[cnt].flg = false;
    
    int mid = (a + b) / 2;
    if(a < b)
    {
        f[p].l = make(a, mid);
        f[p].r = make(mid + 1, b);
    }
    return &f[p];
}

void draw(obj *t, int c)
{
    if(t == NULL) return;
    t->c = c; 
    t->flg = true;
}

void down(obj *t)
{
    if(!t->flg) return;
    draw(t->l, t->c);
    draw(t->r, t->c);
    t->flg = false;
}

void merge(obj *t)
{ 
    if(t->r->c != -1 && t->l->c != -1 && t->l->c == t->r->c)
        t->c = t->l->c;
    else 
        t->c = -1;
}

void insert(obj *t, int a, int b, int c)
{
    if(a <= t->a && t->b <= b) 
    {
        draw(t, c);
        return;
    }
    down(t);
    int mid = (t->a + t->b) / 2;
    if(a <= mid) insert(t->l, a, b, c);
    if(b > mid) insert(t->r, a, b, c);
    merge(t);
}

void count(obj *t)
{
    if(!t) return;
    if(t->c != -1)
    {
        for(int i = t->a; i <= t->b; i++) cc[i] = t->c;
        return;
    }
    count(t->l); count(t->r);
}

obj *top;
int m;

int main()
{
   while(~scanf("%d", &m)) 
   {
       cnt = 0;
       top = make(0, 8000);
      for(int i = 0; i < m; i++) 
      {
          int x, y, z; scanf("%d%d%d", &x, &y, &z);
          insert(top, x, y - 1, z + 1);
      }
      memset(cc, 0, sizeof cc);
      memset(ans, 0, sizeof ans);
      count(top);
      for(int i = 0; i <= 8000; i++)
      if(i == 0 || cc[i] != cc[i - 1])
         ans[cc[i]]++; 
      for(int i = 1; i <= 8000; i++)
         if(ans[i])  printf("%d %d\n", i - 1, ans[i]);
      putchar('\n');
   }
   return 0;
}


