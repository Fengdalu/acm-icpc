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
char A[Maxn], B[Maxn];
int n, k;
int sta[Maxn], top, belong[Maxn];
LL ge[Maxn], sum[Maxn];
void outstack(char str[]) {
    cout << "\t " << str << endl;
    for(int i = 0; i <= top; i++) printf(" %2d", sta[i]);
    cout << endl;
    for(int i = 0; i <= top; i++) printf(" %2d", ge[i]);
    cout << endl;
    for(int i = 0; i <= top; i++) printf(" %2d", sum[i]);
    cout << endl;
}
void calc(LL & ans, int o) {
    int i, j, u, v, w, p, h;
    LL cnt;
    top = 0;
    sta[top] = ge[top] = sum[top] = 0;
    for(j = 2; j < len; ) {
        if(height[j] >= k) {
            for(p = j + 1; p < len; p++) if(height[p] < k) break;
            top = 0;
            sta[top] = ge[top] = sum[top] = 0;
            for(i = j; i < p; i++) {
//                cout << "i = " << i << endl;
                u = sa[i];
                h = height[i];
//                cout << "h = " << h << endl;
//                outstack("pre");
                cnt = 0;
                while(top && h <= sta[top]) {
                    cnt += ge[top];
                    top--;
                }
                sta[top + 1] = h;
                ge[top + 1] = cnt;
                sum[top + 1] = sum[top] + cnt * (h - k + 1);
                top++;
//                outstack("mid");
                v = sa[i - 1];
                if((belong[v] ^ 1) == o) ge[top]++, sum[top] += (h - k + 1);
                if(belong[u] == o) {
                    ans += sum[top];
//                    cout << "+ " << i << " " << ans << " " << sum[top] << endl;
                }
                
//                outstack("end");
            }
//            cout << "calc " << j << " " << p << " " << ans << endl;
            j = p;
        }
        else j++;
    }
}
int change(char ch) {
    if('a' <= ch && ch <= 'z') return ch - 'a' + 1;
    else return ch - 'A' + 27;
}
int main() {
    int i, j, u, v, w;
//    freopen("in1.txt", "r", stdin);
    //freopen("", "w", stdout);
    while(scanf("%d", &k) != EOF && k) {
        scanf("%s%s", A, B);
        for(i = 0, len = 0; A[i]; i++, len++) {
            num[len] = change(A[i]);
            belong[len] = 0;
        }
        u = i;
        num[len] = 54;
        belong[len++] = -1;
        for(i = 0; B[i]; i++, len++) {
            num[len] = change(B[i]);
            belong[len] = 1;
        }
        num[len] = 0;
        belong[len] = -1;
        da(num, len + 1, 58);
//        for(i = 0; i <= len; i++) {
//            printf("%2d: %2d ", i, height[i]);
//            for(j = sa[i]; j < len; j++) cout << (char)(num[j] - 1 + 'a'); cout << endl;
//        }
        LL ans = 0;
        calc(ans, 0);
        calc(ans, 1);
        printf("%I64d\n", ans);
    }
    return 0;
}
/*
2
aababaa
abaabaa
1
xx
xx
0
*/
