#include <cstdio>
#include <iostream>
#include <cstring>
#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;

int q[11111111];
int c[11111111];
int a[11111111];
int ans1[1111111];
int ans2[1111111];
int l, r;
int k;

void insert(int x, int i)
{
    if (r == -1) {q[++r] = x; c[r] = i;}
    else
    {
        while(l <= r && c[l] < i - k + 1) l++;
        while(l <= r && q[r] >= x) r--;
        while(l <= r && q[l] >= x) l++;
        q[++r] = x;
        c[r] = i;
    }
}

void insert1(int x, int i)
{
    if (r == -1) {q[++r] = x; c[r] = i;}
    else
    {
        while(l <= r && c[l] < i - k + 1) l++;
        while(l <= r && q[r] <= x) r--;
        while(l <= r && q[l] <= x) l++;
        q[++r] = x;
        c[r] = i;
    }
}

int main()
{
    int n;
    int x;
    scanf("%d%d", &n, &k);
    rep(i, n) scanf("%d", &a[i]);
    l = 0;
    r = -1;
    rep(i, n)
    {
        insert(a[i], i);
        ans1[i] = q[l];
    }
    l = 0;
    r = -1;
    
    rep(i, n)
    {
        insert1(a[i], i);
        ans2[i] = q[l];
    }
    for(int i = k - 1; i < n; i++) if (i != n - 1)  printf("%d ", ans1[i]); else printf("%d\n", ans1[i]);
    for(int i = k - 1; i < n; i++) if (i != n - 1)  printf("%d ", ans2[i]); else printf("%d\n", ans2[i]);
    return 0;
}