#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
using namespace std;
#define MP make_pair
#define AA first
#define BB second
#define PB push_back
#define cmin(x, y) x = min(x, y)
typedef long long ll;
const int N = 2510;
typedef pair<int, int> PII;
struct Tree {
    int last[N];
    int from[2*N], to[2*N], w[2*N], nt[2*N];
    int dis[N], pre[N];
    int vis[2*N];
    int tot;
    int n;
    int st;
    void init(int _n) {
        n = _n;
        tot = 0;
        memset(last, -1, sizeof last);
    }
    void add(int a, int b, int _w) {
        from[tot] = a;
        to[tot] = b;
        w[tot] = _w;
        nt[tot] = last[a];
        last[a] = tot;
        tot++;
    }
    void adde(int a, int b, int _w) {
        add(a, b, _w);
        add(b, a, _w);
    }
    int path() {
        queue<int>q;
        st = -1;
        for(int i = 0; i < n; i++) if(last[i] != -1) {
            q.push(i);
            break;
        }
        if(q.size() == 0) return 0;
        memset(pre, -1, sizeof pre);
        memset(dis, 0, sizeof dis);
        while(q.size()) {
            int x = q.front(); q.pop();
            for(int k = last[x]; k != -1; k = nt[k]) {
                int v = to[k];
                if(v == pre[x]) continue;
                pre[v] = x;
                dis[v] = dis[x] + w[k];
                q.push(v);
            }
        }
        int p = -1;
        for(int i = 0; i < n; i++) {
            if(dis[i] > dis[p]) p = i;
        }
        memset(pre, -1, sizeof pre);
        memset(dis, 0, sizeof dis);
        q.push(p);
        while(q.size()) {
            int x = q.front(); q.pop();
            for(int k = last[x]; k != -1; k = nt[k]) {
                int v = to[k];
                if(v == from[pre[x]]) continue;
                pre[v] = k;
                dis[v] = dis[x] + w[k];
                q.push(v);
            }
        }
        p = 0;
        for(int i = 0; i < n; i++) {
            if(dis[i] > dis[p]) p = i;
        }
        st = p;
        ll ans = 0;
        while(pre[p] != -1) {
            vis[pre[p]] = true;
            ans += w[pre[p]];
            p = from[pre[p]];
        }
        return ans;
    }

    pair<int, int> middle() {
        int sum = path();
        if(st == -1) return MP(-1, -1);
        int cur = 0;
        int p = st;
        while(pre[p] != -1) {
            cur += w[pre[p]];
            if(cur >= sum / 2) {
                return make_pair(p, from[pre[p]]);
            }
            p = from[pre[p]];
        }
        return make_pair(-1, -1);
    }

} g, g1, g2, g3, g4;

void dfs(int x, int y, int fa, Tree &T) {
    for(int k = g.last[x]; k != -1; k = g.nt[k]) {
        int t = g.to[k];
        if(t == y || t == fa) continue;
        T.adde(x, t, g.w[k]);
        dfs(t, y, x, T);
    }
}

inline void run() {
    int n;
    scanf("%d", &n);
    g.init(n);
    for(int i = 1; i < n; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        g.adde(a, b, w);
    }
    int ans = g.path();
    for(int i = 0; i < g.tot; i++) {
        if(g.vis[i]) {
            g1.init(n);
            g2.init(n);
            g3.init(n);
            for(int j = 0; j < g.tot; j++)
                if(i != j && (i ^ 1) != j) {
                    g3.add(g.from[j], g.to[j], g.w[j]);
                }
            int x = g.from[i], y = g.to[i], w = g.w[i];
            queue<int>q;
            dfs(x, y, x, g1);
            dfs(y, x, y, g2);

            pair<int, int> pa = g1.middle(), pb = g2.middle() ;
            if(pa == MP(-1, -1)) pa = MP(x, x);
            if(pb == MP(-1, -1)) pb = MP(y, y);
            g4 = g3; g4.adde(pa.AA, pb.AA, w); cmin(ans, g4.path());
            g4 = g3; g4.adde(pa.BB, pb.AA, w); cmin(ans, g4.path());
            g4 = g3; g4.adde(pa.BB, pb.BB, w); cmin(ans, g4.path());
            g4 = g3; g4.adde(pa.BB, pb.BB, w); cmin(ans, g4.path());
        }
    }
    printf("%d\n", ans);
}

int main() {
    int _T; scanf("%d", &_T);
    for(int _t = 1; _t <= _T; _t++) { printf("Case %d: ", _t); run(); }
    return 0;
}
