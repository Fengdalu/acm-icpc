#include <iostream>
#include <cstdio>
#include <cstring>

char s[10][10];
char a[10][10];
int main() {
	scanf("%s", s[0]);
	scanf("%s", s[1]);
	scanf("%s", a[0]);
	scanf("%s", a[1]);
	bool flag = false;
	for(int i = 0; i < 100; i++) {
		if(!strcmp(s[0], a[0]) && !strcmp(s[1], a[1])) flag = true;
		if(s[0][0] == 'X') std::swap(s[0][0], s[0][1]);
		else if(s[0][1] == 'X') std::swap(s[0][1], s[1][1]);
		else if(s[1][1] == 'X') std::swap(s[1][0], s[1][1]);
		else if(s[1][0] == 'X') std::swap(s[0][0], s[1][0]);
	}
	if(flag) puts("YES");
	else puts("NO");
}
