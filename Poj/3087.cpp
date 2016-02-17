#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
char s1[1050], s2[1050], s[3000];
char b[3000];

void run(int CASE) {
	scanf("%d", &n);
	scanf("%s%s%s", s1, s2, s);
	memset(b, 0, sizeof b);
	for(int i = 0; i < 100; i++) {
		for(int i = 0; i < 2 * n; i++)	
		if(i & 1) b[i] = s1[i / 2];
		else b[i] = s2[i / 2];
		if(!strcmp(b, s)) {
			printf("%d %d\n", CASE, i + 1);
			return ;
		}
		for(int i = 0; i < 2 * n; i++)
		if(i < n) s1[i] = b[i];
		else s2[i - n] = b[i];
	}
	printf("%d %d\n", CASE, -1);
	return ;
}

int main() {
	int CASE;
	scanf("%d", &CASE);
	for(int i = 1; i <= CASE; i++) run(i);
	return 0;
}
