#include <bits/stdc++.h>

typedef long long ll;
#define cmin(x, y) x = std::min(x, y)

ll check(ll b, ll d, ll s) {
    ll t = std::max(std::max(b, d), s);
    return t - b + t - d + t - s;
}

int main() {
    ll b, d, s;
    std::cin >> b >> d >> s;

    ll ans = check(b, d, s);
    cmin(ans, check(b + 1, d, s));
    cmin(ans, check(b + 1, d + 1, s));


    cmin(ans, check(b, d, s + 1));
    cmin(ans, check(b, d + 1, s + 1));

    cmin(ans, check(b + 1, d, s + 1));
    cmin(ans, check(b + 1, d + 1, s + 1));

    cmin(ans, check(b + 1, d + 1, s + 1));
    cmin(ans, check(b + 1, d + 2, s + 1));
    std::cout << ans << std::endl;
    return 0;
}
