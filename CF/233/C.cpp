#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long sqr(long long x) { return x * x; }
typedef long long LL;

void run() {
	LL a, b;
	cin >> a >> b;	
	if(a == 0) {
		cout << -b * b << endl;
		for(int i = 0; i < b; i++) cout << 'x';
		return;
	}
	if(b == 0) {
		cout << a * a << endl;
		for(int i = 0; i < a; i++) cout << 'o';
		return;
	}
	if(a == 1) {
		long long c = b / 2;
		cout << 1 - sqr(c) - sqr(b - c) << endl;
		for(int i = 0; i < c; i++) cout << 'x';
		cout << 'o';
		for(int i = 0; i < b - c; i++) cout << 'x';
		return ;
	}
	if(b == 1) {
		cout << a * a - 1LL << endl;
		for(int i = 0; i < a; i++) cout << 'o';
		cout << 'x';
		return ;
	}

	LL ans = -1;
	LL p = -1;
	for(LL i = 1; i <= a; i++) {
		LL ans1 = (i - 1) + sqr(a - i + 1);
		LL t = i + 1;
		if(t > b) break;
		LL q = b % t;
		LL c = b / t;
		LL ans2 = (t - q) * sqr(c) + q * sqr(c + 1);
		if(i == 1) { 
			ans = ans1 - ans2;
			p = i;
		}
		else if(ans1 - ans2 > ans) {
			ans = ans1 - ans2;
			p = i;
		}
	}
	cout << ans << endl;
	LL c = b / (p + 1);
	LL cnt = b % (p + 1);

	for(int i = 0; i < c; i++) cout << 'x';
	for(int i = 0; i < a - p + 1; i++) cout << 'o';
	for(int i = 0; i < p - 1; i++) {
		if(cnt) {
			for(int j = 0; j < c + 1; j++) cout << 'x';
			cnt--;
		}
		else {
			for(int j = 0; j < c; j++) cout << 'x';
		}
		cout << 'o';
	}
	if(cnt)
	for(int i = 0; i < c + 1; i++) cout << 'x';
	else 
	for(int i = 0; i < c; i++) cout << 'x';
}

int main() {
	run();
}
