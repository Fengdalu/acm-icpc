#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int c[51][2];
int s[40];
int main() {
	int T;
	c[0][0] = 1;
	c[1][1] = 1;
	c[1][0] = 1;
	for(int i = 1; i < 50; i++) {
		c[i + 1][1] += c[i][0];
		c[i + 1][0] += c[i][1] + c[i][0];
	}
	scanf("%d", &T);
	for(int ii = 0; ii < T; ii++) {
		int x;
		scanf("%d", &x);
		x++;
		int l = 0;
		while(x) {
			s[l++] = x % 2;
			x /= 2;
		}
		int ans = 0;
		int pre = -1;
		while(l) {
			int x = s[--l];
			if(x == 1) ans += c[l][0] + c[l][1];
			if(x == 1 && pre == 1) break;
			pre = x;
		}
		printf("Case %d: %d\n", ii + 1, ans);
	}	
	return 0;
}
