#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <cstring>
#include <map>

const int maxn = 3010;
int x[maxn], y[maxn], q[maxn];
char buf[10];
int h[maxn];
int n;
int dir['z'];
int l[maxn], r[maxn], u[maxn], d[maxn];
int l1[maxn], r1[maxn], u1[maxn], d1[maxn];
int s[maxn][maxn];

int main() {
    freopen("B.in", "r", stdin);
    dir['<'] = 0;
    dir['v'] = 1;
    dir['>'] = 2;
    dir['^'] = 3;

    scanf("%d", &n);Ķ
    for(int i = 0; i < n; i++) {
        scanf("%d%d%s", &x[i], &y[i], buf);
        q[i] = dir[buf[0]];
    }
    int cnt;
    for(int i = 0; i < n; i++) h[i] = x[i];
    std::sort(h, h + n);
    cnt = std::unique(h, h + n) - h;
    for(int i = 0; i < n; i++) x[i] = std::lower_bound(h, h + cnt, x[i]) - h + 1;
    for(int i = 0; i < n; i++) h[i] = y[i];
    std::sort(h, h + n);
    cnt = std::unique(h, h + n) - h;
    for(int i = 0; i < n; i++) y[i] = std::lower_bound(h, h + cnt, y[i]) - h + 1;

    memset(s, 0, sizeof s);
    for(int i = 0; i < n; i++) {
        s[x[i]][y[i]] = i + 1;
    }
    for(int i = 0; i < n; i++) {
        int a, b;

        a = x[i] - 1;
        b = y[i];
        while(a > 0 && s[a][b] == 0) a--;
        l[i + 1] = s[a][b];

        a = x[i] + 1;
        b = y[i];
        while(a < n && s[a][b] == 0) a++;
        r[i + 1] = s[a][b];

        a = x[i];
        b = y[i] - 1;
        while(b > 0 && s[a][b] == 0) b--;
        u[i + 1] = s[a][b];

        b = y[i] + 1;
        while(b < n && s[a][b] == 0) b++;
        d[i + 1] = s[a][b];
    }

    for(int i = 1; i <= n; i++) l1[i] = l[i];
    for(int i = 1; i <= n; i++) r1[i] = r[i];
    for(int i = 1; i <= n; i++) d1[i] = d[i];
    for(int i = 1; i <= n; i++) u1[i] = u[i];

    int ans = 0;
    for(int p = 0; p < n; p++) {
        for(int i = 1; i <= n; i++) l[i] = l1[i];
        for(int i = 1; i <= n; i++) r[i] = r1[i];
        for(int i = 1; i <= n; i++) d[i] = d1[i];
        for(int i = 1; i <= n; i++) u[i] = u1[i];
        int tot = 0;
        int x = p + 1, t;
        while(true) {
            if(x == 0) break;
            tot++;
            if(q[x - 1] == 0) t = l[x];
            else if(q[x - 1] == 2) t = r[x];
            else if(q[x - 1] == 3) t = u[x];
            else t = d[x];
            int a, b;
            a = l[x]; b = r[x];
            r[a] = b;
            l[b] = a;
            a = u[x]; b = d[x];
            d[a] = b;
            u[b] = a;
            x = t;
        }
        ans = std::max(ans, tot);
    }
    printf("%d\n", ans);
    return 0;
}
