#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

int n;
vector<int>s;

int main() {
	scanf("%d", &n);
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		s.push_back(x);
		ans += x;
	}
	if(ans % 2 == 0) printf("%lld\n", ans);
	else {
		sort(s.begin(), s.end());
		for(int i = 0; i < n; i++) if(s[i] % 2 == 1){
			ans -= s[i];
			break;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
