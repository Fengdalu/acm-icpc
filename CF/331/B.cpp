#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
#define SZ size()
#define OP begin()
#define ED end()
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define LL long long

int n;
int b[200010];
int a[200010];

int main() {
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &b[i]);
    int m = 0;
    LL ans = 0;
    for(int i = 0; i < n; i++) { a[i] = m; cmax(a[i], b[i]); ans += max(0, b[i] - m); cmax(m, b[i]); }
    int t = 0;
    for(int i = 0; i < n; i++) if(a[i] - t > b[i]) {
        ans += (a[i] - t - b[i]);
        t += (a[i] - t - b[i]);
    }
    else if(a[i] - t < b[i]) {
        ans += -(a[i] - t - b[i]);
        t -= -(a[i] - t - b[i]);
    }
    printf("%I64d\n", ans);
    return 0;
}
