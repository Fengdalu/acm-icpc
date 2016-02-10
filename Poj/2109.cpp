#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
	double k, n;
	while(~scanf("%lf%lf", &k, &n)) {
		printf("%.0f\n", pow(n, 1 / k));
	}
}
