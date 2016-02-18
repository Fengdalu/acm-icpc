#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char w[700][40];
char s[500];
int dp[400];
int m, n;

void run() {
	scanf("%d%d", &m, &n);
	scanf("%s", s + 1);
	for(int i = 0; i < m; i++) scanf("%s", w[i]);
	dp[0] = 0;
	for(int i = 1; i <= n; i++) {
		dp[i] = n + 1;
		for(int j = 0; j < m; j++) {
			int J = strlen(w[j]) - 1;
			int k = i;
			while(J >= 0 && k >= 0) {
				if(w[j][J] == s[k]) J--;
				k--;
			}
			if(J < 0) 
				dp[i] = min(dp[i], dp[k] + i - k - (int)strlen(w[j]));
			else dp[i] = min(dp[i], i);
		}
	}
	printf("%d\n", dp[n]);
}

int main() {
	run();
	return 0;
}
