#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <cassert>
using namespace std;

const int maxn = 15;
typedef long long ll;
const ll mod = 1e9 + 9;

int n, m, k;
ll two[1000];
ll f[1 << 20], g[1 << 20];
ll dp[1 << 20][maxn];

inline int ones(int x) { return __builtin_popcount(x); }

ll dfs(int mask, int cnt) {
    if(ones(mask) == cnt) return 1;
    if(ones(mask) < cnt) return 0;
    if(dp[mask][cnt] != -1) return dp[mask][cnt];
    dp[mask][cnt] = 0;
    vector<int>q;
    for(int i = 0; i < n; i++)
    if(1 << i & mask) q.push_back(i);
    for(int mk = 0; mk < (1 << q.size()); mk++)
    if(1 & mk) {
        int now = 0;
        for(int j = 0; j < q.size(); j++)
        if(1 << j & mk)
            now |= 1 << q[j];
        if(f[now])
            dp[mask][cnt] = (dp[mask][cnt] + f[now] * dfs(mask ^ now, cnt - 1) % mod) % mod;
    }
    return dp[mask][cnt];
}

int main() {
    two[0] = 1;
    for(int i = 1; i < 1000; i++) two[i] = two[i - 1] * 2LL % mod;
    int __;
    scanf("%d", &__);
    for(int _ = 1; _ <= __; _++) {
        memset(f, 0, sizeof f);
        memset(g, 0, sizeof g);
        scanf("%d%d%d", &n, &m, &k);
        ll loop = 0;
        for(int i = 0; i < m; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            x--; y--;
            if(x == y) {  loop++; continue; }
            int mk = ((1 << n) - 1) ^ (1 << x) ^ (1 << y);
            int sub = mk;
            do {
                g[sub | (1 << x) | (1 << y)]++;
                sub = (sub - 1) & mk;
            }while(sub != mk);
        }
        for(int mk = 1; mk < (1 << n); mk++) {
            f[mk] = two[g[mk]];
            int id;
            for(id = 0; ; id++) if(1 << id & mk) break;
            int sub = mk ^ (1 << id);
            int msub = sub;
            do {
                int now = sub | (1 << id);
                if(now != mk) {
                    f[mk] = ((f[mk] - f[now] * two[g[mk ^ now]]) % mod + mod) % mod;
                }
                sub = (sub - 1) & msub;
            } while(sub != msub);
        }
        for(int i = 0; i < (1 << n); i++) for(int j = 0; j <= n; j++) dp[i][j] = -1;
        int mask = (1 << n); mask --;
        cout << "Case #" << _ << ":" << endl;
        cout << dfs(mask, k) * two[loop] % mod << endl;
    }
    return 0;
}
