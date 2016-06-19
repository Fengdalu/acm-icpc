#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

typedef long long ll;
const int maxn = 1001000;
const ll mod = 1e9 + 9;
int p[maxn];
bool vis[maxn];
ll fact[maxn], inv[maxn];
ll g[maxn];

int n;

ll qpow(ll a, ll x) {
    if(x == 0) return 1;
    return qpow(a * a % mod, x / 2) * (x & 1 ? a : 1) % mod;
}

int main()  {
    int __;
    cin >> __;
    inv[0] = 1;
    inv[1] = 1;
    for(int i = 2; i < maxn; i++) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    for(int i = 2; i < maxn; i++) inv[i] = inv[i - 1] * inv[i] % mod;
    fact[0] = 1;
    for(int i = 1; i < maxn; i++) fact[i] = fact[i - 1] * i % mod;

    while(__--) {
        cin >> n;
        vector<int>a;
        memset(vis, 0, sizeof vis);
        for(int i = 0; i < n; i++)
            cin >> p[i];
        for(int i = 0; i < n; i++)
            p[i]--;
        for(int i = 0; i < n; i++)
            if(!vis[i]) {
                int k = i;
                ll count = 0;
                do {
                    count++;
                    vis[k] = true;
                    k = p[k];
                } while(!vis[k]);
                a.push_back(count);
            }
        ll ans = 0;
        for(int i = 0; i < a.size(); i++) ans += a[i] - 1;
        ans = fact[ans];
        for(int i = 0; i < a.size(); i++) ans = ans * inv[a[i] - 1] % mod;
        for(int i = 0; i < a.size(); i++) ans = ans * qpow(a[i], max(0, a[i] - 2)) % mod;
        cout << ans << endl;
    }
    return 0;
}
