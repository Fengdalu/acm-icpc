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
#define Maxn 4111111
#define Maxm 4111111
//
int MaxRep (char S[], int L) {
    int i = 0, j = 1, k = 0, t;
    while (i < L && j < L && k < L) { //找不到比它还小的 或者 完全匹配
        t = S[ (i + k) % L] - S[ (j + k) % L];
//        t = s[(i + k) >= L ? i + k - L : i + k] 
//            - s[(j + k) >= L ? j + k - L : j + k];
        if (t == 0)
            k++;//相等的话,检测长度加1
        else {
            //大于的话,s[i]为首的肯定不是最小表示,最大表示就改<
            if (t < 0) i += k + 1;
            else j += k + 1;
            if (i == j) j++;
            k = 0;
        }
    }
    return min (i, j);
}
//
int MinRep (char S[], int L) {
    int i = 0, j = 1, k = 0, t;
    while (i < L && j < L && k < L) { //找不到比它还小的 或者 完全匹配
        t = S[ (i + k) % L] - S[ (j + k) % L];
//        t = s[(i + k) >= L ? i + k - L : i + k] 
//            - s[(j + k) >= L ? j + k - L : j + k];
        if (t == 0)
            k++;//相等的话,检测长度加1
        else {
            //大于的话,s[i]为首的肯定不是最小表示,最大表示就改<
            if (t > 0) i += k + 1;
            else j += k + 1;
            if (i == j) j++;
            k = 0;
        }
    }
    return min (i, j);
}
char str[Maxn];
LL h, H, hh;
int L;
int countit(int u) {
    int i, j, ret = 1;
    for(i = u, j = 0, h = 0; j < L; j++, i++) {
        h = ((h * 31) + (str[i] - 'a' + 1)) % MOD;
    }
    for(i = 1, H = 1; i < L; i++) {
        H = ((H * 31)) % MOD;
    }
    hh = h;
    for(i = u + 1, j = 1; j < L; j++, i++) {
        h = ((h - H * (str[i - 1] - 'a' + 1) % MOD + MOD) * 31 + str[i - 1] - 'a' + 1)% MOD;
        if(h == hh) ret++;
    }
    return ret;
}
int main() {
    int i, j, u, v, w;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    int cu, cv;
    while(scanf("%s", str) != EOF) {
        L = strlen(str);
        for(i = L, j = 0; j < L; i++, j++) str[i] = str[j];
        u = MinRep(str, L);
        v = MaxRep(str, L);
        cu = countit(u);
        cv = countit(v);
        printf("%d %d %d %d\n", u + 1, cu, v + 1, cv);
    }
    return 0;
}
