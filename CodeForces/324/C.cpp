#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <bitset>
#include <map>
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
#define FORR(i, n) for(int i = 1; i <= n; i++)
#define u32 unsigned int

char a[100010], b[100010];
char c[100010];
bool vis[100010];
int n, t;

char mm(char a, char b)
{
    if(min(a, b) == 'a' && max(a, b) == 'z') return 'c';
    if(min(a, b) != 'a') return 'a';
    return 'z';
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> t;
    t = n - t;
    cin >> a >> b;
    memset(vis, 0, sizeof vis);
    memset(c, 0, sizeof c);

    FOR(i, n) if(a[i] == b[i]) vis[i] = true;
    FOR(i, n) if(t && vis[i]) { t--; c[i] = a[i]; }

    if(t)
    {
        int t1 = t, t2 = t;

        FOR(i, n) if(!vis[i] && t1) { c[i] = a[i]; vis[i] = true; t1--; }
        FOR(i, n) if(!vis[i] && t2) { c[i] = b[i]; vis[i] = true; t2--; }
        if(t1 || t2) printf("-1\n");
        else        {
            FOR(i, n) if(!vis[i]) c[i] = mm(a[i], b[i]);
            cout << c << endl;
        }
    }
    else
    {
        FOR(i, n) if(c[i] == 0) c[i] = mm(a[i], b[i]);
        cout << c << endl;
    }
    return 0;
}
