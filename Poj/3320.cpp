#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
#define N 2000000


namespace SSS
{
    int tmp[N];

    void deal(int a[], int nn)
    {
        for(int i = 0; i < nn; i++) tmp[i] = a[i];
        sort(tmp, tmp + nn);
        int n = unique(tmp, tmp + nn) - tmp;
        for(int i = 0; i < nn; i++) a[i] = lower_bound(tmp, tmp + n, a[i]) - tmp;
    }
}

set<int>dic;
int cnt[N];
int a[N];
int n;
int sz;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    SSS::deal(a, n);

    dic.clear();
    for(int i = 0; i < n; i++) dic.insert(a[i]);
    sz = dic.size();
//    cout << sz << endl;
    int l = 0, r = 0;
    int ans = n;
    dic.clear();
    memset(cnt, 0, sizeof cnt);
    dic.insert(a[0]);
    cnt[a[0]]++;

    while(l < n)
    {
        if(dic.size() == sz) ans = min(ans, r - l + 1);
        if(r < n - 1) { r++; dic.insert(a[r]); cnt[a[r]]++; }
        if(dic.size() == sz) ans = min(ans, r - l + 1);
        bool flg = false;
        while(cnt[a[l]] > 1) { flg = true; cnt[a[l]]--; l++; }
        if(dic.size() == sz) ans = min(ans, r - l + 1);
        // cout << l << " " << r << " " << (dic.size() == sz) << endl;
        if(r == n - 1 && !flg) break;
    }
    printf("%d\n", ans);
    return 0;
}
