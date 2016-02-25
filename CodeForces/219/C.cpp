#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;

int n;
int c[600000];

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) cin >> c[i];
	sort(c, c + n);
	int ans = 0;
	int J = n / 2;
	for(int i = 0; i < n / 2; i++) {
		while(J < n && 2 * c[i] > c[J]) J++;
		if(J == n) break;
		ans++; J++;
	}
	cout << n - ans << endl;
}
