#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int Maxn = 5010;

int c[Maxn][Maxn];
int valid[Maxn];
bool dp[Maxn][Maxn];
char s[Maxn], t[Maxn];
int n, m;

int lowbit(int x) { return x & (-x); }
void insert(int x, int y) {
	while(x < Maxn) {
		int k = y;
		while(k < Maxn) {
			c[x][k] += 1;
			k += lowbit(k);
		}
		x += lowbit(x);
	}
}

int query(int x, int y) {
	int ans = 0;
	while(x > 0) {
		int k = y;
		while(k > 0) {
			ans += c[x][k];
			k -= lowbit(k);
		}
		x -= lowbit(x);
	}
	return ans;
}

int query(int x, int y, int a, int b) {
	return query(a, b) - query(x - 1, b) - query(a, y - 1) + query(x - 1, y - 1);
}

int main() {
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1);
	m = strlen(t + 1);
	for(int i = 1; i <= m; i++) {
		valid[i] = i;
		if(t[i] == t[i + 1]) valid[i] = 0;
		else valid[i] = m + 1;
	}
	memset(c, 0, sizeof c);
	dp[n + 1][m + 1] = true;
	insert(n + 1, m + 1);
	for(int i = n; i >= 1; i--)
		for(int j = m; j >= 1; j--) if(s[i] == t[j]) {
			if(dp[i + 1][j + 1]) dp[i][j] = true;
			if(query(i + 1, n + 1, j + 1, valid[j]) > 0) dp[i][j] = true;
			if(dp[i][j]) insert(i, j);
		}
	if(dp[1][1]) puts("Yes");
	else puts("No");
 	return 0;
}
