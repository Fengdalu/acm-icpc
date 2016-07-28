#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cassert>
using namespace std;
#define PII pair<int, int>
#define MP(x, y) make_pair(x, y)
#define AA first
#define BB second

const int maxn = 300;
const int maxm = 500000;
const int inf = 0x3f;
int head[maxn], pre[maxn];
int nt[maxm], to[maxm], w[maxm];
int cnt[maxn];
int etot;
int n, m;
int x[maxn], y[maxn], c[maxn];
int s[maxn][maxn];
int dis[maxn];
bool vis[maxn];
vector<PII>e;

void add(int a, int b, int c) {
    to[etot] = b;
    nt[etot] = head[a];
    w[etot] = c;
    head[a] = etot++;
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
        for(int i = 0; i < n + m; i++) {
            scanf("%d%d%d", &x[i], &y[i], &c[i]);
        }
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) scanf("%d", &s[i][j]);

        int st = n + m + 1, ed = st + 1;
        etot = 0;
        memset(head, -1, sizeof head);
        for(int i = 0; i < n; i++) {
            int tot = 0;
            for(int j = 0; j < m; j++)  tot += s[i][j];
            for(int j = 0; j < m; j++) {
                int dis = abs(x[i] - x[j + n]) + abs(y[i] - y[j + n]) + 1;
                add(i, j + n, dis);
                if(s[i][j]) add(j + n, i, -dis);
            }
        }
        for(int j = 0; j < m; j++) {
            int tot = 0;
            for(int i = 0; i < n; i++)  {
                tot += s[i][j];
            }
            if(tot < c[j + n]) add(j + n, ed, 0);
            if(tot) add(ed, j + n, 0);
        }
        memset(cnt, 0, sizeof cnt);
        memset(vis, 0, sizeof vis);
        memset(dis, 0x3f, sizeof dis);
        queue<int>q;
        q.push(ed);
        dis[ed] = 0;
        int op = -1;
        while(q.size()) {
            int x = q.front(); q.pop();
            cnt[x]++;
            vis[x] = false;
            bool flg = false;
            if(cnt[x] > ed) { op = x; break; }
            for(int k = head[x]; k != -1; k = nt[k]) {
                int v = to[k];
                if(w[k] + dis[x] < dis[v]) {
                    pre[v] = x;
                    dis[v] = w[k] + dis[x];
                    if(!vis[v]) {
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
        }
        if(~op) {
           puts("SUBOPTIMAL");
           memset(vis, 0, sizeof vis);
           do {
               vis[op] = true;
               op = pre[op];
           }while(!vis[op]);

           int rt = op;
           do {
               vis[op] = true;
               int v = op, u = pre[op];
               if(u != st && u != ed && v != st && v != ed)  {
                   if(u < n && v >= n && v < st) s[u][v - n]++;
                   else if(v < n && u >= n && u < st) s[v][u - n]--;
               }
               op = pre[op];
           } while(op != rt);

           for(int i = 0; i < n; i++) {
               printf("%d", s[i][0]);
               for(int j = 1; j < m; j++) printf(" %d", s[i][j]);
               printf("\n");
           }

        }
        else puts("OPTIMAL");
    }
    return 0;
}
