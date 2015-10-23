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
#define ONES(x) __builtin_popcount(x)

LL num(char c)
{
    if(c == '#') return 62;
    if('0' <= c && c  <= '9') return c - '0';
    if('a' <= c && c  <= 'z') return c - 'a' + 10;
    if('A' <= c && c  <= 'Z') return c - 'A' + 10 + 26;
}

LL ELFhash(char *str)
{
    LL ans = 0;
    while(*str)
    {
        ans = ans * 63LL + num(*str);
        str++;
    }
    return ans;
}

map<LL, int>f[(1 << 6)];
LL cnt[10];
char s[50001][10];
char buf[10];
LL ans[10];
int n;

int main()
{
    freopen("high.in", "r", stdin);
    freopen("high.out", "w", stdout);

    FOR(i, (1 << 6)) f[i].clear();
    scanf("%d", &n);

    memset(buf, 0, sizeof buf);
    FOR(i, n) scanf("%s", s[i]);
//    FOR(i, n)
//        FOR(j, (1 << 6))
//        {
//            FOR(k, 5)
//            if(j & (1 << k))
//            {
//                buf[k] = s[i][k];
//            }
//            else buf[k] = '#';
//            //f[j][ELFhash(buf)] += 1;
//        }

    memset(ans, 0, sizeof ans);
    FOR(i, n)
    {
        //memset(cnt, 0, sizeof cnt);
        FOR(j, 32)
        {
            FOR(k, 5)
            if(j & (1 << k))
            {
                buf[k] = s[i][k];
            }
            else buf[k] = '#';
            ans[5 - ONES(j)] += f[j][ELFhash(buf)];
//            if(f[j][ELFhash(buf)])cout << s[i] << " " << j << " " << buf << " " << 5 - ONES(j) << " " << f[j][ELFhash(buf)] << endl;
            f[j][ELFhash(buf)] += 1;
            //cnt[5 - ONES(j)] += n - f[j][ELFhash(buf)];
        }
        //for(int j = 4; j >= 0; j--) cnt[j + 1] -= cnt[j];
        //FOR(j, 6) ans[j] += cnt[j];
    }
//    FOR(i, 6) printf("%d ", ans[i]);
//    puts("");
    cnt[0] = ans[0];
    cnt[1] = ans[1] - ans[0] * 5LL;
    cnt[2] = ans[2] - ans[1] * 4LL + ans[0] * 10LL;
    cnt[3] = ans[3] - ans[2] * 3LL + ans[1] * 6LL - ans[0] * 10LL;
    cnt[4] = ans[4] - ans[3] * 2LL + ans[2] * 3LL - ans[1] * 4LL + ans[0] * 5LL;
    cnt[5] = ans[5] - ans[4] + ans[3] - ans[2] + ans[1] - ans[0];
    cout << cnt[0];
    for(int i = 1; i <= 5; i++)
        cout << " " << cnt[i];
    cout << endl;
    return 0;
}