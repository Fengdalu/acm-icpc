#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int Maxn = 30;
char pre[Maxn], mid[Maxn];
struct node {
	char id;
	int l, r;
}nodes[Maxn * 10];
int root;
int cnt;
int J;

int dfs(int l, int r) {
	if(l > r) return -1;
	for(int i = l; i <= r; i++) if(mid[i] == pre[J]){
		int root = cnt++;
		nodes[root].id = pre[J];
		J++;
		nodes[root].l = dfs(l, i - 1);
		nodes[root].r = dfs(i + 1, r);
		return root;
	}
	return -1;
}

void post(int x) {
	if(x == -1) return ;
	post(nodes[x].l);
	post(nodes[x].r);
	printf("%c", nodes[x].id);
}

int main() {
	while(~scanf("%s%s", pre, mid)) {
		int n = strlen(pre);
		cnt = 0;
		J = 0;
		post(dfs(0, n - 1));
		puts("");
	}
	return 0;
}
