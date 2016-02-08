#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

bool vis[3];
char buf[3];
double H, T, D, h;

int read() {
	double tmp; 
	scanf("%s%lf", buf, &tmp);
	if(buf[0] == 'T') {
		T = tmp;
		vis[0] = true;
	}
	if(buf[0] == 'H') {
		H = tmp;
		vis[1] = true;
	}
	if(buf[0] == 'D') {
		D = tmp;
		vis[2] = true;
	}
	if(buf[0] == 'E') return -1;
	return 1;
}

double trans(double d) {
	double e = 6.11 * exp(5417.7530 * (1 / 273.16 - (1.0 / (d + 273.16))));
	return 0.5555 * (e - 10.0);
}

double cal(double h) {
	double e = h / 0.5555 + 10.0;
	return -1.0 / (log(e / 6.11) / 5417.7530 - 1 / 273.16) - 273.16;
}

int main() {
	while(true) {
		memset(vis, 0, sizeof vis);
		if(read() == -1) break;
		read();
		if(!vis[0]) {
			T = H - trans(D);
		}
		if(!vis[1]) {
			H = T + trans(D);
		}
		if(!vis[2]) {
			D = cal(H - T);
		}
		printf("T %.1f D %.1f H %.1f\n", T, D, H);
	}
	return 0;
}
