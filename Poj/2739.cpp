#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int Maxn = 11005;

bool isPrime[Maxn];
vector<int>primes;
int dp[Maxn];
int sum[Maxn];

void euler() {
	memset(isPrime, 0, sizeof isPrime);
	for(int i = 2; i < Maxn; i++) {
		if(!isPrime[i]) primes.push_back(i);
		for(int j = 0; j < primes.size() && i * primes[j] < Maxn; j++) {
			isPrime[i * primes[j]] = true;
			if(i % primes[j] == 0) break;
		}
	}
}

int main() {
	euler();
	memset(dp, 0, sizeof dp);
	memset(sum, 0, sizeof sum);
	dp[0] = 1;
	for(int i = 0; i < primes.size(); i++) {
		dp[0] = 1;
		for(int j = Maxn - 1; j >= 0; j--) {
			if(j + primes[i] < Maxn) dp[j + primes[i]] += dp[j];
			dp[j] = 0;
		}
		for(int j = 0; j < Maxn; j++) sum[j] += dp[j];
	}
	int n;
	sum[0] = 0;
	while(true) {
		scanf("%d", &n);
		if(n == 0) break;
		printf("%d\n", sum[n]);
	}
	return 0;
}
