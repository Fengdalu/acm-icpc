//#include <bits/stdc++.h>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define SZ size()
#define AA first
#define BB second
#define BG begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)

const LL INF = (1LL<<38);

#define Maxn 251111
#define Maxm 851111

struct node {
	int u, v, next;
	LL l;
}e[Maxm];
int tot, last[Maxn];
int n, m;
LL V[Maxn], dist[Maxn];
priority_queue<pair<LL, int> > que;
int visit[Maxn];

void adde(int u, int v, LL l) {
	e[tot].u = u; e[tot].v = v; e[tot].l = l; e[tot].next = last[u]; last[u] = tot++;
	swap(u, v);
	e[tot].u = u; e[tot].v = v; e[tot].l = l; e[tot].next = last[u]; last[u] = tot++;
}

int spfa(int s) {
	int i, j, k, u, v, w;
	LL d;
	for(i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	while(!que.empty()) que.pop();
	que.push(MP(0, s));
	dist[s] = 0;
	visit[s] = 1;
	while(!que.empty()) {
		u = que.top().BB; d = -que.top().AA; que.pop();
		if(d != dist[u]) continue;
		for(j = last[u]; j != -1; j = e[j].next) {
			v = e[j].v;
			if(d + e[j].l < dist[v]) {
				dist[v] = d + e[j].l;
				que.push(MP(-dist[v], v));
			}
		}
	}
	for(i = 1; i <= n; i++) {
		if(dist[i] == INF) return 0;
	}
	return 1;
}

int main() {
    int i, j, k, u, v, w;
	int te;
	scanf("%d", &te);
	for(int ca = 1; ca <= te; ca++) {
		scanf("%d%d", &n, &m);
		for(i = 1; i <= n; i++) {
			scanf("%d", &w);
			V[i] = w;
		}
		if(n == 0) {
			printf("0\n");
			continue;
		}
		tot = 0;
		for(i = 1; i <= n; i++) last[i] = -1;
		for(i = 0; i < m; i++) {
			scanf("%d%d%d", &u, &v, &w);
			adde(u, v, w);
		}
		if(!spfa(1)) {
			printf("No Answer\n");
			continue;
		}
		LL ans = 0;
		for(i = 1; i <= n; i++) {
			ans += V[i] * dist[i];
		}
		printf("%lld\n", ans);
	}
    return 0;
}
