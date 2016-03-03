#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int r[6000], c[6000];
int t1[6000], t2[6000];

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= k; i++) {
		int op, x, v;
		cin >> op >> x >> v;
		if(op == 1) {
			r[x] = v;
			t1[x] = i;
		}
		else {
			c[x] = v;
			t2[x] = i;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(t1[i] > t2[j]) cout << r[i];
			else cout << c[j];
			cout << " ";
		}
		cout << endl;
	}
}
