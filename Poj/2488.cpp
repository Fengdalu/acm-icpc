#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int V[8][2] = {
	{-2, -1}, 
	{-2, 1},
	{-1, -2}, 
	{-1, 2},
	{1, -2},
	{1, 2},
	{2, -1}, 
	{2, 1}
};
int p, q;
bool vis[26][26];
int ax[26 * 26], ay[26 * 26];
int cnt;

bool dfs(int x, int y) {
	if(cnt == p * q) return true;
	if(x <= 0 || x > p || y <= 0 || y > q) return false;
	if(vis[x][y]) return false;
	vis[x][y] = true;
	ax[cnt] = x;
	ay[cnt] = y;
	cnt++;
	for(int i = 0; i < 8; i++) {
		if(dfs(x + V[i][0], y + V[i][1])) return true;
	}
	cnt--;
	vis[x][y] = false;
	return false;
}

void run(int CASE) {
	scanf("%d%d", &q, &p);
	cnt = 0;
	for(int i = 1; i <= q; i++) {
		memset(vis, 0, sizeof vis);
		if(dfs(1, i)) {
			printf("Scenario #%d:\n", CASE);
			for(int i = 0; i < cnt; i++) 
				printf("%c%d", 'A' - 1 + ax[i], ay[i]);
			puts("");
			puts("");
			return;
		}
	}
	printf("Scenario #%d:\n", CASE);
	puts("impossible");
	puts("");
}

int main() {
	int nCase;
	scanf("%d", &nCase);
	for(int i = 1; i <= nCase; i++)
			run(i);
	return 0;
}
