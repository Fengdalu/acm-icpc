#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <set>
#include <bitset>
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
#define N 10010

char f[6000];

int main()
{
    freopen("black.in", "r", stdin);
    freopen("black.out", "w", stdout);

    int n, m, s, k;
    scanf("%d%d%d%d", &n, &m, &s, &k);
    scanf("%s", f);

    if(s == 1)
    {
        if(n == 1 && m == 1)
        {
            if(f[0] != '*') printf("Impossible\n");
            else printf("Unique\n");
        }
        else if(n == 2 && m == 1) printf("Unique\n");
        else
        {
            int cnt = 0;
            FOR(i, m) if(f[i] == '*') cnt++;
            if(cnt > 1) printf("Impossible\n");
            else if(cnt == 1) printf("Unique\n");
            else if(n > 1) printf("Ambiguous\n");
            else printf("Impossible\n");
        }
        return 0;
    }

    bool flg = false;
    int L = m + 1, R = -1;
    FOR(i, m) if(f[i] == '*')
    {
        if(i == 0 || f[i - 1] == '.') L = min(L, i);
        if(i == m - 1 || f[i + 1] == '.') R = max(R, i);
    }
    for(int i = L; i <= R; i++) if(f[i] != '*') { printf("Impossible\n"); return 0; }

    if(L <= R)
    {
        if(R - L + 1 != s) { printf("Impossible\n"); return 0; }
        if(n == s || k == 1 || k == n) { printf("Unique\n"); return 0; }
        { printf("Ambiguous\n"); return 0; }
    }
    else
    {
        if(s > k - 1 && s > n - k) { printf("Impossible\n"); return 0; }
        if(s <= k - 1 && s <= n - k) { printf("Ambiguous\n"); return 0; }
        if(m == s && ( (s == k - 1 && s > n - k) || (s > k - 1 && s == n - k) ) ) { printf("Unique\n"); return 0; }
        { printf("Ambiguous\n"); return 0; }
    }

    return 0;
}