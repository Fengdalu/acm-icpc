#include <bits/stdc++.h>
#include <hash_set>

using namespace __gnu_cxx;
typedef long long ll;
ll f(ll x) {
    if(x > 1 && x % 2 == 1) return f(3 * x + 1) + 1;
    else if(x % 2 == 0) return f(x / 2) + 1;
    return 1;
}

int main() {
    int ans = -1;
    int q = 0;
    for(int i = 1; i < 1e6; i++) {
        int sz = f(i);
        if(sz > ans) {
            ans = sz;
            q = i;
        }
    }
    printf("%d %d\n", q, ans);
    return 0;
}
