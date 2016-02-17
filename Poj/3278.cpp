#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int Maxn = 1000100;
int n, k;
int vis[Maxn];

void run() {
	scanf("%d%d", &n, &k);
	memset(vis, -1, sizeof vis);
	queue<int>Q;
	Q.push(n);
	vis[n] = 0;
	while(Q.size()) {
		int x = Q.front();
		if(x == k) break;
		Q.pop();
		if(x - 1 >= 0 && -1 == vis[x - 1]) {
			Q.push(x - 1);
			vis[x - 1] = vis[x] + 1;
		}
		if(x + 1 < Maxn && -1 == vis[x + 1]) {
			Q.push(x + 1);
			vis[x + 1] = vis[x] + 1;
		}
		if(2 * x < Maxn && -1 == vis[2 * x]) {
			Q.push(2 * x);
			vis[2 * x] = vis[x] + 1;
		}
	}
	printf("%d\n", vis[k]);
}

int main() {
	run();
	return 0;
}
