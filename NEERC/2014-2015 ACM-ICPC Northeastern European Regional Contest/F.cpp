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
#define FOR1(i, n) for(int i = 1; i <= n; i++)
#define M 1020

vector< bitset<M> >s;
bitset<M> d[M];
vector<int>ans;
int n;
int m, f;
int a[M];
char buf[M];



inline int num(char s) { if('0' <= s && s <= '9') return s - '0'; return s - 'a' + 10; }

int main()
{
    freopen("filter.in", "r", stdin);
    freopen("filter.out", "w", stdout);

    scanf("%d%d", &m, &f);

    FOR(i, f)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &n);
    int len = (m + 3) / 4;
    FOR(i, n)
    {
        scanf("%s", buf);
        int bits = 0;
        d[i].reset();
        for(int j = len - 1; j > -1; j--)
        {
            d[i] <<= 4;
            d[i] |= num(buf[j]);
        }
    }

    int q; scanf("%d", &q);
    s.clear();
    FOR(i, q)
    {
        LL u; scanf("%I64d", &u);
        bitset<M>b; b.reset();
        FOR(j, f)
        {
            b.set((u * (LL)a[j]) % m);
        }
        s.PB(b);
    }
    ans.clear();
    FOR(i, n)
    {
        FOR(j, s.SZ)
        {
            if((s[j] & d[i]) == s[j])
            {
                ans.PB(i);
                break;
            }
        }
    }
    printf("%d ", ans.SZ);
    FOR(i, ans.SZ) printf("%d ", ans[i]);
    fclose(stdout);
    return 0;
}