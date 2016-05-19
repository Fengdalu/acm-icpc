#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;


struct obj
{
    LL c;
    LL v;
}ff[222222];

LL h[222222 * 4];
int n, c;
LL f;
LL a[222222], b[222222];
LL l;

void insert(LL x)
{
    h[++l] = x;
    int k = l;
    while(k != 1 && h[k >> 1] < h[k]) {swap(h[k], h[k >> 1]); k >>= 1;}
}

void adjust(int x)
{
    int t = -1;
    LL mm = h[x];
    if ((x << 1) <= l && h[x << 1] > mm) {mm = h[x << 1]; t = x << 1;}
    if ((x << 1) + 1 <= l && h[(x << 1) + 1] > mm) {mm = h[(x << 1) + 1]; t = (x << 1) + 1;}
    if (t != -1) {swap(h[t], h[x]); adjust(t);}
}

int cmp(obj a, obj b)
{
    return a.v < b.v;
}

int main()
{
    scanf("%d%d%I64d", &n, &c, &f);
    for (int i = 0; i < c; i++) scanf("%I64d%I64d", &ff[i].v, &ff[i].c);
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    sort(ff, ff + c, cmp);
    
    l = 0;
    LL sum = 0;
    for (int i = 0; i < n / 2; i++) {insert(ff[i].c); sum += ff[i].c;}
    for (int i = n / 2; i < c; i++)
    {
        a[i] = sum;
        if (ff[i].c < h[1])
        {
            sum -= h[1];
            sum += ff[i].c;
            h[1] = ff[i].c;
            adjust(1);
        }
    }
    
    
    l = 0;
    sum = 0;
    for (int i = c - 1; i >= c - n / 2; i--) {insert(ff[i].c); sum += ff[i].c;}
    for (int i = c - n / 2 - 1; i > -1; i--)
    {
        b[i] = sum;
        if (ff[i].c < h[1])
        {
            sum -= h[1];
            sum += ff[i].c;
            h[1] = ff[i].c;
            adjust(1);
        }
    }
    
    LL ans = -1;
    for (int i = n / 2; i < c - n / 2; i++) if (a[i] + b[i] + ff[i].c <= f) ans = max(ans, ff[i].v);
    printf("%I64d\n", ans);
}