#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
const int maxm = 30010 * 2;
int ind[maxn];
int to[maxm], nt[maxm], c[maxm], del[maxm], e1[maxm], e2[maxm], cc[maxm], base[maxm];
int id[maxm];
int dfn[maxn], low[maxn], color[maxn], pre[maxn], value[maxn];
bool in[maxn];
int num, nc, cnt;
stack<int>s;
vector<pair<int, int> >g[maxn];

void tarjan(int x, int pre) {
    if(dfn[x] != -1) return;
    dfn[x] = low[x] = ++num;
    in[x] = true;
    s.push(x);
    for(int k = ind[x]; k != -1; k = nt[k]) if(!del[k]) {
        if((k ^ pre) == 1) continue;
        int v = to[k];
        if(dfn[v] == -1) {
            tarjan(v, k);
            low[x] = min(low[v], low[x]);
        }
        else if(in[x]) { low[x] = min(low[x], low[v]); }
    }
    if(dfn[x] == low[x]) {
        nc++;
        while(true) {
            int v = s.top(); s.pop();
            in[v] = false;
            color[v] = nc;
            if(v == x) break;
        }
    }
}

void add(int a, int b, int w) {
    to[cnt] = b;
    c[cnt] = w;
    nt[cnt] = ind[a];
    ind[a] = cnt++;
}

int main() {
    int n, m;
    int S, T;
    int ans = 2e9 + 10, cans;
    scanf("%d%d", &n, &m);
    scanf("%d%d", &S, &T);
    S--; T--;
    memset(ind, -1, sizeof ind);
    for(int i = 0; i < m; i++) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        x--; y--;
        e1[i] = x; e2[i] = y; cc[i] = w;
        id[i] = cnt;
        base[cnt] = i;
        add(x, y, w);
        base[cnt] = i;
        add(y, x, w);
    }
    int *vis = dfn;
    memset(dfn, 0, sizeof dfn);
    memset(pre, -1, sizeof(int) * n);
    queue<int>q;
    q.push(S);
    while(q.size()) {
        int v = q.front(); q.pop();
        vis[v] = true;
        for(int k = ind[v]; k != -1; k = nt[k]) {
            int p = to[k];
            if(vis[p]) continue;
            vis[p] = true;
            pre[p] = v;
            value[p] = k;
            q.push(p);
        }
    }
    if(!vis[T]) {
        cout << 0 << endl;
        cout << 0 << endl;
        return 0;
    }
    vector<int>e;
    int k = T;
    while(k != S) {
        e.push_back(value[k]);
        k = pre[k];
    }
    int id0, id1;
    for(auto &t: e) {
        del[t] = del[t ^ 1] = true;
        memset(dfn, -1, sizeof dfn);
        num = 0;
        nc = 0;
        for(int i = 0; i < n; i++) tarjan(i, -1);
        if(color[S] == color[T]) {
            del[t] = del[t ^ 1] = false;
            continue;
        }
        for(int i = 0; i <= n; i++) g[i].clear();
        for(int i = 0; i < m; i++) if(!del[id[i]]) {
            int a = color[e1[i]], b = color[e2[i]], w = cc[i];
            if(a == b) continue;
            g[a].push_back(make_pair(b, i));
            g[b].push_back(make_pair(a, i));
        }
        int *vis = dfn;
        memset(dfn, 0, sizeof dfn);
        memset(pre, -1, sizeof pre);
        memset(value, -1, sizeof value);
        queue<int>q;
        q.push(color[S]);
        while(q.size()) {
            int v = q.front(); q.pop();
            vis[v] = true;
            for(auto &t: g[v]) {
                int p = t.first;
                if(vis[p]) continue;
                pre[p] = v;
                vis[p] = true;
                value[p] = t.second;
                q.push(p);
            }
        }
        int mm = 1e9 + 7;

        if(pre[color[T]] == -1) {
            if(c[t] < ans) {
                ans = c[t];
                cans = 1;
                id0 = base[t];
            }
            del[t] = del[t ^ 1] = false;
            continue;
        }
        int k = color[T];
        int mmid;
        while(k != color[S]) {
            int w = cc[value[k]];
            if(w < mm) {
                mm = w;
                mmid = value[k];
            }
            k = pre[k];
        }
        if(mm + c[t] < ans) {
            ans = mm + c[t];
            cans = 2;
            id0 = base[t];
            id1 = mmid;
        }
        del[t] = del[t ^ 1] = false;
    }
    if(ans > 2e9) cout << -1;
    else if(cans == 2) {
        cout << ans << endl;
        cout << cans << endl;
        cout << id0 + 1 << " " << id1 + 1;
    }
    else if(cans == 1) {
        cout << ans << endl;
        cout << cans << endl;
        cout << id0 + 1 << endl;
    }
    return 0;
}
