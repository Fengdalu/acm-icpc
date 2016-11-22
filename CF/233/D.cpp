#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int Maxn = 3000;
double dp[Maxn][Maxn];
bool vis[Maxn], vis1[Maxn];

int main() {
	int n, m;
	cin >> n >> m;
	memset(vis, 0, sizeof vis);
	memset(vis1, 0, sizeof vis1);
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		vis[x] = vis1[y] = true;
	}
	int r = 0, c = 0;
	for(int i = 1; i <= n; i++) 
		if(vis[i]) r++;
	for(int i = 1; i <= n; i++)
		if(vis1[i]) c++;
	dp[n][n] = 0.0;
	for(int i = n; i >= 0; i--)
		for(int j = n; j >= 0; j--)
		if(i != n || j != n) {
			double k = n * n - i * j; 
			double a = (n - i) * j;
			double b = i * (n - j);
			double c = (n - i) * (n - j);
			dp[i][j] = (a * dp[i + 1][j] + b * dp[i][j + 1] + c * dp[i + 1][j + 1] + n * n)/ k;
		}
	printf("%.10f\n", dp[r][c]);
}
