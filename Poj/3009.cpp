#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int vis[50][50][4];
int g[50][50];
int n, m;
int sx, sy;
const int V[4][2] = {
	{1, 0},
	{-1, 0},
	{0, -1},
	{0, 1}
};


int ans;
int cnt;
void dfs(int x, int y, int d) {
	if(x < 0 || x > n - 1 || y < 0 || y > m - 1) return;
	if(cnt > 10) return;
	if(g[x][y] == 3) ans = min(cnt, ans);
	bool flag = false;
	while(true) {
		int dx = x + V[d][0];
		int dy = y + V[d][1];
		if(dx < 0 || dx > n - 1 || dy < 0 || dy > m - 1) return;
		if(g[dx][dy] == 1) {
			if(!flag) return;
			g[dx][dy] = 0;
			cnt++;
			for(int i = 0; i < 4; i++) dfs(x, y, i);
			g[dx][dy] = 1;
			cnt--;
			return;
		}
		if(g[dx][dy] == 3) ans = min(cnt, ans);
		x = dx;
		y = dy;
		flag = true;
	}
}

int run() {
	scanf("%d%d", &m, &n);
	if(n == 0 && m == 0) return 1;
	
	memset(g, 0, sizeof g);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d", &g[i][j]);
	
	int tx, ty;
	ans = (int)1e7;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		if(g[i][j] == 2) {
			for(int k = 0; k < 4; k++) {
				cnt = 1;
				vis[i][j][k] = 1;
				dfs(i, j, k);
			}
		}

	if(ans != (int)1e7) printf("%d\n", ans);
	else puts("-1");
	return 0;
}

int main() {
	while(!run());
	return 0;
}
