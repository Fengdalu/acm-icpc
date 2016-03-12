#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

const int maxn = 200;
const int maxm = maxn * maxn * 4;
const int Inf = maxn * maxn;

int x[maxn], y[maxn], a[maxn], b[maxn];
int base[maxn * 2];
int cover[maxn][maxn][2];
int id[maxn][maxn][2];
int ind[maxn * maxn];
int to[maxm], nt[maxm], c[maxm];
bool vis[maxn * maxn];
int f[maxn * maxn];
int x1, y1, x2, y2;
int w, h;
int n;
int cnt;
int ncnt;

int get(int x, int y, int d) {
	if(id[x][y][d] == -1) { 
		return id[x][y][d] = ++ncnt; 
	}
	return id[x][y][d];
}

void add(int a, int b, int v) {
	to[cnt] = b;
	nt[cnt] = ind[a];
	c[cnt] = v;
	ind[a] = cnt++;
}

void add2(int a, int b, int v) {
	add(a, b, v);
	add(b, a, v);
}

int spfa(int from, int dest) {
	memset(vis, 0, sizeof vis);
	std::queue<int>q;
	for(int i = 1; i <= ncnt; i++) f[i] = Inf;
	q.push(from);
	f[from] = 0;
	while(q.size()) {
		int x = q.front();
		q.pop();
		vis[x] = false;
		for(int k = ind[x]; k != -1; k = nt[k]) {
			if(f[x] + c[k] < f[to[k]]) {
				f[to[k]] = f[x] + c[k];
				if(!vis[to[k]]) {
					q.push(to[k]);
					vis[to[k]] = true;
				}
			}
		}
	}
	return f[dest];
}

int main() {
	while(true) {
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if(!x1 && !x2 && !y1 && !y2) break;
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d%d%d%d", &x[i], &y[i], &a[i], &b[i]);
		memset(ind, -1, sizeof ind);
		cnt = 0;
		int cnt;

		cnt = 0;
		base[cnt++] = x1;
		base[cnt++] = x2;
		for(int i = 0; i < n; i++) base[cnt++] = x[i];
		for(int i = 0; i < n; i++) base[cnt++] = a[i];
		std::sort(base, base + cnt);
		cnt = std::unique(base, base + cnt) - base;
		for(int i = 0; i < n; i++) x[i] = std::lower_bound(base, base + cnt, x[i]) - base + 1;
		for(int i = 0; i < n; i++) a[i] = std::lower_bound(base, base + cnt, a[i]) - base + 1;
		x1 = std::lower_bound(base, base + cnt, x1) - base + 1;
		x2 = std::lower_bound(base, base + cnt, x2) - base + 1;
		w = cnt + 1;

		cnt = 0;
		base[cnt++] = y1;
		base[cnt++] = y2;
		for(int i = 0; i < n; i++) base[cnt++] = y[i];
		for(int i = 0; i < n; i++) base[cnt++] = b[i];
		std::sort(base, base + cnt);
		cnt = std::unique(base, base + cnt) - base;
		for(int i = 0; i < n; i++) y[i] = std::lower_bound(base, base + cnt, y[i]) - base + 1;
		for(int i = 0; i < n; i++) b[i] = std::lower_bound(base, base + cnt, b[i]) - base + 1;
		y1 = std::lower_bound(base, base + cnt, y1) - base + 1;
		y2 = std::lower_bound(base, base + cnt, y2) - base + 1;
		h = cnt + 1;

		ncnt = 0;
		memset(cover, -1, sizeof cover);
		memset(id, -1, sizeof id);	
		for(int i = 0; i < n; i++) {
			for(int l = x[i]; l < a[i]; l++)
				for(int r = y[i]; r < b[i]; r++)
					cover[l][r][0] = cover[l][r][1] = 0;
			
			for(int l = x[i]; l < a[i]; l++) {
				cover[l][y[i]][0] = 1;
				cover[l][b[i]][0] = 2;
			}
			for(int r = y[i]; r < b[i]; r++) {
				cover[x[i]][r][1] = 3;
				cover[a[i]][r][1] = 4;
			}
		}
		
		for(int i = 0; i < w; i++)
			for(int j = 0; j < h; j++) {
				if(cover[i][j][0] != 0) {
					if(cover[i + 1][j][0] != 0) 
						if(!(cover[i + 1][j][1] == 3 && cover[i + 1][j - 1][1] == 4))
							if(!(cover[i + 1][j][1] == 4 && cover[i + 1][j - 1][1] == 3)) {
								add2(get(i, j, 0), get(i + 1, j, 0), 0);
							}

					if(cover[i + 1][j][1] != 0)
						if(!(cover[i + 1][j][1] == 4 && cover[i + 1][j - 1][1] == 3)) {
								add2(get(i, j, 0), get(i + 1, j, 1), 1);
							}
				}
				if(cover[i][j][1] != 0) {
					if(cover[i][j + 1][1] != 0) {
						if(!(cover[i][j + 1][0] == 1 && cover[i - 1][j + 1][0] == 2))
							if(!(cover[i][j + 1][0] == 2 && cover[i - 1][j + 1][0] == 1)) {
								add2(get(i, j, 1), get(i, j + 1, 1), 0);
							}
					}

					if(cover[i][j + 1][0] != 0) {
						if(!(cover[i][j + 1][0] == 2 && cover[i - 1][j + 1][0] == 1)) {
							add2(get(i, j, 1), get(i, j + 1, 0), 1);
						}
					}
				}
			}
		int ans = 3;
		for(int i = 0; i < 2; i++)
	 		for(int j = 0; j < 2; j++) {
				ans = std::min(ans, spfa(get(x1, y1, i), get(x2, y2, j)));
			}
		if(ans < 3) printf("%d\n", ans);
		else printf("-1\n");
	}
	return 0;
}
