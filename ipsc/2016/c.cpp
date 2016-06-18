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

int main()  {
    int __;
    cin >> __;
    inv[0] = 1;
    inv[1] = 1;
    for(int i = 2; i < maxn; i++) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    for(int i = 2; i < maxn; i++) inv[i] = inv[i - 1] * inv[i] % mod;
    fact[0] = 1;
    for(int i = 1; i < maxn; i++) fact[i] = fact[i - 1] * i % mod;
    g[1] = 1;
    g[2] = 1;
    for(int i = 3; i <= 10; i++) {
        g[i] = i;
        for(int j = 2; i - j >= 2; j++) {
            ll tot = g[j] + g[i - j];
            ll t = fact[tot];
            t = (t * inv[g[j]]) % mod;
            t = (t * inv[g[i - j]]) % mod;
            t = (t * g[j]) % mod;
            t = (t * g[i - j]) % mod;
            t = (t * (i - j)) % mod;
            g[i] = (g[i] + t) % mod;
        }
    }

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
                if(count == 1) continue;
                else if(count == 2) a.push_back(1);
                else a.push_back(count);
            }
        ll ans = 0;
        for(int i = 0; i < a.size(); i++) ans += a[i];
        if(ans == 0) {
            cout << ans << endl;
            continue;
        }
        ans = fact[ans];
        for(int i = 0; i < a.size(); i++) ans = ans * inv[a[i]] % mod;
        for(int i = 0; i < a.size(); i++) ans = ans * g[a[i]] % mod;
        cout << ans << endl;
    }
    return 0;
}
