#include <bits/stdc++.h>

const int N = 300;

int x[N*N], y[N*N];
int deg[N];
int vis[N*N];
std::vector<int> g[N];
std::vector<int> e[N*N];

void cal(int u) {
	if(vis[u]) return;
	vis[u] = true;
	for(int i = 0; i < e[u].size(); i++) {
		int to = e[u][i];
		if(vis[to]) continue;
		if(y[u]==y[to]||x[u] == x[to]) std::swap(x[to], y[to]);
		cal(to);
	}
}

int main() {
	int T; 
	scanf("%d", &T);
	while(T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i = 0; i <= n; i++) g[i].clear();
		for(int i = 0; i <= m; i++) e[i].clear();
		for(int i = 0; i < m; i++) scanf("%d%d", x + i, y + i);
		std::fill(deg, deg + n + 1, 0);
		for(int i = 0; i < m; i++) {
			int u = x[i], v = y[i];
			g[u].push_back(i);
			g[v].push_back(i);
			deg[u]++; deg[v]++;
		}
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			if(deg[i] % 2 == 0) ans++;
			for(int j = 0; j + 1 < g[i].size(); j += 2) {
				int u = g[i][j];
				int v = g[i][j + 1];
				e[u].push_back(v);
				e[v].push_back(u);
			}
		}
		printf("%d\n", ans)	;
		std::fill(vis, vis + m + 1, 0);
		for(int i = 0; i < m; i++) if(!vis[i]) cal(i);
		for(int i = 0; i < m; i++) printf("%d %d\n", x[i], y[i]);
	}
	return 0;	
}
