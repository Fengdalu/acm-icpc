#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[100];
int n;

void run() {
	cin >> n;
	cin >> s;
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'B') ans += (1LL << i);
	}
	cout << ans << endl;
}

int main() {
	run();
}
