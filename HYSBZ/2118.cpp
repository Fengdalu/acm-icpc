#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define mp(x, y) make_pair(x, y)

typedef long long ll;
typedef pair<long long, int> obj;
long long a[200];
int n;
ll l, r;
ll f[510000];
bool vis[510000];
const ll inf = (ll)1e20;

void dijk() {
    ll w = a[0];
    for(int i = 0; i < w; i++) f[i] = inf;
    f[0] = 0;
    priority_queue<obj>q;
    q.push(mp(-f[0], 0));
    while(q.size()) {
        obj t = q.top();
        q.pop();
        int x = t.second;
        if(vis[x]) continue;
        vis[x] = true;
        for(int i = 1; i < n; i++) {
            long long to = (x + a[i]) % w;
            long long add = (x + a[i]) / w;
            if(!vis[to] && f[x] + add < f[to]) {
                f[to] = f[x] + add;
                q.push(mp(-f[to], to));
            }
        }
    }
}

ll solve(ll b) {
    long long ans = 0;
    ll w = a[0];
    for(int i = 0; i < w; i++) {
        ll tmp = max(0LL, b / w - f[i] + (ll)((b % w) >= i));
        ans += tmp;
    }
    return ans;
}

int main() {
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    reverse(a, a + n);
    if(a[0] == 0) cout << 0 << endl;
    else {
        dijk();
        cout << solve(r) - solve(l - 1) << endl;
    }
    return 0;
}
