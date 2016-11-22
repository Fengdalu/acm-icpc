#include <bits/stdc++.h>

const int N = 100;
std::bitset<N>g[N];
int nodes[N];
int stk[N];
bool vis[N];
int cnt = 0;


void dfs(int now, int up, int s, int &ans) {
	if(up == s) { ans++; return; }
	if(now == cnt) return;
	int cur = nodes[now];
	bool flag = true;
	for(int i = 0; i < up && flag; i++) {
		if(!g[cur][stk[i]]) flag = false;
	}
	if(flag) { stk[up++] = cur; dfs(now + 1, up, s, ans); up--; }
	dfs(now + 1, up, s, ans);
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int n, m, S; scanf("%d%d%d", &n, &m, &S);
		for(int i = 0; i < n; i++) g[i].reset();
		for(int i = 0; i < m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			u--; v--;
			g[v][u] = g[u][v] = 1;
		}
		int ans = 0;
		for(int i = 0; i < n; i++) {
			cnt = 0;
			nodes[cnt++] = i;
			for(int j = i; j < n; j++) if(g[i][j]) nodes[cnt++] = j;
			stk[0] = i;
			dfs(1, 1, S, ans);
		}
		printf("%d\n", ans);
	}
	return 0;
}
