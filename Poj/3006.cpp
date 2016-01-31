#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int Maxn = 1000010;

bool prime[Maxn];
vector<int>numbers;

void init() {
	memset(prime, 0, sizeof prime);
	for(int i = 2; i < Maxn; i++) {
		if(!prime[i]) numbers.push_back(i);
		for(int j = 0; j < numbers.size() && i * numbers[j] < Maxn; j++) {
			prime[numbers[j] * i] = true;
			if(i % numbers[j] == 0) break;
		}
	}
}

int main() {
	init();
	int a, d, n;
	while(true) {
		scanf("%d%d%d", &a, &d, &n);
		if(!a && !d && !n) break;
		for(int i = 0; i < numbers.size() && n; i++) {
			if(numbers[i] - a >= 0 && (numbers[i] - a) % d == 0) n--;
			if(n == 0) printf("%d\n", numbers[i]);
		}
	}
	return 0;
}
