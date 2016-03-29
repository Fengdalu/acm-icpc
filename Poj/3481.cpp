#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 2000000;
struct node{
	int ch[2];
	int k, p;
	int pre;
	node(int k, int p): k(k), p(p) {
		ch[0] = ch[1] = -1;
		pre = -1;
	}
	node(){}
}f[maxn];
int root;
int cnt;

void rot(int x, int t) {
	int p = f[x].pre;	
	f[x].pre = f[p].pre;
	f[p].ch[t] = f[x].ch[t ^ 1];	
	f[f[x].ch[t ^ 1]].pre = p;
	f[x].ch[t ^ 1] = p;
	f[p].pre = x;
}

void splay(int x, int des) {
	while(true) {
		if(f[x].pre == des) break;
		int p = f[x].pre, pp = f[p].pre;
		if(pp == -1) {
			if(f[p].ch[0] == x) rot(x, 0);
			else rot(x, 1);
		}
		if(f[pp].ch[0] == p) {
			if(f[p].ch[0] == x) {
				rot(p, 0);
				rot(x, 0);
			}
			else {
				rot(x, 1);
				rot(x, 0);
			}
		}
		else {
			if(f[pp].ch[1] == p) {
				rot(p, 1);
				rot(x, 1);
			}
			else {
				rot(x, 0);
				rot(x, 1);
			}
		}
	}
}

void insert(int k, int p) {
	if(root == -1) {
		f[cnt] = node(k, p);
		root = cnt++;
	}
	else {
		int r = root;		
		int t;
		while(true) {
			cout << r << " " << f[r].k << " " << f[r].pre << endl;
			if(p <= f[r].p) t = 0;
			else t = 1;
			if(f[r].ch[t] == -1) {
				f[cnt] = node(k, p);
				f[cnt].pre = r;
				f[r].ch[t] = cnt;
				splay(cnt, -1);
				root = cnt;
				cnt++;
				break;
			}
			else r = f[r].ch[t];
		}
	}
}

int getmax(int root) {
	int r = root;	
	while(f[r].ch[1] != -1) {
		r = f[r].ch[1];	
	}
	return r;
}

int getmin(int root) {
	int r = root;
	while(f[r].ch[0] != -1) {
		r = f[r].ch[0];
	}
	return r;
}

void dfs(int x) {
	if(x == -1) return;
	cout << f[x].p << " ";

}

int main() {
	root = -1;
	while(true) {
		int op, k, p;
		scanf("%d", &op);
		if(op == 0) break;
		else if(op == 1) {
			scanf("%d%d", &k, &p);
			insert(k, p);
		}
		else if(op == 2) {
			if(root == -1) {
				printf("0\n");
				continue;
			}
			int p = getmax(root);	
			printf("%d\n", f[p].k);
			splay(p, -1);
			if(f[p].ch[1] == -1) {
				root = f[p].ch[0];
				if(root != -1) {
					f[root].pre = -1;
				}
			}
			else {
				int q = getmin(f[p].ch[1]);
				splay(q, p);
				int r = f[p].ch[0];
				f[q].ch[0] = r;
				if(r != -1) f[r].pre = q;
				f[q].pre = -1;
				root = q;
			}
		}
		else if(op == 3) {
			if(root == -1) {
				printf("0\n");
				continue;
			}
			int p = getmin(root);	
			printf("%d\n", f[p].k);	
			splay(p, -1);
			if(f[p].ch[0] == -1) {
				root = f[p].ch[1];
				if(root != -1) {
					f[root].pre = -1;
				}
			}
			else {
				int q = getmax(f[p].ch[0]);
				splay(q, p);
				int r = f[p].ch[1];
				f[q].ch[1] = r;
				if(r != -1) f[r].pre = q;
				f[q].pre = -1;
				root = q;
			}
		}
		cout << op << endl;
	}
	return 0;
}
