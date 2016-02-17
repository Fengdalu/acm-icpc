#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int pos[21];
int dp[20010], dp1[20010];
int c, g;

void run() {
	scanf("%d%d", &c, &g);
	for(int i = 0; i < c; i++) scanf("%d", &pos[i]);
	int t = 10000;
	memset(dp, 0, sizeof dp);
	memset(dp, 0, sizeof dp1);
	for(int i = 0; i < g; i++) {
		int x;
		scanf("%d", &x);
		memset(dp, 0, sizeof dp);
		if(i == 0) {
			for(int j = 0; j < c; j++)
				dp[t + pos[j] * x] = 1;
		}
		else {
			for(int j = 0; j < c; j++) {
				int w = pos[j] * x;
				for(int k = 0; k < 20010; k++)
				if(k + w < 20010 && k + w >= 0) {
					dp[k + w] += dp1[k];
				}
			}
		}
		swap(dp, dp1);
	}
	printf("%d", dp1[t]);
}

int main() {
	run();
	return 0;
}
