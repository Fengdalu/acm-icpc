#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;
const int Maxm = 400000;
const int Maxn = 200000;
int ind[Maxn], f[Maxn];
int nt[Maxm], t[Maxm], c[Maxm];
int cnt;
int n;
LL ans = 0;

void add(int a, int b, LL v) {
	t[cnt] = b;
	c[cnt] = v;
	nt[cnt] = ind[a];
	ind[a] = cnt++;
}


LL dfs(int x, int p) {
	LL tot = 0;
	for(int k = ind[x]; k != -1; k = nt[k]) if(t[k] != p) {
		LL num = dfs(t[k], x);
		ans += min(n - num, num) * c[k];
		tot += num;
	}
	return tot + 1;
}

int main() {
	int CASE;
	scanf("%d", &CASE);
	for(int T = 1; T <= CASE; T++) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) ind[i] = -1;
		cnt = 0;
		for(int i = 1; i < n; i++) {
			int a, b; LL c;
			scanf("%d%d%I64d", &a, &b, &c);
			add(a, b, c);
			add(b, a, c);
		}
		ans = 0;
		dfs(1, -1);
		printf("Case #%d: %I64d\n", T, ans * 2LL);
	}
}
