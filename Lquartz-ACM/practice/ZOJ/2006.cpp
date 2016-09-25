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
#define Maxn 111111
#define Maxm 111111
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
int L;
int main() {
    int i, j, u, v, w;
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    int te;
    scanf("%d", &te);
    while(te--) {
        scanf("%s", str);
        L = strlen(str);
        u = MinRep(str, L);
        printf("%d\n", u);
    }
    return 0;
}

