#include <iostream>
#include <cstdio>
#include <cstring>

const int Maxn = 2000000;
char s[Maxn];
int fail[Maxn];
int c[Maxn];
int v[Maxn];
int n;

int main() {
	int T = 1;
	while(~scanf("%d", &n)) {
		if(n == 0) break;
		scanf("%s", s + 1);
		int r = 0;
		fail[1] = 0;
		for(int i = 2; i <= n; i++) {
			while(r != 0 && s[r + 1] != s[i]) r = fail[r];
			if(s[r + 1] == s[i]) r++;
			fail[i] = r;
		}
		memset(v, 0, sizeof v);
		memset(c, 0, sizeof c);
		int ans = 1;
		printf("Test case #%d\n", T++);
		for(int i = 1; i <= n; i++) {
			if(i - fail[i] == v[fail[i]]) {
				v[i] = v[fail[i]];
				c[i] = c[fail[i]] + 1;
			}
			else {
				v[i] = i;
				c[i] = 1;
			}
		}
		for(int i = 1; i <= n; i++) 
		if(c[i] > 1) {
			printf("%d %d\n", i, c[i]);
		}
		puts("");
	}
	return 0;
}
