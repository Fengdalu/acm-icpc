#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long
#define N 100010
#define M 1000100

int a[N];
int op[M], ed[M], c[M];

using namespace std;

int main()
{
    for(int i = 0; i < M; i++) { op[i] = M; ed[i] = -1; }
    memset(c, 0, sizeof c);

    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) c[a[i]]++;
    for(int i = 0; i < n; i++) { op[a[i]] = min(op[a[i]], i); ed[a[i]] = max(ed[a[i]], i); }
    int m = -1;
    for(int i = 0; i < M; i++) m = max(m, c[i]);
    int l = -M, r = 0;
    for(int i = 0; i < M; i++)
    if(c[i] == m && ed[i] - op[i] < r - l + 1)    {
        l = op[i]; r = ed[i];
    }
    printf("%d %d\n", l + 1, r + 1);
    return 0;
}
