#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

LL f[20];

int main() {
	LL w, m, k;
	cin >> w >> m >> k;
	f[1] = 9;
	for(int i = 2; i < 20; i++) f[i] = f[i - 1] * 10;

	LL b = w / k;
	LL ans = 0;
	m--;
	for(int i = 1; i < 20; i++) {
		if(m >= f[i]) {
			m -= f[i];
			f[i] = 0;
		}
		else {
			f[i] -= m;
			break;
		}
	}
	for(int i = 1; i < 20; i++) {
		if(f[i] * i <= b) {
			ans += f[i];
			b -= f[i] * i;
		}
		else {
			LL t = b / i;
			ans += t;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
