#include <bits/stdc++.h>

typedef long long ll;
int main() {
    ll l1, r1, l2, r2, k;
    std::cin >> l1 >> r1 >> l2 >> r2 >> k;
    if(l1 > r1 || l2 > r1) {
        std::cout << 0 << std::endl;
    }
    else  {
        ll r = std::min(r2, r1) , l =  std::max(l1, l2);
        ll ans = r - l + 1;
        if(l <= k && k <= r) ans--;
        std::cout << std::max(0ll, ans) << std::endl;
    }
    return 0;
}
