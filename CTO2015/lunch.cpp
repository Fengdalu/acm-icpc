#include <cstring>
#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <iostream>

const int N = 7000;
typedef long long ll;
int a[N], b[N], c[N], d[N];
ll s[N*N];
int x, y, z, p;

int main() {
    int up;
    while(true) {
        int up;
        scanf("%d%d%d%d%d", &up, &x, &y, &z, &p);
        if(up + x + y + p == 0) break;
        for(int i = 0; i < x; i++) scanf("%d", a + i);
        for(int i = 0; i < y; i++) scanf("%d", b + i);
        for(int i = 0; i < z; i++) scanf("%d", c + i);
        for(int i = 0; i < p; i++) scanf("%d", d + i);
        int cnt = 0;
        for(int i = 0; i < x; i++) for(int j = 0; j < y; j++) {
            s[cnt++] = 1ll * a[i] + b[j];
        }
        std::sort(s, s + cnt);
        ll ans = 0;
        for(int i = 0; i < z; i++) for(int j = 0; j < p; j++) {
            if(1ll * c[i] + d[j] > up) continue;
            ans += 1ll * (std::upper_bound(s, s + cnt, up - 1ll * c[i] - d[j]) - s);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
/*
11 3 1 1 1
4 5 6
3
2
1

10 4 5 4 2
3 2 5 7
1 1 8 4 2
3 5 2 1
2 3

0 0 0 0 0
*/
