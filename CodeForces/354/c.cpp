#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int f[maxn], g[maxn];
char s[maxn];
int n, k;

bool check(int x) {
    for(int i = x; i <= n; i++) {
        int tota = x - (f[i] - f[i - x]);
        int totb = x - (g[i] - g[i - x]);
        if(tota <= k || totb <= k) return true;
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &k);
    scanf("%s", s + 1);
    for(int i = 1; i <= n; i++) {
        f[i] = f[i - 1];
        g[i] = g[i - 1];
        if(s[i] == 'a') f[i]++;
        if(s[i] == 'b') g[i]++;
    }
    int l = 0, r = n;
    while(l < r) {
        int mid = (l + r + 1) / 2;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    printf("%d\n", l);
    return 0;
}

