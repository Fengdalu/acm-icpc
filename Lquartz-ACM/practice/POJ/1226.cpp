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

int n, len, num[Maxn];
int sa[Maxn], rank[Maxn], height[Maxn];
int wa[Maxn], wb[Maxn], wv[Maxn], wd[Maxn];
int belong[Maxn];

int cmp(int * r, int a, int b, int l) {
    return r[a] == r[b] && r[a + l] == r[b + l];
}

void da(int * r, int n, int m) {
    int i, j, k = 0, p, * x = wa, * y = wb, * t;
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
            x[sa[i]] =  cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
        }
    }
    for(i = 0, k = 0; i < n; i++) rank[sa[i]] = i;
    for(i = 0; i < n - 1; height[rank[i++]] = k) {
        for(k ? k-- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k++);
    }
}

char str[Maxn];
int L[Maxn];
int head[111][2];
int used[Maxn];
bool check(int x) {
    int i, j, k, p, q, fp, fq;
    for(i = 2; i <= len; ) {
        if(height[i] >= x) {
            for(j = i + 1; j <= len; j++) {
                if(height[j] < x) break;
            }
            for(p = 0; p < n; p++) used[p] = 0;
            for(p = i - 1; p < j; p++) {
                q = belong[p]; k = sa[p];
                if(q == -1 || ( k < head[q][1] - 1&& k + x >= head[q][1])
                   || (k + x >= head[q + 1][0])) continue;
                used[q] = 1;
            }
            for(p = 0; p < n; p++) {
                if(!used[p]) break;
            }
            if(p >= n) return true;
            i = j;
        }
        else {
            i++;
        }
    }
    return false;
}

int main() {
    int i, j, u, v, w;
    int te;
    scanf("%d", &te);
    while(te--) {
        scanf("%d", &n);
        len = 0;
        w = 100;
        for(i = 0; i < n; i++) {
            scanf("%s", str);
            head[i][0] = len;
            for(j = 0; str[j]; j++, len++) {
                num[len] = str[j];
            }
            cmin(w, j);
            L[i] = j;
            num[len++] = '$';
            head[i][1] = len;
            for(j--; j >= 0; j--, len++) {
                num[len] = str[j];
            }
            num[len++] = '#';
        }
        num[len] = 0;
        head[n][0] = len;
        da(num, len, 300);
        for(i = 1; i <= len; i++) {
            u = sa[i];
            for(j = 0; j < n; j++) {
                if((head[j][0] <= u && u < head[j][1] - 1) 
                   || (head[j][1] <= u && u < head[j + 1][0] - 1)) {
                    belong[i] = j;
                    break;
                }
            }
            if(j >= n) belong[i] = -1;
        }
        int ans = 0;
        int l = 1, r = w, mid;
        while(l + 1 < r) {
            mid = (l + r) >> 1;
            if(check(mid)) l = mid;
            else r = mid - 1;
        }
        if(check(r)) ans = r;
        else if(check(l)) ans = l;
        printf("%d\n", ans);
    }
    return 0;
}

