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
#define Maxn 21111
#define Maxm 21111

int n;
int num[Maxn];
int sa[Maxn], rank[Maxn], height[Maxn];    //sa[1~n]value(0~n-1); rank[0..n-1]value(1..n); height[2..n]
int wa[Maxn], wb[Maxn], wv[Maxn], wd[Maxn];

int cmp( int *r, int a, int b, int l ) {
	return r[a] == r[b] && r[a + l] == r[b + l];
}

void da( int *r, int n, int m ) {       //  倍增算法 r为待匹配数组  n为总长度+1 m为字符范围
	int i, j, k = 0, p, *x = wa, *y = wb, *t;
	for(i = 0; i < m; i++) wd[i] = 0;
	for(i = 0; i < n; i++) wd[x[i] = r[i]]++;
	for(i = 1; i < m; i++) wd[i] += wd[i - 1];
	for(i = n - 1; i >= 0; i--) sa[--wd[x[i]]] = i;
	for(j = 1, p = 1; p < n; j *= 2, m = p) {
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

bool check(int x) {
    int dmax = -1, dmin = Maxn;
    int i;
    for(i = 1; i < n; i++) {
        if(height[i] >= x) {
            cmax(dmax, sa[i]);
            cmin(dmin, sa[i]);
            cmax(dmax, sa[i - 1]);
            cmin(dmin, sa[i - 1]);
        }
    }
    if(dmax - dmin > x) return true;
    else return false;
}

int main() {
    int i, j, u, v, w;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    while(scanf("%d", &n) != EOF && n) {
        for(i = 0; i < n; i++) scanf("%d", &num[i]);
        if(n == 1) { printf("0\n"); continue; }
        for(i = 0; i < n - 1; i++) num[i] = num[i + 1] - num[i] + 90;
        num[n - 1] = 0;
        da(num, n, 200);
        int ans = -1;
        int l = 4, r = n / 2, mid;
        while(l < r - 1) {
            mid = (l + r) >> 1;
            if(check(mid)) l = mid;
            else r = mid - 1;
        }
        if(check(r)) ans = r;
        else if(check(l)) ans = l;
        printf("%d\n", ans + 1);
    }
    return 0;
}
