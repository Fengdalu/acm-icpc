#include <iostream>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

struct node {
	int x, y;
	double l;
}nodes[2000000];
const int INF = 1e9;
int cnt;
int x[2000], y[2000]; 
double p[2000];
int fa[2000];
int ind[2000];
int t[4000], nt[4000];
int a[4000], b[4000]; 
double c[4000];
int n;

int cmp(node a, node b) {
	return a.l < b.l;
}

void add(int a, int b) {
	t[cnt] = b;
	nt[cnt] = ind[a];
	ind[a] = cnt++;
}

double sqr(double x) { return x * x; }

double dfs(int x, int fa) {
	double v = p[x];
	for(int k = ind[x]; k != -1; k = nt[k]) 
	if(t[k] != fa) {
		v = max(v, dfs(t[k], x));	
	}
	return v;
}

double dis(double x, double y, double a, double b) {
	return sqrt(sqr(x - a) + sqr(y - b));
}

int find(int x) {
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

int main() {
	int CASE;
	scanf("%d", &CASE);
	for(int T = 1; T <= CASE; T++) {
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d%d%lf", &x[i], &y[i], &p[i]);

		int cnt1 = 0;
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++) {
				nodes[cnt1].x = i;
				nodes[cnt1].y = j;
				nodes[cnt1].l = dis(x[i], y[i], x[j], y[j]);
				cnt1++;
			}

		sort(nodes, nodes + cnt1, cmp);
		int cnt2 = 0;
		for(int i = 0; i < n; i++) fa[i] = i;
		for(int i = 0; i < n; i++) ind[i] = -1;
		cnt = 0;
		double tot = 0;
		for(int i = 0; i < cnt1; i++)  
		if(find(nodes[i].x) != find(nodes[i].y)) {
			a[cnt2] = nodes[i].x;
			b[cnt2] = nodes[i].y;
			c[cnt2] = nodes[i].l;
			tot += nodes[i].l;
			cnt2++;
			fa[find(nodes[i].x)] = find(nodes[i].y);
			add(nodes[i].x, nodes[i].y);
			add(nodes[i].y, nodes[i].x);
		}
		double ans = 0;
		for(int i = 0; i < cnt2; i++) {
			ans = max(ans, (dfs(a[i], b[i]) + dfs(b[i], a[i])) / (tot - c[i]) );
		}
		printf("%.2f\n", ans);
	}
	return 0;
}

