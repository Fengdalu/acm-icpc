#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
#define LL long long
#define N 100010

int n;
multiset<int>f[N];
multiset<int>::iterator iter;
LL cnt[300];
int l[N], d[N];
LL sum;

int main()
{
    for(int i = 0; i < N; i++) f[i].clear();
    scanf("%d", &n);
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < n; i++) scanf("%d", &l[i]);
    for(int i = 0; i < n; i++) scanf("%d", &d[i]);
    for(int i = 0; i < n; i++) f[l[i]].insert(d[i]);
    for(int i = 0; i < n; i++) sum += (LL)d[i];



    LL SUM = sum;
    int cc = 0;
    LL ANS = 11111111111;

    for (int i = 0; i < N; i++)
    if(f[i].size())
    {
        LL ans = 0;

        for(iter = f[i].begin(); iter != f[i].end(); iter++)
            sum -= *iter;


        cc += f[i].size();
        //cout << f[i].size() << " " << cc << " " << ans << endl;
        ans += sum;
        int pp = cc;

        LL ccc = pp - f[i].size() * 2 + 1;
        //cout << ccc << " " << ans << endl;
        for(int j = 0; j < 300 && ccc > 0; j++)
        if(cnt[j])
        {
            int tmp = min(cnt[j], ccc);
            tmp = max(tmp, 1);
            ccc -= tmp;
            ans += tmp * j;
        }

        for(iter = f[i].begin(); iter != f[i].end(); iter++) cnt[*iter]++;
        ANS = min(ans, ANS);
        //cout << ans << " " << sum << endl;
    }

    for(int i = 0; i < N; i++)
    if(f[i].size() >= 2)
    {
        iter = f[i].begin();
        iter++;
        ANS = min(ANS, SUM - *f[i].begin() - *iter);
    }

    for(int i = 0; i < N; i++)
    if(f[i].size())
        ANS = min(ANS, SUM - *f[i].begin());
    printf("%I64d\n", ANS);
    return 0;
}
