#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define ONES(x) __builtin_popcount(x)
const int Maxn = 402;
const int Maxk = 10;

int dp[Maxn][Maxn];
bool pre[Maxn][Maxn];
int c[Maxn][Maxn];
int v[Maxn][Maxn];
int n, k, w;
vector< pair<int, int> >Q;

int main() {
	scanf("%d%d%d", &n, &k, &w);
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= n; j++) 
			scanf("%d", &v[i][j]);
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= n; j++) 
			scanf("%d", &c[i][j]);
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= n; j++) 
			c[i][j]--;

	int ans = k + 1;
	for(int mask = 0; mask < (1 << k); mask++) 
	if(1 << c[1][1] & mask) {
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dp[i][j] = w + 1;

		dp[1][1] = v[1][1];
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++) if(dp[i][j] <= w) {
				if(1 << c[i + 1][j] & mask) 
					if(dp[i + 1][j] > v[i + 1][j] + dp[i][j]) {
						dp[i + 1][j] = dp[i][j] + v[i + 1][j];
						pre[i + 1][j] = 0;
					}

				if(1 << c[i][j + 1] & mask) 
					if(dp[i][j + 1] > v[i][j + 1] + dp[i][j]) {
						dp[i][j + 1] = v[i][j + 1] + dp[i][j];
						pre[i][j + 1] = 1;
					}
			}
		if(dp[n][n] <= w) ans = min((int)ONES(mask), ans);
	}
	if(ans == k + 1) {
		puts("-1");
		return 0;
	}
	for(int mask = 0; mask < (1 << k); mask++) 
	if(1 << c[1][1] & mask) if(ONES(mask) == ans){
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dp[i][j] = w + 1;

		dp[1][1] = v[1][1];
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++) if(dp[i][j] <= w) {
				if(1 << c[i + 1][j] & mask) 
					if(dp[i + 1][j] > v[i + 1][j] + dp[i][j]) {
						dp[i + 1][j] = dp[i][j] + v[i + 1][j];
						pre[i + 1][j] = 0;
					}

				if(1 << c[i][j + 1] & mask) 
					if(dp[i][j + 1] > v[i][j + 1] + dp[i][j]) {
						dp[i][j + 1] = v[i][j + 1] + dp[i][j];
						pre[i][j + 1] = 1;
					}
			}
		if(dp[n][n] > w) continue;
		Q.push_back(make_pair(n, n));
		int x = n, y = n;
		while(x != 1 || y != 1) {
			if(pre[x][y] == 0) x--;
			else y--;
			Q.push_back(make_pair(x, y));
		}
		break;
	}
	printf("%d\n", ans);
	reverse(Q.begin(), Q.end());
	for(int i = 0; i < Q.size(); i++) printf("%d %d ", Q[i].first, Q[i].second);
	return 0;
}
