#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
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
		for(int i = 0; i < primes.size(); i++) {
			if(!prime[n - primes[i]]) {
				int x = n - primes[i], y = primes[i];
				if(x > y) swap(x, y);
				printf("%d = %d + %d\n", n, x, y);
				break;
			}
		}
	}
	return 0;
}

