#include <bits/stdc++.h>

typedef long long ll;

int main() {
    std::multiset< std::pair<ll, ll> >s;
    std::multiset<ll> f;
    int n;
    scanf("%d", &n);
    ll tot, ww; scanf("%I64d%I64d", &tot, &ww);
    for(int i = 1; i < n; i++) {
        ll rk, w; scanf("%I64d%I64d", &rk, &w);
        if(rk > tot) {
            f.insert(w + 1 - rk);
        }
        else
            s.insert(std::make_pair(-rk, w));
    }
    int ans = f.size() + 1;
    while(true) {
        if(f.size() == 0) break;
        int T = f.size() - 1;
        bool flag = true;
        while(f.size() != T) {
            ll t = *f.begin(); f.erase(f.begin());
            if(t > tot) { flag = false; break; }
            tot -= t;
            while(s.size() && -(s.begin()->first) > tot) {
                f.insert(s.begin()->second + 1 + s.begin()->first);
                s.erase(s.begin());
            }
        }
        if(!flag) break;
        ans--;
    }
    printf("%d\n", ans);
    return 0;
}
