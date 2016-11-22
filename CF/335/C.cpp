#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define PII pair<int, int>
#define AA first
#define BB second
#define MP(x, y) make_pair(x, y)
#define SZ size()
#define OP begin()
#define ED end()
#define LL long long

int n;
int c[100010];
int pre[100010];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &c[i]);
    for(int i = 0; i < n; i++) {
        pre[c[i]] = pre[c[i] - 1] + 1;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) ans = max(ans, pre[i]);
    printf("%d\n", n - ans);
    return 0;
}
