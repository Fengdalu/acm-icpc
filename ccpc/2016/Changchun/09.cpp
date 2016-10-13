#include <bits/stdc++.h>

const int N = 2e5+10;
struct node {
	int l, r;
	int sum;
} f[100000000];
int rt[N];
int pos[N];
int a[N];
int cnt;

void build(int &rt, int l, int r) {
	rt = cnt++;
	node &p = f[rt];
	p.sum = 0;
	if(l == r) return;
	int mid = (l + r) >> 1;
	build(f[rt].l, l, mid);
	build(f[rt].r, mid + 1, r);
}

void update(int rt) {
	int l = f[rt].l, r = f[rt].r;
	f[rt].sum = f[l].sum + f[r].sum;
}


void insert(int &rt, int a, int b, int p, int fa, int v) {
	rt = cnt++;
	node &t = f[rt];
	t.l = f[fa].l;
	t.r = f[fa].r;
	t.sum = f[fa].sum;
	if(a == b) { 
		t.sum += v; 
		return ; 
	}
	int mid = (a + b) / 2;
	if(p <= mid) insert(t.l, a, mid, p, f[fa].l, v);
	else insert(t.r, mid + 1, b, p, f[fa].r, v);
	update(rt);
}

int cal(int rt, int a, int b, int l, int r) {
	if(l <= a && b <= r) return f[rt].sum;
	int mid = (a + b) >> 1;
	if(r <= mid) return cal(f[rt].l, a, mid, l, r);
	else if(l > mid) return cal(f[rt].r, mid + 1, b, l, r);
	else return cal(f[rt].l, a, mid, l, r) + cal(f[rt].r, mid + 1, b, l, r);	
}

int get(int rt, int a, int b, int pos) {
	if(a == b) return a;
	int mid = (a + b) >> 1;
	int left = f[f[rt].l].sum;
	if(pos <= left) return get(f[rt].l, a, mid, pos);
	else return get(f[rt].r, mid + 1, b, pos - left);
}

int main() {
	int _t; 
	scanf("%d", &_t);
	for(int cas = 1; cas <= _t; cas++) {
		int n, m;
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) scanf("%d", a + i);
		std::fill(pos, pos + N, 0);
		cnt = 0;
		build(rt[n + 1], 1, n);
		for(int i = n; i >= 1; i--) {
			if(pos[a[i]] == 0) insert(rt[i], 1, n, i, rt[i + 1], 1);
			else {
				int tmp;
				insert(tmp, 1, n, pos[a[i]], rt[i + 1], -1);
				insert(rt[i], 1, n, i, tmp, 1);
			}
			pos[a[i]] = i;
		}
		printf("Case #%d:", cas);
		int pre = 0;
		for(int i = 0; i < m; i++) {
			int l, r; scanf("%d%d", &l, &r);
			l = (pre + l) % n + 1;
			r = (pre + r) % n + 1;
			if(l > r) std::swap(l, r);
			int tot = cal(rt[l], 1, n, l, r);
			int pos = (tot + 1) / 2;
			pre = get(rt[l], 1, n, pos);
			printf(" %d", pre);
		}
		puts("");
	}
	return 0;
}

/*
1
7 1
1 1 1 1 1 2 3
1 7
*/
