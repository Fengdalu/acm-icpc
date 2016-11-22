#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <queue>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;
const int maxn = 400100;
int n, k;
int l[maxn], r[maxn];
int h[maxn], cnt;
ll fact[maxn], inv[maxn];
int f[maxn];


int main() {
    scanf("%d%d", &n, &k);
    fact[0] = 1;
    for(int i = 1; i < maxn; i++) fact[i] = (fact[i - 1] * i) % mod;
    inv[0] = 1;
    inv[1] = 1;
    for(int i = 2; i < maxn; i++) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    for(int i = 2; i < maxn; i++) inv[i] = (inv[i - 1] * inv[i]) % mod;
    for(int i = 0; i < n; i++)
        scanf("%d%d", &l[i], &r[i]);
    for(int i = 0; i < n; i++) r[i]++;
    for(int i = 0; i < n; i++) h[cnt++] = l[i];
    for(int i = 0; i < n; i++) h[cnt++] = r[i];
    sort(h, h + cnt);
    cnt = unique(h, h + cnt) - h;
    for(int i = 0; i < n; i++) {
        int x = lower_bound(h, h + cnt, l[i]) - h;
        int y = lower_bound(h, h + cnt, r[i]) - h;
        f[x]++;
        f[y]--;
    }
    ll ans = 0;
    ll c = f[0];
    for(int i = 1; i < cnt; i++) {
        if(c >= k) {
            ans = (ans + fact[c] * inv[k] % mod * inv[c - k] % mod * (ll)(h[i] - h[i - 1]) % mod) % mod;
        }
        c = c + f[i];
    }
    cout << ans << endl;
    return 0;
}

