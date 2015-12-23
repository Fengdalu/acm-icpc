#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define PII pair<int, int>
#define LL long long
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)

char a[200010], b[200010];
int l[200010], r[200010];
int pre[200010], suc[200010];
LL sum;

int main() {
    scanf("%s%s", a + 1, b + 1);
    int n = strlen(a + 1);
    int m = strlen(b + 1);
    for(int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1];
        if(a[i] == '1') pre[i]++;
    }
    for(int i = 1; i <= m; i++) {
        if(m - n + 1 >= i) l[i] = 1; else l[i] = n - (m - i);
        if(n <= i) r[i] = n; else r[i] = i;
    }
    LL ans = 0;
    for(int i = 1; i <= m; i++) {
        int L = l[i], R = r[i];
        LL one = pre[R] - pre[L - 1];
        LL zero = (R - L + 1) - one;
        if(b[i] == '1') ans += zero;
        else ans += one;
    }
    cout << ans << endl;
    return 0;
}
