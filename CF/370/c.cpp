#include <bits/stdc++.h>

typedef long long ll;
int main() {
    int x, y;
    std::cin >> x >> y;
    int a = y, b = y, c = y;
    int ans = 0;
    while(true) {
        if(a == x && b == x && c == x) break;
        if(b > a) std::swap(a, b);
        if(c > a) std::swap(c, a);
        if(c > b) std::swap(b, c);
        // a > b > c
        c = std::min(x, b + a - 1);
        ans++;
    }
    std::cout << ans << std::endl;
    return 0;
}
