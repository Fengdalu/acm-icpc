#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cassert>
#include <iostream>
using namespace std;

const int maxn = 2000;
int n;
int x[maxn], y[maxn];
int cal(int x, int y, int a, int b) {
    if(x == a) {
        if(b > y) return 0;
        return 2;
    }
    if(y == b) {
        if(a > x) return 1;
        return 3;
    }
    return -1;
}

int main() {
    scanf("%d", &n);
    int a, b;
    scanf("%d%d", &a, &b);
    int d = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int p, q;
        scanf("%d%d", &p, &q);
        int dl = cal(a, b, p, q);
        assert(dl != -1);
        if((dl + 1) % 4 == d) ans++;
        d = dl;
        a = p; b = q;
    }
    cout << ans << endl;
}
