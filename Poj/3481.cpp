#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 2e6;
struct node {
	int k, p;
	int ch[2];
	int pre;
} f[maxn];
int root;
int cnt;

void dfs(int x) {
	if(x == -1) return;
	dfs(f[x].ch[0]);
	cout << f[x].p << ' ';
	dfs(f[x].ch[1]);
}

void rot(int x, int t) {
		int y = f[x].pre;
		f[x].pre = f[y].pre;
		if(f[y].pre != -1) {
			if(f[f[y].pre].ch[0] == y) f[f[y].pre].ch[0] = x;
			else f[f[y].pre].ch[1] = x;
		}
		if(f[x].ch[t ^ 1] != -1) {
			f[f[x].ch[t ^ 1]].pre = y;
		}
		f[y].ch[t] = f[x].ch[t ^ 1];
		f[x].ch[t ^ 1] = y;
		f[y].pre = x;
}

void splay(int x, int target) {
	while(f[x].pre != target) {
		int y = f[x].pre, p = f[y].pre;
		if(f[y].ch[0] == x) {
				if(p == target) rot(x, 0);
				else {
						if(f[p].ch[0] == y) rot(y, 0), rot(x, 0);
						else rot(x, 0), rot(x, 1);
				}
		}
		else if(f[y].ch[1] == x) {
			if(p == target) rot(x, 1);
			else {
					if(f[p].ch[1] == y) rot(y, 1), rot(x, 1);
					else rot(x, 1), rot(x, 0);
			}
		}
	}
	if(target == -1) root = x;
	dfs(root);
}

void insert(int k, int p) {
	int x = cnt++;
	f[x].k = k;
	f[x].p = p;
	f[x].ch[0] = f[x].ch[1] = -1;
	f[x].pre = -1;
	int r = root;
	if(r == -1) {
			root = x;
			return;
	}
	while(true) {
		int t;
		if(p <= f[r].p) t = 0;
		else t = 1;
		if(f[r].ch[t] == -1) {
			f[r].ch[t] = x;
			f[x].pre = r;
			break;
		}
		else r = f[r].ch[t];
	}
	splay(x, -1);
}

int get(int src, int t) {
	int r = src;
	if(r == -1) return -1;
	while(f[r].ch[t] != -1) {
		r = f[r].ch[t];
	}
	return r;
}

void del(int x) {
		if(f[x].ch[0] == -1 && f[x].ch[1] == -1) root = -1;
		else {
				splay(x, -1);
				if(f[x].ch[0] == -1) {
					root = f[x].ch[1];
					f[root].pre = -1;
				}
				else if(f[x].ch[1] == -1) {
					root = f[x].ch[0];
					f[root].pre = -1;
					x = root;
				}
				else {
						int r = get(f[x].ch[1], 0);
						splay(r, x);
						f[r].ch[0] = f[x].ch[0];
						f[f[r].ch[0]].pre = r;
						f[r].pre = -1;
						root = r;
				}
		}
}

int main() {
		freopen("tree.in", "r", stdin);
		int op, x, y;
		root = -1;
		while(true) {
			scanf("%d", &op);
			if(op == 0) break;
			if(op == 1) {
				scanf("%d%d", &x, &y);
				insert(x, y);
			}
			else if(op == 2) {
				int r = get(root, 1);
				if(r == -1) puts("0");
				else {
					printf("%d\n", f[r].k);
					del(r);
				}
			}
			else{
				int r = get(root, 0);
				if(r == -1) puts("0");
				else {
					printf("%d\n", f[r].k);
					del(r);
				}
			}
		}
}
