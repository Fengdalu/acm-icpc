#include <bits/stdc++.h>

using namespace std;
#define LL long long
const int N = 20000+20000+20000+100;
const int M = 1000000;
const LL INF = 1e18;
int ind[N];
LL f[N];
bool vis[N];
int t[M], nt[M], c[M], cnt;

void add(int a, int b, int w) {
//    cout << "add " << a << " " << b << " " << w << endl;
    t[cnt] = b;
    c[cnt] = w;
    nt[cnt] = ind[a];
    ind[a] = cnt;
    cnt++;
}

int main() {
    int n, M, m;
    memset(ind, -1, sizeof ind);
    cnt = 0;
    scanf("%d%d", &n, &m);
    M = m;
    for(int i = 0; i < m; i++) {
        int w;
        scanf("%d", &w);
        for(int j = 0; j < w; j++) {
            int id;
            scanf("%d", &id);
            id--;
            add(id, n + i, 0);
            add(n + M + i, id, 0);
        }
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        int u, v, p;
        scanf("%d%d%d", &u, &v, &p);
        u--; v--;
        add(u, v, p);
        add(v, u, p);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        int u, v, p;
        scanf("%d%d%d", &u, &v, &p);
        u--; v--;
        add(u + n, v + n + M, p);
        add(v + n, u + n + M, p);
    }
    for(int i = 0; i < n + M + M; i++) f[i] = INF;
    int S, T;
    scanf("%d%d", &S, &T);
    S--; T--;
    f[S] = 0;
    priority_queue< pair<LL, int> > q;
    for(int i = 0; i < n + M + M; i++) {
        q.push(make_pair(-f[i], i));
    }
    memset(vis, 0, sizeof vis);
    while(q.size()) {
        int x = q.top().second;
//        cout << "TOP: " << x << " " << q.top().first << endl;
        q.pop();
        if(vis[x]) continue;
        vis[x] = true;
        for(int k = ind[x]; k != -1; k = nt[k]) {
//            cout << "TO: " << t[k] << " " << c[k] << endl;
            if(f[x] + c[k] < f[t[k]]) {
                f[t[k]] = f[x] + c[k];
                q.push(make_pair(-f[t[k]], t[k]));
            }
        }
    }
    if(f[T] == INF) printf("-1\n");
    else printf("%I64d\n", f[T]);
    return 0;
}
