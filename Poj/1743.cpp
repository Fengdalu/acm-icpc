#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;
const int N = 300010;


namespace SA
{
    int len;
    int num[N];  //待处理的串
    int sa[N], rank[N], height[N];    //sa[1~n]value(0~n-1); rank[0..n-1]value(1..n); height[2..n]
    int wa[N], wb[N], wv[N], wd[N];

    int cmp(int *r, int a, int b, int x) {
        return r[a] == r[b] && r[a + x] == r[b + x];
    }

    void da(int *r, int n, int m) {       //  倍增算法 r为待匹配数组  n为总长度+1 m为字符范围
        int i, j, k, p, *x = wa, *y = wb, *t;
        for(i = 0; i < m; i++) wd[i] = 0;
     for(i = 0; i < n; i++) wd[x[i] = r[i]]++;
        for(i = 1; i < m; i++) wd[i] += wd[i - 1];
        for(i = n - 1; i >= 0; i--) sa[--wd[x[i]]] = i;
        for(j = 1, p = 1; p < n; j <<= 1, m = p) {
            for(p = 0, i = n - j; i < n; i++) y[p++] = i;
            for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
            for(i = 0; i < n; i++) wv[i] = x[y[i]];
            for(i = 0; i < m; i++) wd[i] = 0;
            for(i = 0; i < n; i++) wd[wv[i]]++;
            for(i = 1; i < m; i++) wd[i] += wd[i - 1];
            for(i = n - 1; i >= 0; i--) sa[--wd[wv[i]]] = y[i];
            for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++) {
                x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
            }
        }

        for(i = 0, k = 0; i < n; i++) rank[sa[i]] = i;
        for(i = 0; i < n - 1; height[rank[i++]] = k) {
            for(k ? k-- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k++);
        }
    }
}
using namespace SA;
int n, m;
int c[N];

bool ok(int l)
{
    int mn = n, mx = 0;
    for(int i = 1; i < n; i++)
    {
        if(height[i] < l)
        {
            if(mn + l <= mx) return true;
            mn = sa[i]; mx = sa[i];
        }
        else
        {
            mn = min(mn, sa[i]);
            mx = max(mx, sa[i]);
        }
    }
    if(mn + l <= mx) return true;
    mn = n; mx = 0;
    return false;
}

int main()
{
//    freopen("input.txt", "r", stdin);
    while(true)
    {
        scanf("%d", &n);
        if(!n) break;
        for(int i = 0; i < n; i++) scanf("%d", &c[i]);
        n--;
        for(int i = 0; i < n; i++) num[i] = c[i + 1] - c[i] + 88;
        m = 0; for(int i = 0; i < n; i++) m = max(num[i], m);
        c[n] = 0;
        da(num, n + 1, m + 1);

        int l = 1, r = n;
        while(l < r)
        {
            int mid = (l + r) / 2 + 1;
            if(ok(mid)) l = mid;
            else r = mid - 1;
        }
        l++;
//        cout << l << endl;
        printf("%d\n", (l >= 5) ? l : 0);
    }
    return 0;
}
