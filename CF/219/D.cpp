#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;
int n, m, q;
char s[50][50];
LL sub[50][50];
LL dat[50][50][50][50];
LL f[50][50][50][50];

int main() {
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++)
		scanf("%s", s[i] + 1);

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			sub[i][j] = sub[i - 1][j] + sub[i][j - 1] - sub[i - 1][j - 1];
			if(s[i][j] == '1') sub[i][j]++;
		}

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			for(int a = i; a <= n; a++)
				for(int b = j; b <= m; b++) {
					int val = sub[a][b] - sub[i - 1][b] - sub[a][j - 1] + sub[i - 1][j - 1];	
					if(val == 0) dat[i][j][a][b]++;
				}

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			for(int a = 1; a <= n; a++)
				for(int b = 1; b <= m; b++) {
					f[i][j][a][b] = f[i - 1][j][a][b] 
									+ f[i][j - 1][a][b] 
									+ f[i][j][a - 1][b]
									+ f[i][j][a][b - 1]
									- f[i - 1][j - 1][a][b] 
									- f[i - 1][j][a - 1][b]
									- f[i - 1][j][a][b - 1]
									- f[i][j - 1][a - 1][b]
									- f[i][j - 1][a][b - 1]
									- f[i][j][a - 1][b - 1]
									+ f[i][j - 1][a - 1][b - 1]
									+ f[i - 1][j][a - 1][b - 1]
									+ f[i - 1][j - 1][a][b - 1]
									+ f[i - 1][j - 1][a - 1][b]
									- f[i - 1][j - 1][a - 1][b - 1]
									+ dat[i][j][a][b];
				}
	
	while(q--) {
		int i, j, a, b;
		cin >> i >> j >> a >> b;
		i--;
		j--;
		cout << f[a][b][a][b]
				- f[i][b][a][b]
				- f[a][j][a][b]
				- f[a][b][i][b]
				- f[a][b][a][j]
				+ f[i][j][a][b]
				+ f[i][b][i][b]
				+ f[i][b][a][j]
				+ f[a][j][i][b]
				+ f[a][j][a][j]
				+ f[a][b][i][j]
				- f[a][j][i][j]
				- f[i][b][i][j]
				- f[i][j][a][j]
				- f[i][j][i][b]
				+ f[i][j][i][j]
			<< endl;
	}
	return 0;
}
