#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int c[500];
int n, m;

void run() {
	cin >> n >> m;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int i = 1; i <= 2 * m; i++) cin >> c[i];
		for(int i = 1; i <= m; i++) if(c[i * 2] || c[i * 2 - 1]) ans++;
	}
	cout << ans << endl;
}

int main() {
	run();
	return 0;
}
