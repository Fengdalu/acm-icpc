#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool vis[110];
bool used[1100];
pair<int, int>a[1010];
int n, m;

int main() {
	int T;
	scanf("%d", &T);
	for(int ii = 1; ii <= T; ii++) {
		scanf("%d%d", &n, &m);
		int l, r;
		for(int i = 0; i < n; i++) scanf("%d%d", &a[i].second, &a[i].first);
		l = a[0].second;
		r = a[0].first;
		sort(a, a + n);
		int ans = 0;	
		for(int i = l; i <= r; i++)	 {
			memset(vis, 0, sizeof(bool) * (m + 3));
			memset(used, 0, sizeof(bool) * (n + 3));
			int tot = 0;
			vis[i] = true;
			for(int j = 1; j <= m; j++) 
			if(!vis[j]) {
				int it = -1;
				for(int k = 0; k < n; k++)
				if(!used[k] && (a[k].second <= j && j <= a[k].first))
					if(it == -1) {
						it = k;
						break;
					}
				if(it != -1) {
					vis[j] = true;
					used[it] = true;
				}
			}
			for(int j = 0; j < n; j++)
			if(used[j]) tot++;
			ans = max(ans, tot);
		}
		printf("Case #%d: %d\n", ii, ans);
	}
	return 0;
}
