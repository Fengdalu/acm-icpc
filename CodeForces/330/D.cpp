#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
double R, v;
double s, f;
const double eps = 1e-9;

void run() {
	cin >> n >> R >> v;
	while(n--) {
		cin >> s >> f;
		double l = 0, r = (f - s) / v;
		while(fabs(r - l) / r > eps) {
			double t = (l + r) / 2.0;
			double d = f - s - v * t - fabs(2.0 * R * sin(v * t / R / 2.0));
			if(d > 0) l = t;
			else r = t;
		}
		char buf[100];
		sprintf(buf, "%.19f", r);
		cout << buf << endl;
	}
}

int main() {
	run();
	return 0;
}
