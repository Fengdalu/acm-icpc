#include <bits/stdc++.h>

typedef unsigned long long u64;

const int N = 515;
char s[N];
int dp[N][N];
std::vector<int> p[N];

void Init() {
	//Pow[0] = 1;
	//for(int i = 1; i < N; i++) Pow[i] = Pow[i - 1] * Base;
	for(int i = 0; i < N; i++)
		for(int j = 1; j < i; j++)
			if(i % j == 0) p[i].push_back(j);
}

/*
void Init(u64* Hash, int len) {
	Hash[len] = 0;
	for(int i = len; i >= 0; i--) Hash[i] = (u64)Hash[i + 1] * Base + (s[i] - 'a' + 1);
}
*/

/*
u64 Get(u64* Hash, int p, int L) {
	return Hash[p] - Hash[p + L] * Pow[L];
}
*/

bool chk(int a, int b, int w) {
	for(int i = 0; i < w; i++)
		if(s[a + i] != s[b + i]) return false;
	return true;
}

int getlen(int x) {
	if(x >= 1000) return 4;
	if(x >= 100) return 3;
	if(x >= 10) return 2;
	return 1;
}


int cal(int l, int r) {
	if(l == r) return 1;
	int &now = dp[l][r];
	if(now != -1) return now; 
	now = r - l + 1;
	int len = r - l + 1;
	for(int k = l; k < r; k++)
		now = std::min(now, cal(l, k) + cal(k + 1, r));
	for(int i = 0; i < p[len].size(); i++) {
		int w = p[len][i];
		bool flag = true;
		int count = 0;
		for(int j = l; j <= r; j += w) {
			if(chk(l, j, w) == false) flag = false;
		}
		if(!flag) continue;
		now = std::min(cal(l, l + w - 1) + 2 * (int)(w != 1) + getlen(len / w), now);
	}
	return now;
}

int main() {
	int n, cas = 1;
	Init();
	while(true) {
		scanf("%s", s + 1);
		if(s[1] == '0') break;
		n = strlen(s + 1);
		//Init(Hash, n);
		memset(dp, -1, sizeof dp);
		printf("Case %d: %d\n", cas++, cal(1, n));
	}
	return 0;
}

[close]

