#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int a[300000];
int n, m;
int r[300000], t[300000];
int s[300000];
struct node {
	int r, t, w;
	node(){}
	node(int r, int t, int w): r(r), t(t), w(w) {}
}q[300000];

int cmp(node a, node b) {
	if(a.r == b.r) return a.w > b.w;
	return a.r > b.r;
}

int main() {
	scanf("%d%d", &n, &m);

	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < m; i++) {
		int r, t;
		cin >> t >> r;
		q[i] = node(r, t, i);
	}
	sort(q, q + m, cmp);
	int mode = q[0].t;
	
	int l = 0, r = 0;
	for(int i = 1; i <= q[0].r; i++) s[r++] = a[i];
	sort(s, s + r);	

	int J = q[0].r;
	int k = q[0].w;
	for(int i = 1; i < m; i++) {
		while(J > q[i].r) {
			if(mode == 2) { a[J] = s[l++]; }
			else { a[J] = s[--r];  } 
			J--;
		}
		if(q[i].w > k) {
			mode = q[i].t;
			k = q[i].w;
		}
	}

	while(J > 0) {
		if(mode == 2) { a[J] = s[l++]; }
		else { a[J] = s[--r];  } 
		J--;
	}

	for(int i = 1; i <= n; i++) printf("%d ", a[i]);
	return 0;
}
