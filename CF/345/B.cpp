#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

int a[2000];
int n;

int main() {
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		a[x]++;
	}
	std::sort(a, a + 2000);
	int pre = 0;
	int ans = 0;
	for(int i = 0; i < 2000; i++) 
	if(a[i]) {
		ans += std::min(pre, a[i]);
		pre = a[i];
	}
	std::cout << ans << std::endl;
}
