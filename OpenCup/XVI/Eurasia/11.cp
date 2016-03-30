#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int v[100010];
int n, m;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) v[i] = 1e9;
    for(int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        v[x] = min(v[x], y);
    }
    sort(v, v + n);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(m >= v[i]) {
            m -= v[i];
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
