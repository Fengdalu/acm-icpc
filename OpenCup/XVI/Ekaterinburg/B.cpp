#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool a[10000000];
int cnt;
int main() { 
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		for(int j = 1; j * j <= x; j++) 
		if(x % j == 0) {
			if(j < 1e7) a[j] = true;
			if(x / j < 1e7) a[x / j] = true;
		}
	}
	int m;
	for(int i = 1; ;i++) {
		if(!a[i]) {
			m = i;
			break;
		}
	}
	cout << m;
}

