#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

const int Maxn = 50010;
map<int, int>base;
typedef map<int, int>::iterator mit;
struct node{
	int l, r, h;
	int v;
	node(){}
	node(int l, int r, int h, int v): l(l), r(r), h(h), v(v) {}
}line[Maxn * 2];

int w, h, n, m;
int a[Maxn], b[Maxn], x[Maxn], y[Maxn];
long long ans = 0;

int cmp(node p, node q) {
	return p.h > q.h;
}

long long cal(long long l, long long r) {
	return max(0LL, (r - l - 1) - m + 1);
}

void run() {
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		line[cnt++] = node(a[i], x[i], b[i], -1);
		line[cnt++] = node(a[i], x[i], y[i], 1);
	}
	sort(line, line + cnt, cmp);

	base.clear();		
	base[0]++;
	base[w + 1]++;
	long long tot = cal(1, w);
	long long pre = h;
	for(int i = 0; i < cnt; i++) {
		mit l = base.lower_bound(line[i].l);
		mit r = base.lower_bound(line[i].r);
		while(l->first > line[i].l) l--;
		long long a = l->first;
		long long b = r->first;
		if(line[i].v > 0) {
			ans += (pre - line[i].h) * tot;
			tot = tot - cal(a, b) + cal(a, line[i].l) + cal(line[i].r, b);
			base[line[i].l]++;
			base[line[i].r]++;
		}
		else {
			tot = tot + cal(a, b) - cal(a, line[i].l) - cal(line[i].r, b);
			if(--base[line[i].l] == 0) {
				base.erase(base.find(line[i].l));
			}
			if(--base[line[i].r] == 0) {
				base.erase(base.find(line[i].r));
			}
			ans += (pre - line[i].h) * tot;
		}
		pre = line[i].h;
	}
	ans += (h - pre) * tot;
}


int main() {
	while(~scanf("%d%d%d%d", &w, &h, &n, &m)) {
		int cnt = 0;
		ans = 0;
		for(int i = 0; i < n; i++) {
			scanf("%d%d%d%d", &x[i], &y[i], &a[i], &b[i]);
		}
		run();
		swap(w, h);
		swap(x, y);
		swap(a, b);
		run();
		if(m == 1) ans /= 2LL;
		printf("%lld\n", ans);
	}
	return 0;
}
