#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int x[300010];
int main() {
    int n; scanf("%d", &n);
    ll ans = 0;
    for(int i = 0; i < n; i++) scanf("%d", x + i);
    sort(x, x + n);
    int p = 0;
    for(int i = 0; i < n - 1; i++) ans += x[i + 1] - x[i];
    int left = 0;
    ll cur = ans;
    for(int i = 0; i < n; i++) {
        if(cur < ans) p = i;
        ans = min(ans, cur);
        left++;
        cur += 1ll * left * (x[i + 1] - x[i]);
        cur -= 1ll * (n - left) * (x[i + 1] - x[i]);
    }
    cout << x[p] << endl;
    return 0;
}
