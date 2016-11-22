#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    map<long long, int>f;
    scanf("%d", &n);
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        int w; scanf("%d", &w);
        for(long long i = 1; i < 3e9; i *= 2ll) {
            ans += 1ll * f[i - w];
        }
        f[w]++;
    }
    cout << ans << endl;
    return 0;
}
