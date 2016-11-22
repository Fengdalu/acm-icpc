#include <cstdio>
#include <cstring>
#include <iostream>

const int Inf = 1e9;
int dp[1000][1000];

int main() {
	int a, b;
	std::cin >> a >> b;
	int ans = 0;
	for(int i = 0; i < 5000; i++) {
		if(a == 0 || b == 0) break;
		if(a >= 3) {
			a -= 2;
			b += 1;
			ans++;
			continue;
		}
		if(b >= 3) {
			a ++;
			b -= 2;
			ans++;
			continue;
		}
		if(a >= 2) {
			a -= 2;
			b += 1;
			ans++;
			continue;
		}
		if(b >= 2) {
			a ++;
			b -= 2;
			ans++;
			continue;
		}
	}
	std::cout << ans << std::endl;
}

