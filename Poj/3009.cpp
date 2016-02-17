#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int vis[50][50][4];
int g[50][50];
struct pt {
	int x, y;
	pt(){}
	pt(int x, int y): x(x), y(y) {}
}S, T;
struct state {
	int x, y, d;
	state() {}
	state(int x, int y, int d): x(x), y(y), d(d) {}
};
queue<state>Q;
int n, m;

const int V[4][2] = {
	{1, 0},
	{-1, 0},
	{0, 1},
	{0, -1}
};

void run() {
	scanf("%d%d", &m, &n);
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= m; j++)
			scanf("%d", &g[i][j]);		
	for(int i = 0; i <= n + 1; i++) g[i][m + 1] = g[i][0] = 4;
	for(int i = 0; i <= m + 1; i++) g[0][i] = g[n + 1][i] = 4;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)  {
			if(g[i][j] == 2) {
				S = pt(i, j);
			}
			else if(g[i][j] == 3) 
				T = pt(i, j);
		}
						
	while(Q.size()) Q.pop();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			for(int k = 0; k < 4; k++)
				vis[i][j][k] = n * m;
	for(int i = 0; i < 4; i++) Q.push(state(S.x, S.y, i));
	for(int i = 0; i < 4; i++) vis[S.x][S.y][i] = 0;
	while(Q.size()) {
		state p = Q.front();
		Q.pop();
		int c = vis[p.x][p.y][p.d];
		int d = g[p.x + V[p.d][0]][p.y + V[p.d][1]];
		if(d == 1) {
				
		}
		else if(d == 0) {

		}
	}
}

int main() {

}

