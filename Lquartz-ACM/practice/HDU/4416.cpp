#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define OP begin()
#define BG begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
#define Maxn 300111
int kk[Maxn];
//O(nlogn)
//调用da(num, len+1, m);//m为字符个数略大
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

struct RMQ {
    int n;
    int st[20][Maxn];
    void init(int v[], int L) {
        int i, j, k;
        n = L;
        for(i = 0; i <= n; i++) st[0][i] = v[i];
        for(j = 1, k = 0; (1<<j) <= n; j++, k++) {
            for(i = 0; i + (1<<j) - 1<= n; i++) {
                st[j][i] = min(st[j - 1][i], st[j - 1][i + (1<<k)]);
            }
        }
    }
    int query(int l, int r) {   //求[l, r]
//        int k = log2(r - l + 1);
//        int k = 31 - __builtin_clz(r - l + 1);
          int k = kk[r - l + 1];
        return min(st[k][l], st[k][r - (1<<k) + 1]);
    }
//    int query(int l, int r) {   //对于sa, 求原串l, r为起点的之间的height
//        if(l == r) return len - r;
//        int u = rank[l], v = rank[r];
//        if(u > v) swap(u, v);
//        int k = kk[v - (u + 1)+ 1];
//        return min(st[u + 1][k], st[v - (1<<k) + 1][k]);
//    }
}rmq;
LL ans;
int ll[10];
void calc() {
    int * next = wv;
    int i, j, k, u, v, w, pre = 0;
    ans = 0;
    for(i = 0; i <= len + 10; i++) next[i] = -1;
    for(i = len; i > 0; i--) {
        u = sa[i];
        if(u > ll[0]) {
            next[i] = i;
        }
        else {
            next[i] = next[i + 1];
        }
    }
    for(i = 1; i <= len; i++) {
        u = sa[i];
        if(sa[i] < ll[0]) { //string A
            w = 0;
            cmax(w, height[i]);//i-1
            if(next[i] != -1)
            cmax(w, rmq.query(i + 1, next[i]));//next

            ans += (LL)max(0, ll[0] - u - w);
//            printf("add %d %d\n", i, ans);
            pre = i;
        }
    }
}
int n;
char str[100005], a[100005];
int main() {
//    freopen("data.in", "r", stdin);
//    freopen("no.txt", "w", stdout);
    int i,j,u,v,w,k;
    int te;
    scanf("%d", &te);
    for(i = 0; i < Maxn; i++) kk[i] = 31 - __builtin_clz(i);
    for(int ca = 1; ca <= te; ca++) {
        scanf("%d", &n);
        scanf("%s", a);
        w = strlen(a);
        ll[0] = w;
        for(i = 0; i < w; i++) {
            num[i] = a[i] - 'a' + 1;
//            mask[i] = w;
        }
        len = w;
        num[len] = 27;
//        mask[len] = w;
        len++;
        for(i = 1; i <= n; i++) {
            scanf("%s", str);
            w = strlen(str);
            u = w + len;
            for(j = 0; j < w; j++) {
                num[len] = str[j] - 'a' + 1;
//                mask[len] = u;
                len++;
            }
            num[len] = 27;
//            mask[len] = u;
            len++;
        }
        num[len] = 0;
//        mask[len] = -1;
        da(num, len + 1, 30);
//        for(i = 0; i <= len; i++) {
//            printf("%8d %8d ", i, sa[i]);
//            for(j = sa[i]; j <= len; j++) printf("%c", num[j]); printf("\n");
//        }
        rmq.init(height, len);
        calc();
        printf("Case %d: %I64d\n", ca, ans);
    }
    return 0;
}

/*
2
4
aaabbccddabc
aabb
aab
abb
ab

*/
/*
100
2
abab
ab
ba
1
aaa
bbb
2
aaaa
aa
aaa
5
abbc
a
ab
abc
bc
abcd
3
bab
abab
abc
ba
3
abcde
abc
bcd
cde
1
abc
def
1
abc
abc
*/
