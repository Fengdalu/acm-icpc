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
int n, len;
int num[Maxn];
int sa[Maxn], rank[Maxn], height[Maxn];
int wa[Maxn], wb[Maxn], wv[Maxn], wd[Maxn];
int cmp(int * r, int a, int b, int x) {
    return r[a] == r[b] && r[a + x] == r[b + x];
}
void da(int * r, int n, int m) {
    int i, j, k, p , * x = wa, * y = wb, * t;
    for(i = 0; i < m; i++) wd[i] = 0;
    for(i = 0; i < n; i++) wd[x[i] = r[i]]++;
    for(i = 1; i < m; i++) wd[i] += wd[i - 1];
    for(i = n - 1; i >= 0; i--) sa[--wd[x[i]]] = i;
    for(j = 1, p = 1; p < n; j <<=1, m = p) {
        for(p = 0, i = n - j; i < n; i++) y[p++] = i;
        for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
        for(i = 0; i < n; i++) wv[i] = x[y[i]];
        for(i = 0; i < m; i++) wd[i] = 0;
        for(i = 0; i < n; i++) wd[wv[i]]++;
        for(i = 1; i < m; i++) wd[i] += wd[i - 1];
        for(i = n - 1;i >= 0; i--) sa[--wd[wv[i]]] = y[i];
        for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++) {
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
        }
    }
    for(i = 0, k = 0; i < n; i++) rank[sa[i]] = i;
    for(i = 0; i < n - 1; height[rank[i++]] = k) {
        for(k ? k-- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k++) ;
    }
}
int sum[2005], belong[Maxn], used[2105];

bool check(int x) {
//    cout << "check " << x << endl;
    int i, j, p, q, cnt;
    for(i = 2; i <= len;) {
        p = belong[sa[i - 1]];
        q = belong[sa[i]];
        if(p != -1 && q != -1 && height[i] >= x && sa[i - 1] + x < sum[p + 1]&& sa[i] + x < sum[q + 1]) {
            for(j = i + 1; j <= len; j++) {
                q = belong[sa[j]];
                if(height[j] < x) break;
            }
            if(j - (i - 1) > (n) / 2) {
                for(p = 1; p <= n; p++) {
                    used[p] = 0;
                }
                for(p = i - 1, cnt = 0; p < j; p++) {
                    q = belong[sa[p]];
                    if(!used[q]) {
                        used[q] = 1;
                        cnt++;
                        if(cnt > (n) / 2) {
                            return true;
                        }
                    }
                }
            }
            i = j;
        }
        else i++;
    }
    return false;
}
char str[10005];

void getans(int x) {
    int i, j, p, q, cnt;
    for(i = 2; i <= len;) {
        p = belong[sa[i - 1]];
        q = belong[sa[i]];
        if(p != -1 && q != -1 && height[i] >= x && sa[i - 1] + x < sum[p + 1]&& sa[i] + x < sum[q + 1]) {
            for(j = i + 1; j <= len; j++) {
                q = belong[sa[j]];
                if(height[j] < x) break;
            }
            if(j - (i - 1) > (n)/ 2) {
                for(p = 1; p <= n; p++) {
                    used[p] = 0;
                }
                for(p = i - 1, cnt = 0; p < j; p++) {
                    q = belong[sa[p]];
                    if(!used[q]) {
                        used[q] = 1;
                        cnt++;
                        if(cnt > (n) / 2) {
                            break;
                        }
                    }
                }
                if(cnt > (n) / 2) {
                    for(p = sa[i - 1], cnt = 0; cnt < x; cnt++) {
                        putchar(num[p + cnt] - 1 + 'a');
                    }
                    printf("\n");
                }
            }
            i = j;
        }
        else i++;
    }
}
int main() {
    int i, j, u, v, w, ca = 0;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    while(scanf("%d", &n) != EOF && n) {
        sum[0] = 0;
        len = 0;
        int dmax = 100000000;
        for(i = 1; i <= n; i++) {
            scanf("%s", str);
            sum[i] = len;
            for(j = 0; str[j]; j++, len++) {
                num[len] = str[j] - 'a' + 1;
                belong[len] = i;
            }
            belong[len] = -1;
            num[len++] = '{' - 'a' + 1;
            cmin(dmax, j);
        }
        num[len] = 0;
        sum[n + 1] = len;
//        for(i = 0; i <= len; i++) cout << belong[i] << " "; cout << endl;
//        for(i = 1; i <= n; i++) cout << sum[i] << " "; cout << endl;
        da(num, len + 1, 30);
//        for(i = 0; i <= len; i++) {
//            cout << i << ": ";
//            for(j = sa[i]; j <= len; j++) cout << (char)(num[j] - 1 + 'a'); cout << endl;
//        }
        int l = 1, r = dmax, mid, ans = -1;
        while(l + 1 < r) {
            mid = (l + r) >> 1;
            if(check(mid)) l = mid;
            else r = mid - 1;
        }
        if(check(r)) ans = r;
        else if(check(l)) ans = l;
        if(ca) printf("\n");
        ca++;
//        cout << ans << endl;
        if(ans == -1) {
            printf("?\n");
        }
        else {
            getans(ans);
        }
    }
    return 0;
}

