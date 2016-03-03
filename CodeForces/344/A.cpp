#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int a[2000], b[2000];
int n;


int main() {
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];

	long long a1 = 0, a2 = 0;
	for(int i = 0; i < n; i++) a1 |= a[i];
	for(int i = 0; i < n; i++) a2 |= b[i];
	cout << a1 + a2 << endl;

	return 0;
}
