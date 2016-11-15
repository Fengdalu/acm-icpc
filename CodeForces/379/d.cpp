#include <bits/stdc++.h>

int gcd(int x, int y) {
    if(y == 0) return x;
    return gcd(y, x % y);
}
typedef long long LL;

int main() {
    int n, a, b; scanf("%d%d%d", &n, &a, &b);
    std::map< std::pair<LL, LL>, std::vector< std::pair<LL, char> > > f;
    char buf[10];
    for(int i = 0; i < n; i++) {
        int x, y;
        scanf("%s%d%d", buf, &x, &y);
        LL d = 1ll * std::abs(x - a) + std::abs(y - b);
        x = x - a;
        y = y - b;
        int t = gcd(abs(x), abs(y));
        if(t) x /= t, y /= t;
        f[std::make_pair(x, y)].push_back(std::make_pair(d, buf[0]));
    }
    int A[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int B[][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    bool flag = false;
    for(int i = 0; i < 4; i++) {
        std::vector<std::pair<LL, char> > a = f[std::make_pair(A[i][0], A[i][1])];
        std::sort(a.begin(), a.end());
        for(auto &c : a) {
            if(c.second == 'B') break;
            else flag = true;
        }
    }

    for(int i = 0; i < 4; i++) {
        std::vector<std::pair<LL, char> > a = f[std::make_pair(B[i][0], B[i][1])];
        std::sort(a.begin(), a.end());
        for(auto &c : a) {
            if(c.second == 'R') break;
            else flag = true;
        }
    }
    if(flag) puts("YES"); else puts("NO");
    return 0;
}
