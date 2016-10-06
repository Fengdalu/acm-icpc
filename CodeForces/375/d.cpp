#include <bits/stdc++.h>

#define cmax(x, y) x = std::max(x, y)

const int N = 60;
char s[N][N];
bool vis[N][N];
bool ff[N*N];
int f[N][N];
int fa[N*N];
int count[N*N];
int id[N][N];
int n, m, K;

const int V[4][2] = {
	{0, -1},
	{0, 1},
	{1, 0},
	{-1, 0}
};

int dfs(int x, int y) {
	vis[x][y] = true;
	for(int i = 0; i < 4; i++) {
		int tx = x + V[i][0];
		int ty = y + V[i][1];
		if(tx < 0 || tx > n - 1 || ty < 0 || ty > m - 1) return false;
		if(vis[tx][ty] || s[tx][ty] == '*') continue;
		if(!dfs(tx, ty)) return false;
	}
	return true;
}

void cal(int x, int y) {
	f[x][y] = 2;
	for(int i = 0; i < 4; i++) {
		int tx = x + V[i][0];
		int ty = y + V[i][1];
		if(tx < 0 || tx > n - 1 || ty < 0 || ty > m - 1) continue;
		if(f[tx][ty] || s[tx][ty] == '*') continue;
		cal(tx, ty);
	}
}

int find(int x) {
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

std::vector<int>q;
int main() {
	scanf("%d%d%d", &n, &m, &K);
	for(int i = 0; i < n; i++)
		scanf("%s", s[i]);

	int tot = 1;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			id[i][j] = tot++;
	for(int i = 0; i < tot; i++) {
		fa[i] = i; count[i] = 1;
	}

	memset(f, 0, sizeof f);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(s[i][j] == '.') {
				memset(vis, 0, sizeof vis);
				if(!dfs(i, j)) {
					cal(i, j);
				}
			}
			else f[i][j] = 1;


	for(int i = 0; i < n - 1; i++)
		for(int j = 0; j < m - 1; j++) if(f[i][j] == 0){
			int v = find(id[i][j]);
			if(f[i + 1][j] == 0) {
				int u = find(id[i + 1][j]);
				if(u != v) {
					int add = count[u];
					count[v] += add;
					fa[u] = v;
				}
			}
			if(0 == f[i][j + 1]) {
				int u = find(id[i][j + 1]);
				int add = count[u];
				if(u != v) {
					count[v] += add;
					fa[u] = v;
				}
			}
		}
		
	std::vector< std::pair<int, int> >q;
	for(int i = 0; i != n; i++)
		for(int j = 0; j != m; j++) 
			if((find(id[i][j]) == id[i][j]) && f[i][j] == 0) {
				q.push_back(std::make_pair(count[id[i][j]], id[i][j]));
			}
	std::sort(q.begin(), q.end());
	long long ans = 0;
	for(int i = 0; i < q.size() - K; i++) {
		ff[q[i].second] = true;
		ans += q[i].first;
	}
	printf("%I64d\n", ans);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			if(f[i][j] == 2)
				printf("%c", '.');
			else if(ff[find(id[i][j])]) printf("%c", '*');
			else if(f[i][j]) printf("*");
			else if(0 == f[i][j]) printf(".");
			if(j == m - 1) puts("");
		}
	return 0;
}

