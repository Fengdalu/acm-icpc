#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const LL Mod = 1e9 + 7;
LL dp[2000], dp1[2000];
char s[2000];


int main() {
	while(~scanf("%s", s)) {
		int len = strlen(s);
		memset(dp, 0, sizeof dp);
		memset(dp1, 0, sizeof dp1);
		dp[1] = 1;
		for(int i = 0; i < len; i++) {
			LL tot = 0;
			for(int j = 1; j <= i + 1; j++) {
				if(s[i] == 'I')
					dp1[j + 1] = (dp1[j + 1] + dp[j]) % Mod;
				else 
					dp1[j] = (dp1[j] + dp[j]) % Mod;
					tot = (tot + dp[j]) % Mod;
			}
			if(s[i] == 'D') {
				for(int j = i + 2; j >= 1; j--) dp1[j] = (dp1[j] + dp1[j + 1]) % Mod;
			}
			else if(s[i] == 'I') {
				for(int j = 1; j <= i + 2; j++) dp1[j] = (dp1[j - 1] + dp1[j]) % Mod;
			}
			else {
				for(int j = 1; j <= i + 2; j++) dp1[j] = tot;
			}
			swap(dp, dp1);
			for(int j = 0; j <= i + 3; j++) dp1[j] = 0;
		}
		LL ans = 0;
		for(int i = 1; i <= len + 1; i++) ans = (ans + dp[i]) % Mod;
		printf("%lld\n", ans);
	}
	return 0;
}
