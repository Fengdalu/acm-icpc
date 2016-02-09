#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int Maxn = 2000;
const double eps = 1e-8;
int n;
double d;
vector< pair<double, double> >interval;

int run(int CASE) {
	scanf("%d%lf", &n, &d);
	if(n == 0 && d == 0) return 1;
	interval.clear();
	bool flag = false;
	for(int i = 0; i < n; i++) {
		double x, y;
		scanf("%lf%lf", &x, &y);
		if(flag || y > d + eps || y < 0) {
			flag = true;
			continue;
		}
		double L = sqrt(d * d - y * y);
		interval.push_back(make_pair(x + L, x - L));
	}
	if(d <= 0 || flag) {
		printf("Case %d: -1\n", CASE);
		return 0;
	}
	sort(interval.begin(), interval.end());
	double R = interval[0].first;
	int ans = 1;
	for(int i = 0; i < n; i++) {
		double l = interval[i].second;
		double r = interval[i].first;
		if(l > R + eps) {
			ans++;
			R = r;
		}
	}
	printf("Case %d: %d\n", CASE, ans);
	return 0;
}

int main() {
	int CASE = 1;
	while(!run(CASE++));
	return 0;
}
