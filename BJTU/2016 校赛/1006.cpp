#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 550;
char s[maxn][maxn];
int vis[maxn][maxn];
int n, m;
int vx[4] = {1, 0, -1, 0};
int vy[4] = {0, -1, 0, 1}; 

int main() {
	int T;
	scanf("%d", &T);
	for(int ii = 0; ii < T; ii++) {
		scanf("%d%d", &n, &m);
		int x, y;
		scanf("%d%d", &x, &y);
		memset(vis, 0, sizeof vis);
		for(int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
		queue<pair<int, int> >q;
		q.push(make_pair(x, y));
		for(int i = 0; i <= n + 1; i++) s[i][0] = s[i][m + 1] = '*';
		for(int i = 0; i <= m + 1; i++) s[0][i] = s[n + 1][i] = '*';
		vis[x][y] = true;
		while(q.size()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if(s[x][y] == '*') continue;
			for(int i = 0; i < 4; i++)  {
				int tx = x + vx[i];
				int ty = y + vy[i];
				if(!vis[tx][ty]) {
					vis[tx][ty] = true;
					q.push(make_pair(tx, ty));
				}
			}
		}

		int cnt = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
			if(vis[i][j] && s[i][j] == '*')
				cnt++;
		printf("Case %d: %d\n", ii + 1, cnt);
	}
	return 0;
}
