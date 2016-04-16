#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for(int ii = 0; ii < T; ii++) {
		int n;
		scanf("%d", &n);
		int mask = 0;
		for(int i = 1; i < n; i++) {
			int t;
			scanf("%d", &t);
			mask ^= t;
		}
		printf("Case %d: %d\n", ii + 1, mask);
	}
	return 0;
}
