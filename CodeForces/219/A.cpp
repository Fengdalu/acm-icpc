#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int c[10];

int main() {
	int k;
	cin >> k;
	k *= 2;
	char buf[10];
	for(int i = 0; i < 4; i++) {
		cin >> buf;
		for(int j = 0; j < 4; j++) if(buf[j] != '.')
			c[buf[j] - '0']++;
	}
	for(int i = 0; i < 10; i++)
	if(c[i] > k) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	return 0;
}
