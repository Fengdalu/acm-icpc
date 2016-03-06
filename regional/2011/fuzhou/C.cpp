#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

const int Maxn = 500010;
const int Maxm = Maxn * 2;
const int Pow = 20;
int ind[Maxn];
int id[Maxn], inv[Maxn];
long long v[Maxn];
int t[Maxm], nt[Maxm], c[Maxn];
int f1[Maxn][Pow], f2[Maxn][Pow];
int cnt;
int n;
int root;

void rmq() {
	for(int i = 1; i <= n; i++) f1[i][0] = f2[i][0] = query(root, 0, n - 1, id[i]);
	std::cout << "f1 " << std::endl;
	for(int i = 1; i <= n; i++) std::cout << f1[i][0] << " " ;
	std::cout << std::endl;

	for(int j = 0; j < Pow; j++)
		for(int i = 1; i < n + 1; i++)
	    if(i + (1 << (j + 1)) <= n + 1) {
			f1[i][j + 1] = std::max(f1[i][j], f1[i + (1 << j)][j]);
		}

	for(int j = 0; j < Pow; j++)
		for(int i = 1; i < n + 1; i++)
	    if(i + (1 << (j + 1)) <= n + 1) {
			f2[i][j + 1] = std::min(f2[i][j], f2[i + (1 << j)][j]);
		}
}

long long cal1(int l, int r) {
	int k = log2(r - l + 1);
	return std::max(f1[l][k], f1[r - (1 << k) + 1][k]);
}

long long cal2(int l, int r) {
	int k = log2(r - l + 1);
	return std::min(f2[l][k], f2[r - (1 << k) + 1][k]);
}

int main() {
	int m;
	while(~scanf("%d%d", &n, &m)) {
		if(!n && !m) break;
		cnt = idx = cnt1 = 0;
		root = build(0, n - 1);
		memset(ind, -1, sizeof ind);
		for(int i = 0; i < n - 1; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			add(a, b, c);
			add(b, a, c);
		}
		long long res = dfs(1, -1, 0);
		std::cout << "ok" << std::endl;
		rmq();
		while(m--) {
			long long q;
			scanf("%lld", &q);
			int ans = 0;
			for(int i = 1; i <= n; i++) {
				int l = i, r = n;
				while(l < r) {
					int mid = (l + r + 1) / 2;
					long long min = cal2(i, mid);
					long long max = cal1(i, mid);	
					if(max - min > q) r = mid - 1;
					else l = mid;
				}
				ans = std::max(ans, l - i + 1);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
