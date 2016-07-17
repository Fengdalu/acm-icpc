#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;
const int maxn = 100010;
const ll mod = 998244353LL;
int a[maxn], b[maxn];
int n;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)  scanf("%d", &a[i]);
        for(int i = 0; i < n; i++)  scanf("%d", &b[i]);
        if(a[0] != b[0]) {
            puts("0");
            continue;
        }
        int l = a[0], r = b[0];
        ll ans = 1;
        ll all = 0;
        for(int i = 1; i < n; i++) {
            if(a[i] > l || b[i] < r) ans = 0;
            if(a[i] < l && r < b[i]) {
                ans = 0;
            }
            if(b[i] > r) {
                all += b[i] - r - 1;
                r = b[i];
            }
            else if(a[i] < l) {
                all += l - a[i] - 1;
                l = a[i];
            }
            else {
                ans = (ans * all) % mod;
                all--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
