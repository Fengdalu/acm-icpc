#include <bits/stdc++.h>

typedef long long ll;
const int N = 2e5+100;
ll W[N], T[N];

void out() { printf("-1\n"); exit(0); }

int main() {
    std::vector<ll> ans;
    int n;
    ll r;
    scanf("%d%I64d", &n, &r);
    for(int i = 0; i < n; i++) scanf("%I64d", W + i);
    for(int i = 0; i < n; i++) scanf("%I64d", T + i);
    ll cur = 0;
    ll left = 0;
    ll cnt = 0;
    for(int i = 0; i < n; i++) {
        // printf("cur: %I64d\n", cur);
        ll w = W[i], t = T[i];
        ll pre = std::min(w, left);
        left -= pre;
        w -= pre;
        cur += pre;
        t -= pre;
        if(t < 0) out();
        else if(w > t) out();
        else if(2 * w <= t) { cur += 2 * w; continue; }
        else {
            // printf("he da li\n");
            ll dt = 2ll * w - t;
            // printf("DT: %I64d\n", dt);
            cur += (t - dt);
            w -= (t - dt) / 2;
            ll count = (dt + r - 1) / r;
            ll cc = count;
            // printf("count: %d\n", count);
            cnt += count;
            if(count + ans.size() <= 1e5) {
                ll ww = w;
                while(count--) {
                    ans.push_back(cur);
                    ll dis = std::min(r, ww);
                    ww -= dis;
                    cur += dis;
                }
            }
            else cur += w;
            left += cc * r - w;
        }
    }
    printf("%I64d\n", cnt);
    if(cnt <= 1e5)
        for(int i = 0; i < ans.size(); i++)
            printf("%I64d ", ans[i]);
    return 0;
}
