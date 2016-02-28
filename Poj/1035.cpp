#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

char s[10010][100];
char c[100];
int cnt;

int main() {
	cnt = 0;
	while(true) {
		scanf("%s", s[cnt]);
		if(s[0] == '#') break;
		else cnt++;
	}
	while(true) {
		scanf("%s", c);
		if(s[0] == '#') break;
		queue<int>ans;
	}
	return 0;
}
