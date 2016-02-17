#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int Maxn = 2000000;
long long q[Maxn];

int run() {
	int n;
	scanf("%d", &n);
	if(n == 0) return 1;
	int l = 0, r = 0;
	q[0] = 1;
	while(l <= r) {
		long long x = q[l];
		l++;
		if(x % (long long)n == 0) {
			printf("%lld\n", x);
			return 0;
		}
		else {
			q[++r] = x * 10;
			q[++r] = x * 10 + 1;
		}
	}
	return 0;
}
int main() {
	while(!run());
	return 0;
}
