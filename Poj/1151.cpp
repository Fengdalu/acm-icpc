#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i, j) for (int i = 0; i < j; i++)

using namespace std;

struct obj
{
    int a, b;
    obj *l, *r;
    double s;
    int add;
}f[11111];

struct obj1
{
    double a, b;
    double c;
    bool flg;
}l[11111];

int cnt;
double x[1111];
double tmp[1111];
obj* top;
int cnt1;

obj* make(int a, int b)
{
    cnt++;
    int tmp = cnt;
    f[cnt].a = a;
    f[cnt].b = b;
    f[cnt].l = NULL;
    f[cnt].r = NULL;
    f[cnt].s = 0;
    f[cnt].add = 0;
    if (a < b)
    {
        int mid = (a + b) >> 1;
        f[tmp].l = make(a, mid);
        f[tmp].r = make(mid + 1, b);
    }
    return f + tmp;
}

void update(obj* a)
{
    if (a->add > 0) a->s = x[a->b + 1] - x[a->a];
    else if (a->a == a->b) a->s = 0;
    else a->s = a->l->s + a->r->s;
}

void insert(obj* t, int a, int b)
{
    if (a <= t->a && t->b <= b)
    {
        (t->add)++;
        update(t);
    }
    else
    {
        int mid = (t->a + t->b) >> 1;
        if (a <= mid) insert(t->l, a, b);
        if (b > mid) insert(t->r, a, b);
        update(t);
    }
}

void del(obj* t, int a, int b)
{
    if (a <= t->a && t->b <= b)
    {
        (t->add)--;
        update(t);
    }
    else
    {
        int mid = (t->a + t->b) >> 1;
        if (a <= mid) del(t->l, a, b);
        if (b > mid) del(t->r, a, b);
        update(t);
    }
}

int cmp(obj1 a, obj1 b)
{
    return a.c < b.c;
}


int find(double xx)
{
    int l = 0, r = cnt1 - 1;
    while(l < r - 1)
    {
        int mid = (l + r) >> 1;
        if (xx < x[mid]) r = mid; else l = mid;
    }
    if (x[l] == xx) return l;
    else return r;
}
void test(obj* t)
{
    printf("%d %d\n", t->a, t->b);
    if (t->a == t->b) return;
    test(t->l);
    test(t->r);
}
int main()
{
    int n;
    int ii = 1;
    while(true)
    {
        scanf("%d", &n);
        if (n == 0) break;
        double a, b, c, d;
        rep(i, n)
        {
            scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
            l[i].a = a;
            l[i].b = c;
            l[i].c = b;
            l[i].flg = true;
            
            l[i + n].a = a;
            l[i + n].b = c;
            l[i + n].c = d;
            l[i + n].flg = false;
            
            x[i] = a;
            x[i + n] = c;
        }
        sort(x, x + 2 * n);
        cnt = 0;
        cnt1 = 0;
        rep(i, 2 * n) if (i == 0 || x[i] != x[i - 1]) tmp[cnt1++] = x[i];
        rep(i, cnt1) x[i] = tmp[i];
        sort(l, l + 2 * n, cmp);
        double ans = 0;
        top = make(0, cnt1 - 1);
        rep(i, 2 * n)
        {
            if(l[i].flg) insert(top, find(l[i].a), find(l[i].b) - 1);
            else del(top, find(l[i].a), find(l[i].b) - 1);
            ans += top->s * (l[i + 1].c - l[i].c);
        }
        printf("Test case #%d\n", ii++);
        printf("Total explored area: %.2f\n", ans);
        putchar('\n');
    }
}