 By SpideAce, contest: 2014-2015 ACM-ICPC East Central North America Regional Contest (ECNA 2014), problem: (D) Generalized Roman Numerals, Accepted, #

#include <bits/stdc++.h>

const int N = 51;
int dp[N][N][5010];
int cnt[N][N];
char s[N*N];
int ch[300];
int buf[3000000];
std::bitset<5001>vis;
int n;

void cal(int l, int r) {
	int *now = buf;
	int tot = cnt[l][r];
	if(tot != 0) return;
	if(l == r) {
		buf[tot++] = ch[s[l]];
		dp[l][r][cnt[l][r]++] = ch[s[l]];
		return ;
	}
	for(int i = l; i < r; i++) {
		cal(l, i); cal(i + 1, r);
	}
	vis.reset();
	for(int i = l; i < r; i++) {
		int *left = dp[l][i], *right = dp[i + 1][r];
		int tot1 = cnt[l][i], tot2 = cnt[i + 1][r];
		for(int j = 0; j != tot1; j++) {
			int cur = dp[l][i][j];
			int x = left[j];
			int st = 
				std::upper_bound(right, right + tot2, 5001 - x) - right;
			for(int k = 0; k != st; k++) {
				int y = right[k];
				if(y > x)  break;
				if(!vis[(x + y)])
					now[tot++] = (x + y);
				vis[(x + y)] = true;
			}
		}
	}
	for(int i = l; i < r; i++) {
		int *left = dp[l][i], *right = dp[i + 1][r];
		int tot1 = cnt[l][i], tot2 = cnt[i + 1][r];
		for(int k = 0; k != tot2; k++) {
			for(int j = 0; j < tot1; j++) {
				int x = left[j], y = right[k];
				if(x >= y) break;
				if(!vis[(y - x)])
					now[tot++] = (y - x);
				vis[(y - x)] = true;
			}
		}
	}
	std::sort(now, now + tot);
	tot = std::unique(now, now + tot) - now;
	int &cur = cnt[l][r];
	cur = 0;
	for(int i = 0; i < tot; i++) dp[l][r][cur++] = now[i];
}

int main() {
	ch['I'] = 1; ch['V'] = 5; ch['X'] = 10; ch['L'] = 50; ch['C'] = 100;
	int _cas = 1;
	while (true) {
		scanf("%s", s);
		if(s[0] == '0') break;
		n = strlen(s);
		for(int i = 0; i < n; i++)
			for(int j = i; j < n; j++)
				cnt[i][j] = 0;
		cal(0, n - 1);
		int * ans = dp[0][n - 1];
		int tot = cnt[0][n - 1];
		printf("Case %d: ", _cas++);
		for(int i = 0; i != tot; i++) {
			printf("%d%c", ans[i], " \n"[i == tot - 1]);
		}
	}
	return 0;
}


