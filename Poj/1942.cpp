#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

LL C(LL a, LL b) {
	double ans = 1;
	if(a - b < b) b = a - b;
	for(LL i = a; i > a - b; i--) {
		ans = ans * (double)i / (double)(i - a + b);
	}
	return ans + 0.5;
}


int run() {
	LL n, m;
	scanf("%lld%lld", &n, &m);
	if(n == 0 && m == 0) return 0;
	printf("%lld\n", C(n + m, n));
	return 1;
}

int main() {
	while(run());
	return 0;
}
