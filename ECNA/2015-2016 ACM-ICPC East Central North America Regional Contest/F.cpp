#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
const int Maxn = 3000;
const int Maxm = 9000000;
const int INF = 100000000;
struct node {
    int u, v, c, next;
}e[Maxm];
int tot, last[Maxn];
void adde(int u, int v, int c, int c1) {
    //cout << u << " " << v << " " << c <<endl;
    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].next = last[u]; last[u] = tot++;
    e[tot].u = v; e[tot].v = u; e[tot].c = c1; e[tot].next = last[v]; last[v] = tot++;
}

int dist[Maxn], cur[Maxn], gap[Maxn], pre[Maxn];
int ISAP(int s, int t, int n) {
    int i, j, u, v, det;
    int maxflow = 0;
    memset(dist, 0, sizeof(dist[0]) * (n + 3));
    memset(gap, 0, sizeof(gap[0]) * (n + 3));
    for (i = 0; i < n; i ++ )
        cur[i] = last[i];
    u = s;
    gap[0] = n;
    pre[s] = -1;
    while (dist[s] <= n) {
        bool flag = false;
        for (j = cur[u]; j != -1; j = e[j].next) {
            v = e[j].v;
            if (e[j].c > 0 && dist[u] == dist[v] + 1) {
                flag = true;
                pre[v] = u;
                cur[u] = j;
                u = v;
                break;
            }
        }
        if (flag) {
            if (u == t) {
                int det = INF;
                for (i = u; i != s; i = pre[i])
                    det = min(det, e[cur[pre[i]]].c);
                for (i = u; i != s; i = pre[i]) {
                    e[cur[pre[i]]].c -= det;
                    e[cur[pre[i]] ^ 1].c += det;
                }
                maxflow += det;
                u = s;
            }
        }
        else {
            int mind = n;
            for (j = last[u]; j != -1; j = e[j].next ) {
                v = e[j].v;
                if (e[j].c > 0 && dist[v] < mind) {
                    mind = dist[v];
                    cur[u] = j;
                }
            }
            if (( -- gap[dist[u]]) == 0) break;
            gap[dist[u] = mind + 1] ++ ;
            if (u != s) u = pre[u];
        }
    }
    return maxflow;
}

int s, r, f, t;
map<string, int>name;
char buf[1000000];

int main() {
    //freopen("input.in", "r", stdin);
    memset(last, -1, sizeof last);
    tot = 0;
    scanf("%d%d%d%d", &s, &r, &f, &t);
    int cnt = 0;
    for(int i = 0; i < r; i++) {
        scanf("%s", buf);
        name[string(buf)] = ++cnt;
        adde(0, cnt, 1, 0);
    }
    int lp = cnt;
    for(int i = 0; i < f; i++) {
        scanf("%s", buf);
        name[string(buf)] = ++cnt;
    }
    int ed = cnt;
    for(int i = 0; i < t; i++) {
        int n; scanf("%d", &n);
        int x = ++cnt;
        int y = ++cnt;
        adde(x, y, 1, 0);
        for(int j = 0; j < n; j++) {
            scanf("%s", buf);
            if(name.find(string(buf)) != name.end()) {
                int to = name.find(string(buf))->second;
                adde(y, to, INF, 0);
                adde(to, x, INF, 0);
            }
            else {
                name[string(buf)] = ++cnt;
                adde(y, cnt, INF, 0);
                adde(cnt, x, INF, 0);
            }
        }
    }
    int target = ++cnt;
    for(int i = lp + 1; i <= ed; i++) {
        adde(i, target, 1, 0);
    }
    printf("%d\n", ISAP(0, target, cnt + 1));
}
