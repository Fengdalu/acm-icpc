#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

struct point {
	double x, y;
	void read() {
		scanf("%lf%lf", &x, &y);
	}
	point(){}
	point(double x, double y): x(x), y(y) {}
}a[10010][3];
int n;
const double eps = 1e-16;

double sqr(double x) { return x * x; }
double dis(const point &a, const point &b) {
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

int check(point a[3], point p) {
	point o(0, 0);
	for(int i = 0; i < 3; i++) o.x += a[i].x;
	for(int i = 0; i < 3; i++) o.y += a[i].y;
	o.x /= 3.0;
	o.y /= 3.0;
	double r = dis(o, a[0]);
	cout << p.x << " " << p.y << endl;
	cout << r << " " << dis(o, p) << endl;
	if(dis(o, p) < r) return false;
	return true;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < 3; j++) a[i][j].read();
	bool flag = true;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)	
		if(j != i) {
			for(int k = 0; k < 3; k++) 
				flag &= check(a[i], a[j][k]);
		}
		if(!flag) break;
	}
	if(flag) cout << "YES";
	else cout << "NO";
}
