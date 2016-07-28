#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

const int N = 100010;
typedef long long ll;
int r[N];
int nxt[N];
char s[N];
char buf[N];
namespace SA
{
    int len;
    int num[N];
    int sa[N], rank[N], height[N]; // sa[1~n]value(0~n-1); rank[0..n-1]value(1..n); height[2..n]
    int wa[N], wb[N], wv[N], wd[N];

    int cmp(int *r, int a, int b, int x) {
        return r[a] == r[b] && r[a + x] == r[b + x];
    }

    void da(int *r, int n, int m) { //  `倍增算法 r为待匹配数组  n为总长度+1 m为字符范围`
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

int main() {
    int _T, cas = 1;
    scanf("%d", &_T);
    while(_T--) {
        scanf("%s%s", buf, s);
        int n = strlen(s);
        for(int i = 0; i < n; i++) r[i] = s[i] - 'a' + 1;
        r[n] = 0;
        SA::da(r, n + 1, 28);
        int p = -1;
        char op = buf[0];
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == op) p = i;
            nxt[i] = p;
        }
        ll ans = 0;
        int pos = SA::sa[1];
        if(~nxt[pos]) {
            ans += n - nxt[pos];
        }
        for(int i = 2; i <= n; i++) {
            int pos = SA::sa[i];
            int h = SA::height[i];
            if(~nxt[pos]) {
                ans += n - max(pos + h, nxt[pos]);
            }
        }
        cout << "Case #" << cas++ << ": " << ans << endl;
    }
    return 0;
}
