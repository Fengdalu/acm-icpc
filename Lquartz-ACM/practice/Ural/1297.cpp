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
#define Maxn 11111
#define Maxm 111111
//O(nlogn)
//da(num, len + 1, m);
int len;
int num[Maxn];  //待处理的串
int sa[Maxn], rank[Maxn], height[Maxn];    //sa[1~n]value(0~n-1); rank[0..n-1]value(1..n); height[2..n]
int wa[Maxn], wb[Maxn], wv[Maxn], wd[Maxn];

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
int pos, l, belong[Maxn], pt[Maxn];
char str[Maxn];
int change(char ch) {
    return ch;
    if('a' <= ch && ch <= 'z') return ch - 'a' + 2;
    else return ch - 'A' + 28;
}
char tochange(int x) {
    return x;
    if(x == 1) return '#';
    else if(x < 28) return x - 2 + 'a';
    else return x - 28 + 'A';
}
int main() {
    int i, j, u, v, w;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    while(scanf("%s", str) != EOF) {
//        scanf("%s", str);
        for(i = 0, len = 0; str[i]; i++, len++) {
            num[len] = change(str[i]);
            belong[len] = 0;
            pt[len] = i;
        }
        num[len] = 1;
        belong[len] = -1;
        len++;
        for(i--; i >= 0; i--, len++) {
            num[len] = change(str[i]);
            belong[len] = 1;
            pt[len] = i;
        }
        num[len] = 0;
        da(num, len + 1, 156);
//        for(i = 0; i <= len; i++) {
//            printf("%2d: %2d ", i, height[i]);
//            for(j = sa[i]; j < len; j++) putchar(tochange(num[j])); puts("");
//        }
        l = 1, pos = 0;
        for(i = 2; i <= len; i++) {
            u = sa[i]; v = sa[i - 1];
            if(u > v) swap(u, v);
            if(belong[u] == 0 && belong[v] == 1){
                int h = height[i];
                if(pt[u] + h - 1!= pt[v]) h = -1;
//                cout << i << " " << h << " " << l << " " << u << endl;
                if(h > l) {
                    l = height[i];
                    pos = u;
                }
                else if(h == l) {
                    if(pos > u) pos = u;
                }
            }
        }
        for(i = pos; l > 0; i++, l--) putchar(str[i]); puts("");
    }
    return 0;
}

/*
qwerSOMETEXTrewq
ABCDLKOIKJTFIDCBA

ETE
A
*/
