#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define PII pair<int, int>
#define A first
#define B second
#define MP(x, y) make_pair(x, y)
#define PB(x) push_back(x)
#define SZ size()
#define OP begin()
#define ED end()

const int Maxn = 100000;
struct state {
	int mask;
	int pre;
	int x, y;
}Q[Maxn];
bool vis[1 << 20];

int op(int x, int y) {
	int cur = 0;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++)
			if(i == x || y == j) 
				cur = 1 | cur << 1;
			else 
				cur <<= 1;
	}
	return cur;
}
int add[5][5];
char buf[10];
vector<PII>ans;

int main() {	
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			add[i][j] = op(i, j);
	int st = 0;
	for(int i = 0; i < 4; i++) {
		scanf("%s", buf);
		for(int j = 0; j < 4; j++) {
			if(buf[j] == '+') st = 1 | st << 1;
			else st <<= 1;
		}
	}

	int l = 0, r = 0;
	memset(vis, 0, sizeof vis);

	Q[l].x = Q[l].y = -1;
	Q[l].mask = st;
	Q[l].pre = -1;
	vis[st] = true;

	while(l <= r) {
		state p = Q[l++];
		if(p.mask == 0) { r = l - 1; break; }
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++)
			if(!vis[add[i][j] ^ p.mask]) {
				vis[add[i][j] ^ p.mask] = true;
				r++;
				Q[r].x = i;
				Q[r].y = j;
				Q[r].mask = add[i][j] ^ p.mask;
				Q[r].pre = l - 1;
			}
	}
	while(Q[r].pre != -1) {
		ans.PB(MP(Q[r].x, Q[r].y));
		r = Q[r].pre;
	}
	reverse(ans.OP, ans.ED);
	printf("%d\n", ans.SZ);
	for(int i = 0; i < ans.SZ; i++) printf("%d %d\n", ans[i].A + 1, ans[i].B + 1);
	return 0;	
}