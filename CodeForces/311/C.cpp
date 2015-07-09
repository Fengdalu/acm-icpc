#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
#define LL long long
#define N 100011

int n;
set<int>f[N];
set<int>::iterator iter;
int cnt[300];
int l[N], d[N];
int sum;

int main()
{
    for(int i = 0; i < N; i++) f[i].clear();
    scanf("%d", &n);
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < n; i++) scanf("%d", &l[i]);
    for(int i = 0; i < n; i++) scanf("%d", &d[i]);
    for(int i = 0; i < n; i++) f[l[i]].insert(d[i]);
    for(int i = 0; i < n; i++) sum += d[i];

    int cc = 0;
    int ANS = 0;
    for (int i = 0; i < N; i++)
    if(f[i].size())
    {
        int ans = 0;
        for(iter = f[i].begin(); iter != f[i].end(); iter++)
            sum -= *iter;

        cc += f[i].size();
        ans += sum;
        int pp = cc;
        for(int i = 0; i < 300 && f[i].size() * 2 <= pp; i++)
        if(cnt[i])
        {
            int tmp = min(cnt[i], pp - f[i].size() * 2);
            tmp = max(tmp, 1);
            pp -= tmp;
            ans += tmp * i;
        }
        ANS = min(ans, ANS);
    }
    return 0;
}
