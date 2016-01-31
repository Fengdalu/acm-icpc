#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int Maxn = 1001;

int c[5000];
int d[5000];

int main() {
	int n;
	long long ans = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		c[x + y]++;
		d[x - y + 1000]++;
	}
	for(int i = 0; i < 5000; i++) ans += (c[i] * (c[i] - 1)) / 2;
	for(int i = 0; i < 5000; i++) ans += (d[i] * (d[i] - 1)) / 2;
	cout << ans << endl;
	return 0;
}
