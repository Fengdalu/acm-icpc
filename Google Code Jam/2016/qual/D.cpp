#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;

long long k, c, s;

int main() {
	int T;
	cin >> T;
	for(int ii = 0; ii < T; ii++) {
		cin >> k >> c >> s;
		cout << "Case #" << ii + 1 << ": ";
		vector<int>q;
		if(s * c < k) cout << "IMPOSSIBLE";
		else {
			for(int i = 1; i <= k; i += c) {
				long long p = 1;
				for(int j = 0; j < c; j++)
					p = (p - 1) * k + 1 + (long long)(i + j) % k;	
				cout << p << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
