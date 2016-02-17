#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int f[300];
int n;
int s[300];

void run() {
	scanf("%d", &n);
	s[0] = 0;
	for(int i = 1; i <= n; i++) {
		int c, m;
		scanf("%d%d", &m, &c);
		s[i] = m + s[i - 1];
		f[i] = (s[i] + 10) * c;
		for(int j = 1; j < i; j++)
			f[i] = min(f[i], (s[i] - s[j] + 10) * c + f[j]);
	}
	printf("%d\n", f[n]);
}


int main() {
	int CASE;
	scanf("%d", &CASE);
	while(CASE--) run();
	return 0;
}
