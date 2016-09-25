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
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define OP begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)

const double eps = 1e-8;
const LL MOD = 1000000007;
#define Max 210000
int num[Max];
int sa[Max], rank[Max], height[Max];
int wa[Max], wb[Max], wv[Max], wd[Max];
int cmp(int *r, int a, int b, int l) {
    return r[a] == r[b] && r[a + l] == r[b + l];
}

void da(int * r, int n, int m) {
    int i, j, k = 0, p , *x = wa, *y = wb, *t;
    for(int i = 0; i < m; i++) wd[i] = 0;
    for(int i = 0; i < n; i++) wd[x[i] = r[i]]++;
    for(int i = 1; i < m; i++) wd[i] += wd[i-1];
    for(int i = n - 1; i >= 0; i--) sa[--wd[x[i]]] = i;
    for(int j = 1, p = 1; p < n; j *= 2, m = p) {
        for(p = 0, i = n - j; i < n; i++) y[p++] = i;
        for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
        for(i = 0; i < n; i++) wv[i] = x[y[i]];
        for(i = 0; i < m; i++) wd[i] = 0;
        for(i = 0; i < n; i++) wd[wv[i]]++;
        for(i = 1; i < m; i++) wd[i] += wd[i-1];
        for(i = n - 1; i >= 0; i--) sa[--wd[wv[i]]] = y[i];
        for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++) {
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
        }
    }
    for(i = 0; i < n; i++) rank[sa[i]] = i;
    for(i = 0; i < n - 1; height[rank[i++]] = k) {
        for(k?k--:0, j = sa[rank[i]-1]; r[i+k] == r[j+k]; k++);
    }
}

int n, tot;
map<int, int > dmap;
int g[Max], f[Max];
vector<int> ans;
int main() {
    int i, j;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
//    while(scanf("%d", &n) != EOF) {
        scanf("%d", &n);
        for(i = 0; i < n; i++) {
            scanf("%d", &g[n - 1 - i]);
            f[n - i - 1] = g[n - i - 1];
        }
        sort(f, f + n);
        dmap.clear(); tot = 1;
        for(i = 0; i < n; i++) {
            if(dmap[f[i]] == 0) dmap[f[i]] = tot++;
        }
        for(i = 0; i < n; i++) num[i] = dmap[g[i]];
        num[n] = 0;
        da(num, n + 1, tot);
        int l1, l2;
        ans.clear();
        for(i = 1; i <= n; i++) {
            if(sa[i] > 1) {
                l1 = sa[i];
                for(j = l1; j < n; j++) ans.PB(g[j]);
                break;
            }
        }
        for(i = 0, n = l1; i < l1; i++, n++) {
            num[n] = num[i];
        }
        num[n] = 0;
        da(num, n + 1, tot);
//        for(i = 0; i < n; i++) cout << "~ " << num[i] << " "; cout << endl;
        for(i = 1; i <= n; i++) {
            if(n / 2 > sa[i] && sa[i] > 0) {
                for(j = sa[i]; j < n / 2; j++) ans.PB(g[j]);
                for(j = 0; j < sa[i]; j++) ans.PB(g[j]);
                break;
            }
            
        }
        for(i = 0; i < ans.SZ; i++) {
            printf("%d\n", ans[i]);
        }
//    }
    return 0;
}
