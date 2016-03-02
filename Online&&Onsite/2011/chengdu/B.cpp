#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;

LL cal(LL n, LL m, LL k) {
	if(n == 1 && m == 1 && k == 1) return 0;
	LL ans = n * m * k - 1;
	if(n != 1) ans = min(ans, cal((n + 1) / 2, m, k) + 1);
	if(m != 1) ans = min(ans, cal(n, (m + 1) / 2, k) + 1);
	if(k != 1) ans = min(ans, cal(n, m, (k + 1) / 2) + 1);
	return ans;
}

LL cal(LL x) {
	if(x == 1) return 0;
	return cal((x + 1) / 2) + 1;
}

int main() {
	int CASE;
	scanf("%d", &CASE);
	int n, m, k;
	for(int T = 1; T <= CASE; T++) {
		scanf("%d%d%d", &n, &m, &k);
		LL ans = cal(n) + cal(m) + cal(k);
		printf("Case #%d: %I64d %I64d\n", T, n * m * k - 1LL, ans);
	}
	return 0;
}
