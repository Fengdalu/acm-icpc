#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

pair<int, int> cal(int x) {
    for(int i = x + 1; i <= 1e9; i++) {
        LL fz = i - x;
        LL fm = 1LL * i * x;
        LL g = __gcd(fz, fm);
        if(g) {fz /= g; fm /= g;}
        if(fz == 1 && fm != i && i != x && fm != x) return make_pair(i, fm);
    }
    return make_pair(-1, -1);
}


int main() {
    int n; scanf("%d", &n);
    if(n <= 1) puts("-1");
    else {
        auto t = cal(n);
        printf("%d %d %d\n", n, t.first, t.second);
    }
    return 0;
}
