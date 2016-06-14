#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 100010;
int ind[maxn];
int to[maxn * 2], nt[maxn * 2];
int d[maxn];
int wish[maxn];
int f[maxn];
bool vis[maxn];
int in[maxn];
int list[maxn];
int tot;
int n, m;
int cnt;

void add(int a, int b) {
    in[b]++;
    to[cnt] = b;
    nt[cnt] = ind[a];
    ind[a] = cnt++;
}

void dfs(int x) {
    for(int k = ind[x]; k != -1; k = nt[k]) {
        d[to[k]] = d[x] + 1;
        f[to[k]] += f[x];
        dfs(to[k]);
    }
}

void dfs1(int x) {
    for(int k = ind[x]; k != -1; k = nt[k]) {
        dfs(to[k]);
    }
    if(!vis[wish[x]]) {
        list[tot++] = x;
        vis[wish[x]] = true;
    }
}
int main()  {
    scanf("%d%d", &n, &m);
    memset(ind, -1, sizeof ind);
    while(m--) {
        int p, q;
        scanf("%d%d", &p, &q);
        add(p, q);
    }
    for(int i = 1; i <= n; i++) scanf("%d", &wish[i]);
    for(int i = 1; i <= n; i++) f[i] += 1;
    for(int i = 1; i <= n; i++) if(in[i] == 0) dfs(i);
    for(int i = 1; i <= n; i++) if(f[i] > d[i] + 1) {
        cout << -1 << endl;
        return 0;
    }
    tot = 0;
    for(int i = 1; i <= n; i++) if(in[i] == 0)  dfs1(i);
    for(int i = 0; i < tot; i++)
        printf("%d\n", list[i]);
}
