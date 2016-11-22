#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
#define PII pair<int, int>
#define MP(a, b) make_pair(a, b)
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define PB(x) push_back(x)
#define SZ size()
#define LL long long
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORR(i, n) for(int i = 1; i <= n; i++)


bool vis1[100];
bool vis2[100];

int main()
{
    int n; scanf("%d", &n);
    memset(vis1, 0, sizeof vis1);
    memset(vis2, 0, sizeof vis2);
    FOR(i, n * n)
    {
        int x, y; scanf("%d%d", &x, &y);
        if(!vis1[x] && !vis2[y]) { vis1[x] = vis2[y] = true;  printf("%d ", i + 1); }
    }
    return 0;
}
