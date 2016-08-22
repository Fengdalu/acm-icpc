#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e7;
ll f[N+1];
bool vis[N+1];
int main() {
    ll n, x, y;
    cin >> n >> x >> y;
    fill(f, f + 2 * n, n * x);
    f[1] = x;
    fill(vis, vis + 2 * n, false);
    queue<int>q;
    q.push(1);
    while(q.size()) {
        auto p = q.front(); q.pop();
        vis[p] = false;
        if(~p & 1) {
            f[p] = min(f[p], f[p>>1] + y);
        }
        if(p + 1 <= 2 * n && f[p] + x < f[p + 1]) {
            f[p + 1] = f[p] + x;
            if(!vis[p + 1]) {
                vis[p + 1] = true;
                q.push(p + 1);
            }
        }
        if(p - 1 && f[p] + x < f[p - 1]) {
            f[p - 1] = f[p] + x;
            if(!vis[p - 1]) {
                vis[p - 1] = true;
                q.push(p - 1);
            }
        }
    }
    cout << f[n] << endl;
    return 0;
}

