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
#define Maxn 804111
#define Maxm 111111
int belong[Maxn];
//int st[Maxn][21];
int leng[Maxn];
//O(nlogn)
int n, m;
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

//void rmq_init() {
//    int i, j;
//    for(i = 0; i <= n; i++) st[i][0] = height[i];
//    for(j = 1; (1<<j) <= n; j++) {
//        for(i = 0; i + (1<<j) - 1 <= n; i++) {
//            st[i][j] = min(st[i][j - 1], st[i + (1<<(j - 1))][j - 1]);
//        }
//    }
//}
//int rmq(int l, int r) {
//    int k = (int)log2(r - l + 1);
//    return min(st[l][k], st[r - (1<<k) + 1][k]);
//}
int visit[Maxn];
int check(int x) {
    int i, j, l, r, mid, k, cnt;
//    cout << "check " << x << endl;
    for(i = 2; i <= n; ) {
        if(height[i] >= x && min(leng[sa[i]], leng[sa[i - 1]]) >= x) {
            for(j = i + 1; j <= n && height[j] >= x && leng[sa[j]] >=x; j++);
            for(k = 0; k < m; k++) visit[k] = 0;
            for(k = i - 1, cnt = 0; k < j; k++) {
                if(!visit[belong[sa[k]]]) {
                    visit[belong[sa[k]]] = 1;
                    cnt++;
                }
            }
            if(cnt == m) return sa[i];
//            cout << "\t" << i - 1 <<" " <<j << endl;
            i = j + 1;
        }
        else i++;
    }
    return -1;
}
char str[10000];
int main() {
    int i, j, k, u, v, w;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
//    cout << sizeof(st) << endl;
    while(scanf("%d", &m) != EOF && m) {
        int len = 0, dmin = MOD;
        for(i = 0; i < m; i++) {
            scanf("%s", str);
            k = strlen(str);
            for(j = 0, k; str[j]; j++, k--) {
                num[len] = str[j] - 'a' + 1;
                leng[len] = k;
                belong[len++] = i;
            }
            cmin(dmin, j);
            num[len] = 28;
            leng[len] = -1;
            belong[len++] = -1;
        }
        num[len] = 0;
        n = len;
        da(num, len + 1, 30);
//        cout << "da " << endl;
//        for(i = 0; i <= n; i++) {
//            cout << i << ": ";
//            for(j = sa[i]; j < n; j++) cout << (char)(num[j] - 1 + 'a'); cout << endl;
//        }
//        rmq_init();
        int l = 1, r = j, mid;
        while(l + 1 < r) {
//            cout << "binary " << l << " " << r << endl;
            mid = (l + r) >> 1;
            if(check(mid) != -1) {
                l = mid;
            }
            else r = mid - 1;
        }
        int p = check(r), q = check(l);
        if(p != -1) l = r, q = p;
        if(q == -1) {
            printf("IDENTITY LOST\n");
        }
        else {
            for(i = q, j = 0; j < l; j++, i++) printf("%c", num[i] - 1 + 'a');
            printf("\n");
        }
    }
    return 0;
}

