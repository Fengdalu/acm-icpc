#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[2000];
int n;
int f[2000];

void run() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < i; j++)
		if(a[j] < a[i]) 
			f[i] = max(f[i], f[j]);
		f[i]++;
		ans = max(f[i], ans);
	}
	printf("%d\n", ans);
}

int main() {
	run();
}
