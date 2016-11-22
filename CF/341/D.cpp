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
const long double eps = 1e-10;

long double a[Maxn], b[Maxn];
long double x, y, z;

const char* result[12] = {
	"x^y^z",
	"x^z^y",
	"(x^y)^z",
	"(x^z)^y",
	"y^x^z",
	"y^z^x",
	"(y^x)^z",
	"(y^z)^x",
	"z^x^y",
	"z^y^x",
	"(z^x)^y",
	"(z^y)^x"	
};

int main() {
	cin >> x >> y >> z;
	a[0] = z * log(y);
	a[1] = y * log(z);
	a[2] = a[3] = log(y) + log(z);
	a[4] = z * log(x);
	a[5] = x * log(z);
	a[6] = a[7] = log(x) + log(z);
	a[8] = y * log(x);
	a[9] = x * log(y);
	a[10] = a[11] = log(x) + log(y);

	b[0] = b[1] = b[2] = b[3] = log(x);
	b[4] = b[5] = b[6] = b[7] = log(y);
	b[8] = b[9] = b[10] = b[11] = log(z);
	bool flag = false;
	for(int i = 0; i < 12; i++) flag |= (b[i] > 0);
	if(flag) {
		int pos = 0;
		for(int i = 0; i < 12; i++) if(b[i] > 0) {
			pos = i;
			break;
		}
		for(int i = 0; i < 12; i++) if(b[i] > 0) {
			if(a[i] + log(b[i]) > a[pos] + log(b[pos]) + eps)
				pos = i;
		}
		printf("%s\n", result[pos]);
	}
	else {
		int pos = 0;
		for(int i = 0; i < 12; i++) b[i] *= -1.0;
		for(int i = 0; i < 12; i++) {
			if(a[i] + log(b[i]) + eps < a[pos] + log(b[pos]))	
				pos = i;
		}
		printf("%s\n", result[pos]);
	}
	return 0;
}
