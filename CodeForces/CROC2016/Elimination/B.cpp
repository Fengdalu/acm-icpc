#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

long long n, k;
int main() {
	std::cin >> n >> k;
	long long ans = 0;
	for(int i = 0; i < k && n >= 2; i++) {
		ans += (n - 1) + (n - 2);
		n -= 2;
	}
	std::cout << ans << std::endl;
}
