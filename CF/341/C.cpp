#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int Maxn = 100010;

int n, P;
int l[Maxn], r[Maxn];
double p[Maxn];

int cal(int R) { return R / P; } 

int main() {
	scanf("%d%d", &n, &P);
	for(int i = 0; i < n; i++) scanf("%d%d", &l[i], &r[i]);
	for(int i = 0; i < n; i++) p[i] = 1.0 * (cal(r[i]) - cal(l[i] - 1)) / (r[i] - l[i] + 1);
	double ans = 0.0;
	for(int i = 0; i < n; i++) {
		int j = (i + 1) % n;
		ans += p[i] * 1000.0;
		ans += p[j] * 1000.0;
		ans -= p[i] * p[j] * 1000.0;
	}
	printf("%.16f", 2.0 * ans);
	return 0;
}
