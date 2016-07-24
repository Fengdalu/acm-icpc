#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;


const int maxn = 100100;
int ind[maxn], dfn[maxn], low[maxn], color[maxn], f[maxn];
int to[maxn * 2], nt[maxn * 2];
bool vis[maxn], in[maxn];
int cnt, num;
int ncnt;
int e1[maxn], e2[maxn];
stack<int>q;

void add(int x, int y) {
    to[cnt] = y;
    nt[cnt] = ind[x];
    ind[x] = cnt++;
}

void tarjan(int x, int pre) {
    if(vis[x]) return;
    q.push(x); vis[x] = in[x] = true;
    dfn[x] = low[x] = num++;
    for(int k = ind[x]; k != -1; k = nt[k])
    if((pre ^ k) != 1){
        int v = to[k];
        if(!vis[v]) {
            tarjan(v, k);
            low[x] = min(low[x], low[v]);
        }
        else if(in[v]) low[x] = min(low[x], low[v]);
    }
    if(dfn[x] == low[x]) {
        ncnt++;
        while(true) {
            int v = q.top(); q.pop();
            color[v] = ncnt;
            in[v] = false;
            if(v == x)  {
                break;
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    memset(ind, -1, sizeof ind);
    for(int i = 0; i < m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        x--; y--;
        e1[i] = x;
        e2[i] = y;
        add(x, y), add(y, x);
    }
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < n; i++) tarjan(i, -1);
    memset(vis, 0, sizeof vis);
    memset(ind, -1, sizeof ind); cnt = 0;
    for(int i = 0; i < m; i++) {
        int x = color[e1[i]], y = color[e2[i]];
        if(x != y) f[x]++, f[y]++;
    }
    int ans = 0;
    for(int i = 1; i <= ncnt; i++) if(f[i] == 1) ans++;
    cout << (ans + 1) / 2 << endl;
    return 0;
}
