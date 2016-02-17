#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int l, n, m;
char s[40][40][40];
int vis[40][40][40];
struct state {
	int x, y, z;
	state(){}
	state(int z, int x, int y): x(x), y(y), z(z) {}
};

const int V[6][3] = {
	{1, 0, 0},
	{-1, 0, 0},
	{0, 1, 0}, 
	{0, -1, 0},
	{0, 0, 1},
	{0, 0, -1}
};

state q[40 * 40 * 40];
char buf[10];
int run() {
	scanf("%d%d%d", &l, &n, &m);
	if(l == 0 && n == 0 && m == 0) return 1;
	for(int i = 1; i <= l; i++) {
		for(int j = 1; j <= n; j++) scanf("%s", s[i][j] + 1);
	}
	for(int i = 0; i <= n + 1; i++)
		for(int j = 0; j <= m + 1; j++)	
			s[0][i][j] = s[l + 1][i][j] = '#';
	
	for(int i = 0; i <= l + 1; i++) {
		for(int j = 0; j <= n + 1; j++) s[i][j][0] = s[i][j][m + 1] = '#';
		for(int j = 0; j <= m + 1; j++) s[i][0][j] = s[i][n + 1][j] = '#';
	}

	memset(vis, -1, sizeof vis);
	state ed;
	for(int i = 1; i <= l; i++) 
		for(int j = 1; j <= n; j++)
			for(int k = 1; k <= m; k++) {
				if(s[i][j][k] == 'S') q[0] = state(i, j, k);
				else if(s[i][j][k] == 'E') ed = state(i, j, k);
			}

	vis[q[0].z][q[0].x][q[0].y] = 0;
	int l = 0, r = 0;
	while(l <= r) {
		state p = q[l++];
		for(int i = 0; i < 6; i++)  {
			int x = p.x + V[i][0];
			int y = p.y + V[i][1];
			int z = p.z + V[i][2];
			if(s[z][x][y] != '#' && -1 == vis[z][x][y]) {
				vis[z][x][y] = vis[p.z][p.x][p.y] + 1;
				q[++r] = state(z, x, y);
			}
		}
	}
	if(-1 != vis[ed.z][ed.x][ed.y])
		printf("Escaped in %d minute(s).\n", vis[ed.z][ed.x][ed.y]);
	else puts("Trapped!");
	return 0;
}

int main() {
	while(!run());
	return 0;
}
