#include <bits/stdc++.h>

using namespace std;

const int N = 300005;
const int inf = 1e9+7;
int n;
int c[N], d[N];
int f[N];
int g[N];

int main() {
    int n; scanf("%d", &n);
    int cur = inf;
    for(int i = 0; i < n; i++) scanf("%d%d", c + i, d + i);
    bool flag = true;
    for(int i = 0; i < n; i++) {
        if(d[i] == 2) flag = false;
    }
    if(flag) {
        printf("Infinity\n");
        return 0;
    }
    int s = 0;
    for(int i = 0; i < n; i++) {
        f[i] = s;
        s += c[i];
    }

    int d1 = inf, d2 = -inf;
    for(int i = 0; i < n; i++) {
        if(d[i] == 1) d1 = min(d1, f[i]);
        else d2 = max(d2, f[i]);
    }
    if(d1 <= d2) {
        puts("Impossible");
        return 0;
    }
    printf("%d\n", f[n - 1] - d2 + c[n - 1] + 1899);
    return 0;
}



