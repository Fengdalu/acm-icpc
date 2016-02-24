#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int c[2000000];

void run() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &c[i]);
	nth_element(c, c + n / 2, c + n);
	printf("%d\n", c[n / 2]);
}

int main() {
	run();
}
