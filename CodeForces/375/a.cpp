#include <bits/stdc++.h>

int main() {
	int x1, x2, x3;
	std::cin >> x1 >> x2 >> x3;
	int ans = 100000;
	for(int i = 0; i <= 100; i++)
		ans = std::min(ans, abs(i - x1) + abs(i - x2) + abs(i - x3));
	std::cout << ans << std::endl;
	return 0;
}

