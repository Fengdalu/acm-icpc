#include <iostream>
#include <cstdio>
#include <cstring>
#include <bitset>
using namespace std;

bitset<1005>dp;
int n, m, d;
int main() {
	int T;
	scanf("%d", &T);
	for(int ii = 0; ii < T; ii++) {
		scanf("%d%d%d", &n, &m, &d);
		int tot = 0;
		dp.reset();
		dp[0] = 1;
		for(int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			tot += x;
			dp |= dp << x;
		}
		
		for(int i = d; i >= 0; i--) 
		if(dp[i]) {
			tot -= i;
			break;
		}
		int fee = 1e9;
		for(int i = 0; i < m; i++) {
			int v, c;
			scanf("%d%d", &c, &v);
			if(c >= tot) fee = min(fee, v);
		}
		if(tot == 0) fee = 0;
		if(fee != 1e9) printf("Case %d: %d\n", ii + 1, fee);
		else printf("Case %d: QAQ\n", ii + 1);
	}
	return 0;
}
