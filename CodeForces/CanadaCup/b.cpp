#include <bits/stdc++.h>

typedef long long ll;

int order(char p) {
    if(p == 'f') return 1;
    if(p == 'e') return 2;
    if(p == 'd') return 3;
    if(p == 'a') return 4;
    if(p == 'b') return 5;
    if(p == 'c') return 6;
}
int main() {
    std::string s;
    std::cin >> s;
    ll n = atoll(s.substr(0, s.size() - 1).c_str());
    char p = s[s.size() - 1];
    ll pre = (n - 1) / 4;
    ll ans = pre * 12;
    ans += n - 1;
    if(n % 2 == 0) {
        if(n % 4 != 0)
            ans += 6;
        else ans += 4;
        ans += order(p);
    }
    else {
        if(n % 4 == 3) ans -= 2;
        ans += order(p);
    }
    std::cout << ans << std::endl;
    return 0;
}
