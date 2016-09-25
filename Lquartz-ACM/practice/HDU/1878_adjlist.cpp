#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define Maxn 1111
#define Maxm 501111
struct node {
    int u, v, next;
}e[Maxm];
int tot, last[Maxn];
int n, m;
int deg[Maxn];
int visit[Maxn];
int cnt;

void adde(int u, int v) {
    e[tot].u = u; e[tot].v = v; e[tot].next = last[u]; last[u] = tot++;
    e[tot].u = v; e[tot].v = u; e[tot].next = last[v]; last[v] = tot++;
}

void dfs(int u) {
    cnt++;
    visit[u] = 1;
    for(int j = last[u]; j != -1; j = e[j].next) {
        int v = e[j].v;
        if(!visit[v]) {
            dfs(v);
        }
    }
}

int main() {
    int i, j;
    while(scanf("%d", &n) != EOF && n) {
        scanf("%d", &m);
        int u, v;
        for(i = 1; i <= n; i++) {
            visit[i] = false;
            last[i] = -1;
            deg[i] = 0;
        }
        tot = 0;
        for(i = 0; i < m; i++) {
            scanf("%d%d", &u, &v);
            adde(u, v);
            deg[u]++, deg[v]++;
        }
        for(i = 1; i <= n; i++) {
            if(deg[i] & 1) break;
        }
        if(i <= n) {
            printf("0\n");
        }
        else {
            cnt = 0;
            dfs(1);
            if(cnt != n) {
                printf("0\n");
            }
            else {
                printf("1\n");
            }
        }

    }
    return 0;
}
