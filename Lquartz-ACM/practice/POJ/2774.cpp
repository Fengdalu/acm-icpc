#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
 
#define PB push_back
#define PF push_front
#define PPB pop_back
#define PPF pop_front
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define OP begin()
#define ED end()
#define SORT(x) sort(x.begin(), x.end())
#define SQ(x) ((x)*(x))
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)
 
const double eps = 1e-8;
const LL MOD = 1000000007;
const LL INF = 0x3f3f3f3f;
#define Maxn 211111
#define Maxm 111111

int len;
int num[Maxn];
int sa[Maxn], rank[Maxn], height[Maxn];
int wa[Maxn], wb[Maxn], wv[Maxn], wd[Maxn];
int cmp(int * r, int a, int b, int x) {
    return r[a] == r[b] && r[a + x] == r[b + x];
}
void da(int * r, int n, int m) {
    int i, j, k = 0, p, *x = wa, *y = wb, * t;
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
char str[Maxn];

int main() {
    int i, j, u, v, w;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    while(scanf("%s", str) != EOF) {
        for(i = 0; str[i]; i++) num[i] = str[i] - 'a' + 1;
        len = u = i;
        num[len++] = 29;
        scanf("%s", str);
        for(i = 0; str[i]; i++) num[i + len] = str[i] - 'a' + 1;
        len += (v = i);
        num[len] = 0;
//        cout << u << " " << v << " " << len << endl;
//        for(i = 0; i <= len; i++) cout << (char)num[i]; cout << endl;
        da(num, len + 1, 300);
        int ans = 0;
        for(i = 2; i <= len; i++) {
            if(height[i] <= ans) continue;
            if((sa[i] < u && sa[i - 1] > u) || (sa[i] > u && sa[i - 1] < u)) ans = height[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}

