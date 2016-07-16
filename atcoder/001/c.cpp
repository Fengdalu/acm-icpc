#include <bits/stdc++.h>
using namespace std;

vector<int>g[5000];
int dis[5000];
int ans = 0;
int n, k;

int get(int x, int k, int pre) {
    memset(dis, -1, sizeof dis);
    queue<int>q;
    q.push(x);
    dis[x] = 0;
    while(q.size()) {
        int x = q.front();
        q.pop();
        for(auto t: g[x]) {
            if(dis[t] == -1 && t != pre) {
                dis[t] = dis[x] + 1;
                q.push(t);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) if(dis[i] != -1 && dis[i] > k) ans++;
    return ans;
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b); a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ans = n + 1;
    if(k % 2) {
        for(int i = 0 ; i < n; i++)
            for(auto x: g[i]) {
                ans = min(ans, get(i, k / 2, x) + get(x, k / 2, i));
            }
    }
    else {
        for(int i = 0; i < n; i++)
            ans = min(ans, get(i, k / 2, -1));
    }
    cout << ans << endl;
    return 0;
}
