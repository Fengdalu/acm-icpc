#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
#define PB push_back
#define MP make_pair
#define BG begin()
#define ED end()
#define SZ size()
#define N 210
#define M 250000
#define MOD 1000000009
typedef vector<int> VI;
struct node {
    int u, v, c, next;
}E[M];
int tot, last[N];
int n, m, S, T;

void addedge(int u, int v, int c) {
//    printf("add %d %d %d\n", u, v, c);
    E[tot].u = u; E[tot].v = v; E[tot].c = c; E[tot].next = last[u]; last[u] = tot++;
    E[tot].u = v; E[tot].v = u; E[tot].c = 0; E[tot].next = last[v]; last[v] = tot++;
}

int dist[N], cur[N], sta[N], que[N], pre[N];
bool bfs(int s, int t, int n) {
    int front = 0, tail = 0;
    memset(dist, -1, sizeof(dist[0]) * (n + 1));
    dist[s] = 0;
    que[tail++] = s;
    while(front < tail) {
//        cout << "bfs " << que[front] << endl;
        for( int j = last[que[front++]]; j != -1; j = E[j].next) {
//            cout << "j " << j << "v " << E[j].v << endl;
            if(E[j].c > 0&& dist[E[j].v] == -1) {
                dist[E[j].v] = dist[E[j].u] + 1;
                if(E[j].v == t) return 1;
                que[tail++] = E[j].v;
            }
        }
    }
    return 0;
}

int dinic(int s, int t, int n) {
    int maxflow = 0, tp;
    while(bfs(s, t, n)) {
//        cout << "dinic " << maxflow << endl;
        for(int i = 0; i < n; i++) {
            cur[i] = last[i];
        }
        int u = s, tail = 0;
        while(cur[s] != -1) {
            if(u == t) {
                tp = MOD;
                for(int i = tail - 1; i >= 0; i--) 
                    tp = min(tp, E[sta[i]].c);
                maxflow += tp;
                for(int i = tail - 1; i >= 0; i--) {
                    E[sta[i]].c -= tp;
                    E[sta[i] ^ 1].c += tp;
                    if(E[sta[i]].c == 0) 
                        tail = i;
                }
                u = E[sta[tail]].u;
            }
            else if(cur[u] != -1 && E[cur[u]].c > 0
                    && dist[u] + 1 == dist[E[cur[u]].v]) {
                        sta[tail++] = cur[u];
                        u = E[cur[u]].v;
            }
            else {
                while(u != s && cur[u] == -1) {
                    u = E[sta[-- tail]].u;
                }
                cur[u] = E[cur[u]].next;
            }
        }
    }
    return maxflow;
}

int main() {
//    cout << sizeof(E) + sizeof(last) * 3 << endl;
    int i, j, u, v, l, c;
    int Te;
    scanf("%d", &Te);
    for(int Ca = 1; Ca <= Te; Ca++) {
//        cout << Ca << " " << Te << endl;
        scanf("%d%d", &n, &m);
        S = 0, T = n + 1;
        for(i = 0; i <= T; i++) {
            last[i] = -1; 
            tot = 0;
        }
        for(i = 0; i < m; i++) {
            scanf("%d%d%d%d", &u, &v, &l, &c);
            addedge(S, v, l);
            addedge(u, T, l);
            addedge(u, v, c - l);
        }
        dinic(S, T, T + 1);
        int flag = 1;
//        for(i = 0; i < tot; i++) {
//            printf("E %d %d %d\n", E[i].u, E[i].v, E[i].c);
//            if(i % 6 == 5) printf("\n");
//        }
        for(j = last[S]; j != -1; j = E[j].next) {
            if(E[j].c != 0) {
                flag = 0;
                break;
            }
        }
        if(Ca > 1) printf("\n");
        if(flag) {
            printf("YES\n");
            for(i = 0, j = 1; i < tot; i += 6, j++) {
                printf("%d\n", E[i + 1].c + E[i + 5].c);
            }
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}

/*
2

4 6
1 2 1 2
2 3 1 2
3 4 1 2
4 1 1 2
1 3 1 2
4 2 1 2

4 6
1 2 1 3
2 3 1 3
3 4 1 3
4 1 1 3
1 3 1 3
4 2 1 3
*/
