#include <iostream>
#include <cstdio>
#include <cstring>
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
		if(c[0] == '#') break;
		for(int i = 0; i < cnt; i++) {
			int l1 = strlen(s[i]), l2 = strlen(c);
			if(l1 == l2)
				
			}
		}
	}
	return 0;
}
