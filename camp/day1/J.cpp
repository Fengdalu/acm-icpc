#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define N 3000

int c[N];
int lowbit(int x){
	return x & (-x);
}

void insert(int x) {
	while(x <= n){
		c[x] += 1;
		x = lowbit(x);
	}
}

int calc(int x) {
	int ans = 0;
	while(x) {
		ans += c[x];
		x += lowbit(x);
	}
}
int main() {
	
}

