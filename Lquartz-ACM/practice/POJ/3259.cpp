#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MP make_pair
#define Maxn 505
#define Maxm 6000
#define MOD 2011111111

struct node {
    int u, v, l, next;
}e[Maxm];
int tot, last[Maxn];
int n, m, w;
int dist[Maxn];
int cnt[Maxn], used[Maxn], visit[Maxn];

void adde(int u, int v, int z) {
    e[tot].u = u; e[tot].v = v; e[tot].l = z; e[tot].next = last[u]; last[u] = tot++;
}

priority_queue<pair<int, int> > Q;
bool spfa(int s) {
    int i, j, u, v, d;
    while(!Q.empty()) Q.pop();
    dist[s] = 0;
    Q.push(MP(0, s));
    cnt[s] = 1;
    while(!Q.empty()) {
        d = -Q.top().first;
        u = Q.top().second;
        Q.pop();
//        cout << "~ " << u << " " << d << endl;
        if(d != dist[u]) continue;
        for(j = last[u]; j != -1; j = e[j].next) {
            v = e[j].v;
            if(dist[v] > d + e[j].l) {
                dist[v] = d + e[j].l;
                cnt[v]++;
                if(cnt[v] > n) return true;
                Q.push(MP(-dist[v], v));
            }
        }
    }
    return false;
}

int main() {
    int i, j, x, y, z;
    int Te;
    scanf("%d", &Te);
    for(int CA = 1; CA <= Te; CA++) {
        scanf("%d%d%d", &n, &m, &w);
        tot = 0;
        for(i = 0; i <= n; i++) last[i] = -1;
        for(i = 0; i < m; i++) {
            scanf("%d%d%d", &x, &y, &z);
            adde(x, y, z);
            adde(y, x, z);
        }
        for(i = 0; i < w; i++) {
            scanf("%d%d%d", &x, &y, &z);
            adde(x, y, -z);
        }
        for(i = 0; i <= n; i++) {
            cnt[i] = 0;
            dist[i] = MOD;
        }
        int flag = false;
        flag = spfa(1);
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
