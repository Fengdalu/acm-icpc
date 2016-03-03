#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

char s[1000];
int c[20];
int to[2000][4];
char w['Z'];
int word[1100];
int fail[1100];
int dp[1100][1 << 11], dp1[1100][1 << 11];
int cnt;
int Hash[1 << 11];
const int INF = 1e9;

void insert(char *a, int mask) {
	int p = 0;
	while(*a) {
		int v = w[*a];
		if(!to[p][v]) {
			to[p][v] = ++cnt;
			memset(to[cnt], 0, sizeof to[cnt]);
		}
		p = to[p][v];
		a++;
	}
	word[p] |= mask;
}

void ac() {
	queue<int>q;
	memset(fail, 0, sizeof fail);
	for(int i = 0; i < 4; i++) if(to[0][i]) {
		q.push(to[0][i]);	
	}
	while(q.size()) {
		int p = q.front();
		q.pop();
		for(int i = 0; i < 4; i++) {
			int v = to[p][i];
			if(v) {
				fail[v] = to[fail[p]][i];
				word[v] |= word[fail[v]];
				q.push(v);
			}
			else 
				to[p][i] =  to[fail[p]][i];
		}
	}
}

int main() {
	int n, l;
	w['A'] = 0;
	w['G'] = 1;
	w['C'] = 2;
	w['T'] = 3;

	while(~scanf("%d%d", &n, &l)) {
		cnt = 0;
		memset(word, 0, sizeof word);
		memset(to[0], 0, sizeof to[0]);
		memset(Hash, 0, sizeof Hash);
		memset(fail, 0, sizeof fail);
		for(int i = 0; i < n; i++) {
			scanf("%s%d", s, &c[i]);
			insert(s, 1 << i);
		}
		int mask = (1 << n) - 1;
		for(int i = 0; i <= mask; i++)
			for(int j = 0; j < n; j++)
			if(1 << j & i) Hash[i] += c[j];

		ac();
		memset(dp, 0, sizeof dp);
		memset(dp1, 0, sizeof dp1);
		dp[0][0] = 1;		
		for(int i = 0; i < l; i++) {

			for(int j = 0; j <= cnt; j++)		
				for(int k = 0; k <= mask; k++)
					dp1[j][k] = 0;

			for(int j = 0; j <= cnt; j++)		
				for(int k = 0; k <= mask; k++)
					for(int p = 0; p < 4; p++) if(dp[j][k]) {
						int v = to[j][p];
						dp1[v][k | word[v]] |= dp[j][k];
					}
			swap(dp, dp1);
		}
		int ans = -INF;
		for(int i = 0; i <= cnt; i++)	
			for(int j = 0; j <= mask; j++)
			if(dp[i][j]) {
				ans = max(ans, Hash[j]);
			}

		if(ans >= 0)
		 	printf("%d\n", ans);
		else puts("No Rabbit after 2012!");
	}
	return 0;
}
