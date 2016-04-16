#include <iostream>
#include <cstdio>
using namespace std;

long long m;
long long gcd(long long a, long long b) {
	return ((b == 0) ? a : gcd(b, a % b));
}

int main() {
	int T;
	scanf("%d", &T);
	for(int ii = 0; ii < T; ii++) {
		cin >> m;
		long long tot = 0;
		for(int i = 1; i <= m; i++)
			tot += gcd(m, i);
		cout << "Case " << ii + 1 << ": " << m * m - tot << endl; 
	}
	return 0;
}
