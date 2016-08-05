#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> PII;
#define AA first
#define BB second
#define MP make_pair
PII a[1010];
int dp[1010][10100];
PII pre[1010][10100];
ll k;
unordered_map<int, int>pos;
int f[10100], prime[100100], np[100100], cnt1;
int q[10010];

ll qpow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a;
        a *= a; b >>= 1;
    }
    return ans;
}

int cc(ll a, ll b) {
    int cnt = 0;
    while(a % b == 0) cnt++, a /= b;
    return cnt;
}

ll cal(ll a, ll b) {
    cout << "cal " << a << " " << b;
    ll ans = 1;
    for(int i = 0; i < cnt1; i++) {
        int c = cc(a, prime[i]) + cc(b, prime[i]);
        ans *= qpow(prime[i], min(c, np[i]));
    }
    cout << " " << ans << endl;
    return ans;
}

void update(PII p, PII b) {
    int &now = dp[p.AA][p.BB];
    int w = dp[b.AA][b.BB];
    if(now == -1 || now >= w + 1) {
        now = w + 1;
        pre[p.AA][p.BB] = b;
    }
}

int main() {
    ll n;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i].AA;
        a[i].BB = i;
    }
    sort(a, a + n);
    int cnt = 0;
    f[cnt++] = 1;
    for(ll i = 2; i * i <= k; i++) if(k % i == 0) f[cnt++] = i, f[cnt++] = k / i;
    f[cnt++] = k;
    sort(f, f + cnt);
    cnt = unique(f, f + cnt) - f;
    cnt1 = 0; ll tmp = k;
    for(ll i = 2; i * i <= k; i++) if(tmp % i == 0) {
        prime[cnt1++] = i;
        while(tmp % i == 0) {
            tmp /= i;
        }
    } if(tmp != 1) prime[cnt1++] = tmp;
    for(int i = 0; i < cnt1; i++) {
        int tmp = k, v = prime[i];
        while(tmp % v == 0) {
            tmp /= v;
            np[i] ++;
        }
    }
    for(int i = 0; i < cnt; i++) cout << f[i] << " "; cout << endl;
    for(int i = 0; i < cnt; i++) pos[f[i]] = i;
    for(int i = 0; i < cnt1; i++) cout << prime[i] << " "; cout << endl;
    for(int i = 0; i < cnt1; i++) cout << np[i] << " "; cout << endl;
    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    for(int i = 0; i < n; i++) {
        PII q = a[i + 1];
        for(int j = 0; j < cnt; j++) {
            int now = dp[i][j];
            if(now == -1) continue;
            cout << i << " " << f[j] << endl;
            update(MP(i + 1, pos[cal(f[j], q.AA)]), PII(i, j));
        }
    }
    cout << dp[n][f[k]] << endl;
    return 0;
}
