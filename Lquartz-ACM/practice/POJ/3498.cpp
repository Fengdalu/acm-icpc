#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define Maxn 400
#define Maxm 40000
#define MOD 100000007
#define SQ(x) ((x)*(x))
struct node {
    int u, v, c, next;
}e[Maxm];
int tot, last[Maxn];
int cur[Maxn], que[Maxn], sta[Maxn], dist[Maxn], top, head, tail;
int n, S, T;
int px[Maxn], py[Maxn], sum;
double D;

void adde(int u, int v, int c) {
    e[tot].u = u; e[tot].v = v; e[tot].c = c; e[tot].next = last[u]; last[u] = tot++;
    e[tot].u = v; e[tot].v = u; e[tot].c = 0; e[tot].next = last[v]; last[v] = tot++;
}

bool bfs(int s, int t, int n) {
    int i, j, u, v;
    for(i = 0; i < n; i++) {
        dist[i] = MOD;
    }
    dist[s] = 0;
    head = tail = 0;
    que[tail++] = s;
    while(head < tail) {
        u = que[head++];
        for(j = last[u];j != -1; j = e[j].next) {
            v = e[j].v;
            if(e[j].c > 0 && dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                if(v == t) return true;
                que[tail++] = v;
            }
        }
    }
    return false;
}

int dinic(int s, int t, int n) {
    int i, j, u, v, tp;
    int maxflow = 0;
    while(bfs(s, t, n)) {
//        cout << maxflow << endl;
        top = 0;
        u = s;
        for(i = 0; i < n; i++) cur[i] = last[i];
        while(cur[s] != -1) {
            if(u == t) {
                tp = MOD;
                for(i = top - 1; i >= 0; i--) {
                    tp = min(tp, e[sta[i]].c);
                }
                maxflow += tp;
                for(i = top - 1; i >= 0; i--) {
                    e[sta[i]].c -= tp;
                    e[sta[i] ^ 1].c += tp;
                    if(e[sta[i]].c == 0) top = i;
                }
                u = e[sta[top]].u;
            }
            else if(cur[u] != -1 && e[cur[u]].c > 0 && dist[u] + 1 == dist[e[cur[u]].v]) {
                sta[top++] = cur[u]; 
                u = e[cur[u]].v;
            }
            else {
                while(u != s && cur[u] == -1) {
                    u = e[sta[--top]].u;
                }
                cur[u] = e[cur[u]].next;
            }
        }
    }
    return maxflow;
}
vector<int> ans;
int main() {
    int i, j, u, v, w, k, te;
    scanf("%d", &te);
    while(te--){
        scanf("%d%lf", &n, &D);
        D *= D;
        tot = 0;
        for(i = 0; i < 2 * n + 20; i++) last[i] = -1;
        S = 0;
        sum = 0;
        for(i = 1; i <= n; i++) {
            scanf("%d%d%d%d", &u, &v, &w, &k);
            px[i] = u; py[i] = v;
            adde(i, i + n, k);
            adde(S, i, w);
            sum += w;
        }
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                if(i == j) continue;
                double dist = SQ(px[i] - px[j]) + SQ(py[i] - py[j]);
                if(dist <= D) adde(i + n, j, MOD);
            }
        }
        ans.clear();
        for(i = 1; i <= n; i++) {
            for(j = 0; j < tot; j += 2) {
                e[j].c += e[j ^ 1].c;
                e[j ^1].c = 0;
            }
            int maxflow = dinic(S, i, 2 * n + 1);
//            cout << "i " << i << " " << maxflow << endl;
            if(maxflow == sum) {
                ans.push_back(i - 1);
            }
        }
        if(ans.size() == 0) printf("-1\n");
        else {
            for(i = 0; i < ans.size(); i++) {
                if(i) printf(" ");
                printf("%d", ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
