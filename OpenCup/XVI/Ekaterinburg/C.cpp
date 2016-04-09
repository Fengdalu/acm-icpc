#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	if(n == 2) {
		cout << k << " " << 0 << endl;
	}
	else if(k < 2) {
		for(int i = 0; i < n - 3; i++) cout << "-1 ";
		cout << k << " " << 0 << endl;
	}
	else {
		for(int i = 0; i < n - 2; i++) cout << "-1 ";
		cout << k - 1 << " " << 1 << endl;
	}
	return 0;
}
