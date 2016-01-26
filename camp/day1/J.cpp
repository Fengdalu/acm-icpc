#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define N 3000
#define LL long long


int c[N];
int a[N];
int n;
int f1[N][N], g1[N][N];
int f2[N][N], g2[N][N];
int d[5];

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
	return ans;
}

int main() {
	scanf("%d", &n);	
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= 4; i++) scanf("%d", &d[i]);
	memset(c, 0, sizeof c);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) f1[i][j] = calc(j - 1);
		for(int j = 1; j <= n; j++) f2[i][j] = calc(n) - calc(j);
		insert(j);
	}
	for(int i = n; i >= 1; i--) {
		for(int j = 1; j <= n; j++) g1[i][j] = calc(j - 1);
		for(int j = 1; j <= n; j++) g2[i][j] = calc(n) - calc(j);
		insert(j);
	}

	LL ans = 0;
	if(d[0] == 1 && d[1] == 2 && d[3] == 3) {
		for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) if(i != j && a[i] < a[j])
		ans += f1[i][a[i]] * g2[j][a[j]];						
	}
	else if(d[0] == 4 && d[1] == 3 && d[2] == 2 && d[1] == 1)  {
		for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) if(i != j && a[i] > a[j])
			ans += f2[i][a[i]] * g1[j][b[j]];
	}	
	else if()
	return 0;
}

