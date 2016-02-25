#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#include <set>
using namespace std;

set<unsigned>s;
int Hash[1000000];
int a[6];

unsigned int f(int p) {
	unsigned p = 0;
	for(int i = 0; i < 6; i++) {
		p = p * 10 + (unsigned)a[(i + p) % 6];
	}
	return p;
}

int main() {
	memset(Hash, -1, sizeof Hash);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 6; j++) scanf("%d", &a[j]);
	}
}
