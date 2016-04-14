#include <iostream>
#include <cstdio>
using namespace std;

int vis[20000];

int main() {
	int T;
	cin >> T;
	for(int ii = 1; ii <= T; ii++) {
		memset(vis, 0, sizeof vis);
		string s;
		cin >> s;
		for(int i = 0; i < s.size(); i++)
		if(s[i] == '+') vis[i] = true;
		else vis[i] = false;
		int n = s.size();
		int mask = 0;
		int tot = 0;
		for(int i = n - 1; i >= 0; i--) {
			vis[i] ^= mask;
			if(!vis[i]) {
				mask ^= 1;
				tot++;
			}
		}
		printf("Case #%d: %d\n", ii, tot);
	}
	return 0;
}
