#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
int p[200020];
int in[200020];
int vis[200010];
ll qpow(ll a, ll b) {
    ll tot = 1;
    while(b) {
        if(b & 1) tot = (tot * a) % mod;
        b /= 2ll;
        a = (a * a) % mod;
    }
    return tot;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &p[i]);
    for(int i = 1; i <= n; i++) in[p[i]]++;
    queue<int>q;
    for(int i = 1; i <= n; i++) {
        if(in[i] == 0) q.push(i);
    }
    while(q.size()) {
        int x = q.front(); q.pop();
        vis[x] = true;
        in[p[x]]--;
        if(in[p[x]] == 0) q.push(p[x]);
    }
    ll ans = 1;
    ll oth = 0;
    for(int i = 1; i <= n; i++) if(!vis[i]) {
        int k = i;
        int cnt = 0;
        do {
            cnt++;
            vis[k] = true;
            k = p[k];
        } while(!vis[k]);
        ans = (ans * max(1ll, qpow(2, cnt) - 2ll)) % mod;
        oth += cnt;
    }
    oth = n - oth;
    cout << ans * qpow(2, oth) % mod << endl;
    return 0;
}
