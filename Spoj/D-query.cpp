#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define PII pair<int, int>
#define PB(x) push_back(x)
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)

struct obj
{
    int a, b, id;
    int ans;
}Q[200010];

int B;
int cnt[2000010];
int a[300100];
int tot;
int n, m;

int pos(int x) { return x / B; }

int add(int x)
{
    cnt[x]++;
    if(cnt[x] == 1) tot++;
    return tot;
}

int del(int x)
{
    cnt[x]--;
    if(cnt[x] == 0) tot--;
    return tot;
}

int cmp1(obj a, obj b) {
    if(pos(a.a) == pos(b.a)) return a.b < b.b;
    return pos(a.a) < pos(b.a);
}

int cmp2(obj a, obj b) {
    return a.id < b.id;
}

int main()
{
    scanf("%d", &n);
    B = sqrt(n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    memset(cnt, 0, sizeof cnt);
    tot = 0;
    scanf("%d", &m);
    for(int i = 0; i < m; i++) { scanf("%d%d", &Q[i].a, &Q[i].b); Q[i].id = i; }
    sort(Q, Q + m, cmp1);

    int l = 1, r = 1; add(a[1]);
    for(int i = 0; i < m; i++)
    {
        if(l < Q[i].a)
        {
            for(int j = l; j < Q[i].a; j++) del(a[j]);
        }
        if(l > Q[i].a)
        {
            for(int j = Q[i].a; j < l; j++) add(a[j]);
        }

        if(Q[i].b < r) {
            for(int j = Q[i].b + 1; j <= r; j++) del(a[j]);
        }
        if(Q[i].b > r){
            for(int j = r + 1; j <= Q[i].b; j++) add(a[j]);
        }

        l = Q[i].a; r = Q[i].b;
        Q[i].ans = tot;
    }
    sort(Q, Q + m, cmp2);
    for(int i = 0; i < m; i++) printf("%d\n", Q[i].ans);
    return 0;
}

