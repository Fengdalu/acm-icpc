#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> PII;
#define AA first
#define BB second
#define MP make_pair
PII a[1010];
ll p[1010];
int dp[1010][10100];
ll sum[1010][10100];
pair<pair<int, int>, int> pre[1010][10100];
ll k;
unordered_map<ll, int>pos;
ll data[10100];
int tot;

int get(ll g) {
    if(pos.find(g) == pos.end()) pos[g] = ++tot, data[tot] = g;
    return pos[g];
}

ll qpow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a;
        a *= a; b >>= 1;
    }
    return ans;
}

ll cal(ll a, ll b) {
    return __gcd(k / b, a) * b;
}

void update(PII p, PII b, int v, ll s, int pos) {
    int &now = dp[p.AA][p.BB];
    ll &ss = sum[p.AA][p.BB];
    if(now == -1 || now > v || (now == v && s <= ss)) {
        now = v;
        pre[p.AA][p.BB].BB = pos;
        pre[p.AA][p.BB].AA = b;
        ss = s;
    }
}

int main() {
    ll n;
    scanf("%I64d%I64d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%I64d", &a[i].AA);
        p[i] = a[i].AA;
        a[i].AA = __gcd(a[i].AA, k);
        a[i].BB = i;
    }
    memset(dp, -1, sizeof dp);
    if(k == 1) {
        for(int i = 0; i < n; i++) a[i].AA = p[i];
        sort(a, a + n);
        printf("1\n%I64d", a[0].BB + 1);
        return 0;
    }

    tot = 0;
    pos.clear();
    dp[0][get(1)] = 0;
    for(int i = 0; i < n; i++) {
        PII q = a[i];
        for(int j = 1; j <= tot; j++) {
            int now = dp[i][j];
            ll tmp = sum[i][j];
            if(now == -1) continue;
            update(MP(i + 1, get(cal(data[j], q.AA))), PII(i, j), now + 1, tmp + p[i], q.BB);
            update(MP(i + 1, j), PII(i, j), now, tmp, -1);
        }
    }
    int &now = dp[n][get(k)];
    if(~now) {
        queue<int>q;
        int i = n, j = get(k);
        while(i != 0) {
            if(pre[i][j].BB != -1) q.push(pre[i][j].BB + 1);
            pair<pair<int, int>, int> &g = pre[i][j]; i = g.AA.AA; j = g.AA.BB;
        }
        printf("%d\n", q.size());
        while(!q.empty()) { printf("%d ", q.front()); q.pop(); }
    } else {
        puts("-1");
    }
    return 0;
}
