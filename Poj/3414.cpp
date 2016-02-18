#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
	int x, y;
	node(){}
	node(int x, int y) : x(x), y(y) {}
};
int vis[200][200];
node pre[200][200];
int tp[200][200];

int run() {
	int a, b, c;
	queue<node>Q;
	if(-1 == scanf("%d%d%d", &a, &b, &c)) return 0;
	memset(vis, -1, sizeof vis);
	Q.push(node(0, 0));
	vis[0][0] = 0;
	int tx = -1, ty = -1;
	while(Q.size()) {
		node p = Q.front();
		Q.pop();
		if(p.x == c || p.y == c) {
			tx = p.x;
			ty = p.y;
			break;
		}
		if(-1 == vis[a][p.y]) {
			vis[a][p.y] = vis[p.x][p.y] + 1;
			pre[a][p.y] = p;
			tp[a][p.y] = 1;
			Q.push(node(a, p.y));
		}
		if(-1 == vis[p.x][b]) {
			vis[p.x][b] = vis[p.x][p.y] + 1;
			pre[p.x][b] = p;
			tp[p.x][b] = 2;
			Q.push(node(p.x, b));
		}
		int q;
		q = min(a - p.x, p.y);
		if(-1 == vis[p.x + q][p.y - q]) {
			vis[p.x + q][p.y - q] = vis[p.x][p.y] + 1;
			pre[p.x + q][p.y - q] = p;
			tp[p.x + q][p.y - q] = 3;
			Q.push(node(p.x + q, p.y - q));
		}
		q = min(p.x, b - p.y);
		if(-1 == vis[p.x - q][p.y + q]) {
			vis[p.x - q][p.y + q] = vis[p.x][p.y] + 1;
			pre[p.x - q][p.y + q] = p;
			tp[p.x - q][p.y + q] = 4;
			Q.push(node(p.x - q, p.y + q));
		}
		if(-1 == vis[0][p.y]) {
			vis[0][p.y] = vis[p.x][p.y] + 1;
			pre[0][p.y] = p;
			tp[0][p.y] = 5;
			Q.push(node(0, p.y));
		}
		if(-1 == vis[p.x][0]) {
			vis[p.x][0] = vis[p.x][p.y] + 1;
			pre[p.x][0] = p;
			tp[p.x][0] = 6;
			Q.push(node(p.x, 0));
		}
	}
	if(tx == -1 && ty == -1) {
		puts("impossible");
		return 1;
	}
	vector<int>ans;
	while(tx != 0 || ty != 0) {
		ans.push_back(tp[tx][ty]);
		node p = pre[tx][ty];
		tx = p.x;
		ty = p.y;
	}
	reverse(ans.begin(), ans.end());
	
	printf("%d\n", ans.size());
	for(int i = 0; i < ans.size(); i++) {
		if(ans[i] == 1) printf("FILL(1)\n");
		if(ans[i] == 2) printf("FILL(2)\n");
		if(ans[i] == 3) printf("POUR(2,1)\n");
		if(ans[i] == 4) printf("POUR(1,2)\n");
		if(ans[i] == 5) printf("DROP(1)\n");
		if(ans[i] == 6) printf("DROP(2)\n");
	}
	return 1;
}

int main() {
	run();
	return 0;
}
