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
#define PB(x) push_back(x)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR1(i, n) for(int i = 1; i <= n; i++)
#define N 51


int C[N];
char s[N * N];
bool vis[N];
int n;
deque<int>f;
int len;

int BITS(int x)
{
    int cnt = 0;
    while(x) { cnt++; x /= 10; }
    return cnt;
}

void init()
{
    memset(C, 0, sizeof C);
    FOR1(i, 50) C[i] = C[i - 1] + BITS(i);
}

bool dfs(int p)
{
    if(p == len) return true;
    int x;
    x = s[p]- '0';
    if(x <= n && !vis[x])
    {
        f.PB(x);
        vis[x] = true;
        if(dfs(p + 1)) return true;
        f.pop_back();
        vis[x] = false;
    }
    if(p + 1 < len)
    {
        x = (s[p] - '0') * 10 + s[p + 1] - '0';
        if(x <= n && !vis[x])
        {
            f.PB(x);
            vis[x] = true;
            if(dfs(p + 2)) return true;
            f.pop_back();
            vis[x] = false;
        }
    }
    return false;
}

int main()
{
    freopen("joke.in", "r", stdin);
    freopen("joke.out", "w", stdout);

    init();
    while(~scanf("%s", s))
    {
        f.clear();
        len = strlen(s);
        memset(vis, 0, sizeof vis);
        FOR1(i, 50) if(C[i] == len) { n = i; break; }
        dfs(0);
        while(f.size()) { printf("%d ", f.front()); f.pop_front(); }
    }
    fclose(stdout);
    return 0;
}