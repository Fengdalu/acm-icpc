#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int Maxn = 1000001;

bool prime[Maxn];
vector<int>primes;

void init() {
	memset(prime, 0, sizeof prime);
	prime[1] = true;
	prime[0] = true;
	for(int i = 2; i < Maxn; i++) {
		if(!prime[i]) primes.push_back(i);
		for(int j = 0; j < primes.size() && i * primes[j] < Maxn; j++) {
			prime[i * primes[j]] = true;
			if(i % primes[j] == 0) break;
		}
	}
}

int main() {
	init();	
	int n;
	while(true) {
		scanf("%d", &n);
		if(!n) break;
		int m = lower_bound(primes.begin(), primes.end(), n / 2) - primes.begin();
		for(int i = m; i > 0; i--) {
			if(!prime[n - primes[i]]) {
				printf("%d = %d + %d\n", n, primes[i], n - primes[i]);
				break;
			}
		}
	}
	return 0;
}

