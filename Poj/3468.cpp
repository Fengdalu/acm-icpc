#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#define MAXN 100005

using namespace std;

long long num[MAXN];

struct node
{
    node *ch[2];
    node *pre;
    long long sum;
    long long val;
    long long add;
    long long size;
}*top;

void add(node *p, long long c)
{
    if (p == NULL || c == 0) return;
    p->val += c;
    p->sum += p->size * c;
    p->add += c;
}

void update(node *p)
{
    p->sum = p->val + (p->ch[0] ? p->ch[0]->sum : 0) + (p->ch[1] ? p->ch[1]->sum : 0);
    p->size = 1 + (p->ch[0] ? p->ch[0]->size : 0) + (p->ch[1] ? p->ch[1]->size : 0);
}

void down(node *p)
{
    if (p->add == 0) return;
    add(p->ch[0], p->add);
    add(p->ch[1], p->add);
    p->add = 0;
}

node* build(int a, int b)
{
    if (a > b) return NULL;
    int mid = (a + b) >> 1;
    
    node *p = (node*) malloc(sizeof(node));
    p->val = num[mid];
    p->pre = NULL;
    p->add = 0;
    p->ch[0] = build(a, mid - 1);
    p->ch[1] = build(mid + 1, b);
    if (p->ch[0] != NULL)(p->ch[0]->pre = p);
    if (p->ch[1] != NULL)(p->ch[1]->pre = p);
    update(p);
    return p;
}

void rotate(node *x, int c)
{
    node *y = x->pre;
    down(y), down(x);
    y->ch[!c] = x->ch[c];
    if (y->ch[!c] != NULL)(y->ch[!c]->pre = y);
    x->pre = y->pre;
    if (x->pre != NULL)
    {
        if (y == x->pre->ch[0]) x->pre->ch[0] = x;
        else x->pre->ch[1] = x;
    }
    x->ch[c] = y;
    y->pre = x;
    if (y == top) top = x;
    update(y);
}

void splay(node *x, node *f)
{
    for (down(x); x->pre != f;)
    {
        if (x->pre->pre == f)
        {
            if (x->pre->ch[0] == x) rotate(x, 1);
            else rotate(x, 0);
        }
        else
        {
            node *y = x->pre, *z = y->pre;
            if (z->ch[0] == y)
                if (y->ch[0] == x)
                    rotate(y, 1), rotate(x, 1);
                else
                    rotate(x, 0), rotate(x, 1);
                else
                    if (y->ch[1] == x)
                        rotate(y, 0), rotate(x, 0);
                    else
                        rotate(x, 1), rotate(x, 0);
        }
    }
    update(x);
}

node* findK(int k)
{
    k++;
    node *p = top;
    while(true)
    {
        down(p);
        int l = (p->ch[0] ? p->ch[0]->size : 0);
        if (l + 1 == k) return p;
        if (l + 1 < k) k -= l + 1, p = p->ch[1];
        else p = p->ch[0];
    }
}

int main()
{
    //freopen("test.txt", "r", stdin);
    int n, m;
    int a, b, c;
    char s[3];
    memset(num, 0, sizeof num);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%I64d", &num[i]);
    top = build(0, n + 1);
    for (int i = 0; i < m; i++)	
    {
        scanf("%s", s);
        if (!strcmp(s, "Q"))
        {
            scanf("%d%d", &a, &b);
            splay(findK(b + 1), NULL);
            splay(findK(a - 1), findK(b + 1));
            printf("%I64d\n", top->ch[0]->ch[1]->sum);
        }
        else
        {
            scanf("%d%d%d", &a, &b, &c);
            splay(findK(b + 1), NULL);
            splay(findK(a - 1), findK(b + 1));
            add(top->ch[0]->ch[1], c);
        }
    }
    return 0;
}