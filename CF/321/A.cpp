#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define FOR(i, n) for(int i = 0; i < n; i++)
#define AA first
#define BB second
#define PB(x) push_back(x)
#define SZ size()
#define MP(a, b) make_pair(a, b)
#define OP begin()
#define ED end()
#define CLR clear()
#define CLR(a, b) memset(a, b, sizeof a)
typedef pair<int, int> PII;
#define N 100010

int H[N];
int cnt;
int n;
int q[N], a[N];
int c[N];
int f[N];

int lowbit(int x) { return x & (-x); }

int qry(int x)
{
    int ans = -1;
    while(x > 0)
    {
        ans = max(ans, c[x]);
        x -= lowbit(x);
    }
    return ans;
}

void insert(int x, int cc)
{
    while(x <= n)
    {
        c[x] = max(c[x], cc);
        x += lowbit(x);
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    int ans = 1;
    int tmp = 1;
    for(int i = 1; i < n; i++)
    {
        if(a[i] >= a[i - 1]) tmp++;
        else tmp = 1;
        ans = max(ans, tmp);
    }
    printf("%d\n", ans);
    return 0;
}
