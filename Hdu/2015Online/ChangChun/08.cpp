#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;
#define AA first
#define BB second
#define N 20010
#define M 100010
#define LL long long
#define PII pair<int, int>
#define E pair< int, PII >
#define QQ pair< PII, LL >

struct node
{
    int l, r;
    int c;
}f[N];
int cnt, T, n, q, x, rt;

int add(int c)
{
    f[cnt].l = f[cnt].r = -1;
    f[cnt].c = c;
    return cnt++;
}

void add(int x, int c)
{
    if(c > f[x].c)
    {
        if(f[x].l == -1) f[x].l = add(c);
        else add(f[x].l, c);
    }
    else
    {
        if(f[x].r == -1) f[x].r = add(c);
        else add(f[x].r, c);
    }
}

void qry(int x, int c)
{
    if(f[x].c == c) return;
    if(c > f[x].c) { printf("W"); qry(f[x].l, c); }
    else { printf("E"); qry(f[x].r, c); }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        cnt = 0;
        rt = -1;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            if(rt == -1) rt = add(x);
            else add(rt, x);
        }
        scanf("%d", &q);
        for(int i = 0; i < q; i++)
        {
            scanf("%d", &x);
            qry(rt, x);
            printf("\n");
        }
    }
    return 0;
}
