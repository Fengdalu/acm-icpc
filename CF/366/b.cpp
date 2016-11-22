#include <bits/stdc++.h>

const int N = 2000;
char s[N][N];
int r[N], c[N];
int n, m;
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) scanf("%s", s + i);
	int tot = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) if(s[i][j] == '*')
			r[i]++, c[j]++, tot++;
	for(int i = 0; i < n; i++)	
		for(int j = 0; j < m; j++) {
			int sum = r[i] + c[j];
			if(s[i][j] == '*') sum--;
			if(sum == tot) {
				puts("YES");
				printf("%d %d\n", i + 1, j + 1);
				return 0;
			}
		}
	puts("NO");
	return 0;
}
