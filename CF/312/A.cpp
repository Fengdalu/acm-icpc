#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long
#define N 200

struct node
{
    int p, c;
}f1[N], f2[N];
int cnt1 = 0, cnt2 = 0;

int cmp1(node a, node b)
{
    return a.p > b.p;
}

int cmp2(node a, node b)
{
    return a.p < b.p;
}

int main()
{
    int n; scanf("%d", &n);
    int x;
    for(int i = 0; i < n; i++)
    {
        int p, c; scanf("%d%d", &p, &c);
        if(p < 0) { f1[cnt1].p = p; f1[cnt1].c = c; cnt1++; }
        else { f2[cnt2].p = p; f2[cnt2].c = c; cnt2++; }
    }
    sort(f1, f1 + cnt1, cmp1);
    sort(f2, f2 + cnt2, cmp2);
    int c = min(cnt1, cnt2) + 1;
    LL ans = 0;
    for(int i = 0; i < c && i < cnt1; i++) ans += (LL)f1[i].c;
    for(int i = 0; i < c && i < cnt2; i++) ans += (LL)f2[i].c;
    printf("%I64d\n", ans);
    return 0;
}
