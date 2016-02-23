#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int T(char s) {
	switch(s) {
		case 'A': return 0;
		case 'C': return 1;
		case 'G': return 2;
		case 'T': return 3;
		case ' ': return 4;
	}
}
const int M[5][5] = {
	{+5, -1, -2, -1, -3},
	{-1, +5, -3, -2, -4},
	{-2, -3, +5, -2, -2},
	{-1, -2, -2, +5, -1},
	{-3, -4, -2, -1, 0}
};

int dp[200][200];
char a[200], b[200];
int n, m;
const int INF = 1e9;

void run() {
	scanf("%d%s", &n, a + 1);
	scanf("%d%s", &m, b + 1);
	a[0] = ' ';
	b[0] = ' ';
	for(int i = 1; i <= n; i++) 
		dp[i][0] = dp[i - 1][0] + M[T(a[i])][4];
	for(int i = 1; i <= m; i++)
		dp[0][i] = dp[0][i - 1] + M[4][T(b[i])];
	for(int i = 1; i <= n; i++)	
		for(int j = 1; j <= m; j++) {
			dp[i][j] = -INF;
			dp[i][j] = max(dp[i][j], dp[i - 1][j] + M[4][T(a[i])]);
			dp[i][j] = max(dp[i][j], dp[i][j - 1] + M[4][T(b[j])]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + M[T(a[i])][T(b[j])]);
		}
	printf("%d\n", dp[n][m]);
}

int main() {
	int CASE; 
	scanf("%d", &CASE);
	while(CASE--) run();
}
