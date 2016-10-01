#include <bits/stdc++.h>

/*
 * init: 4, 5, 1, 3, 2
 * ----> 4, 5, 1, 3, 2 == -0
 * ----> 4, 5, 1, 2, 3 == -1
 */

const int INF = 1e9+7;
const int N = 5000100;
std::pair<int, int> p[N * 2];
int a[N];
typedef long long ll;
int f[N];

struct BIT{
	int _[N+10];
	void insert(int x) {
		for(int i = x; i < N; i += i & (-i))
			_[i]++;
	}

	int cal(int x) {
		int tot = 0;
		for(int i = x; i != 0; i -= (i) & (-i))
			tot += _[i];
		return tot;
	}
} T;

std::pair<int, int> cal(int rt, int l, int r, int a, int b) {
	if(a <= l && r <= b) {
		return p[rt];
	}
	int mid = (l + r) >> 1;
	if(b <= mid) return cal(rt << 1, l, mid, a, b);
	else if(a > mid) return cal(rt << 1 ^ 1, mid + 1, r, a, b);
	else return std::min(cal(rt << 1, l, mid, a, b)
			, cal(rt << 1 ^ 1, mid + 1, r, a, b));
}

void modify(int rt, int l, int r, int x) {
	if(l == r)  {
		p[rt].first = INF;
		return ;
	}
	int mid = (l + r) >> 1;
	if(x <= mid) modify(rt << 1, l, mid, x);
	else modify(rt << 1 ^ 1, mid + 1, r, x);
	p[rt] = std::min(p[rt << 1], p[rt << 1 ^ 1]);
}

void build(int rt, int l, int r) {
	if(l == r) {
		p[rt].first = a[l];
		p[rt].second = l;
		return ;
	}
	int mid = (l + r) >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	p[rt] = std::min(p[rt << 1], p[rt << 1 ^ 1]);
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)  scanf("%d", a + i);
	ll sum = 0;
	for(int i = n; i >= 1; i--) {
		f[i] = T.cal(a[i] - 1);
		sum += 1ll * f[i];
		T.insert(a[i]);
	}
	printf("%I64d\n", sum);
	build(1, 1, n);
	while(m--) {
		int x; scanf("%d", &x);
		ll tot = f[x];
		f[x] = 0;
		while(true) {
			std::pair<int, int> t = cal(1, 1, n, x, n);
			if(t.first > a[x]) break;
			tot += f[t.second];
			f[t.second] = 0;
			modify(1, 1, n, t.second);
		}
		sum -= tot;
		printf("%I64d\n", sum);
	}
	return 0;
}
/*
   4 4
   120 130 140 110
   2
   3
   4
   1
 */
