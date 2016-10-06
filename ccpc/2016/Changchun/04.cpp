#include <bits/stdc++.h>
const int ans[] = {0,0,0,0,1,1,2,3,3,4,5,6,7,7,8,9,10,11,12,13,14};

int main() {
	int t; scanf("%d", &t);
	for(int cas = 1; cas <= t; cas++) {
		int x; scanf("%d", &x);
		printf("Case #%d: %d\n", cas, ans[x]);
	}
	return 0;
}

