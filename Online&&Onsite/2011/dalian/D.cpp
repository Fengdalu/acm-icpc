#include <iostream>
#include <cstdio>
using namespace std;

char line[100000];

int main() {
	while(gets(line)) {
		int len = strlen(line);
		
		int cnt = 0;
		int pre = -1;
		for(int i = 0; i < len; i++) {
			if(i % 16 == 0) {
				printf("%04x:", i);
			}
			if(i % 2 == 0) {
				printf(" ");
			}
			printf("%2x", line[i]);
			cnt++;
			
			if((i + 1) % 16 == 0 || i == len - 1) {
				for(int i = cnt; i < 16; i++) {
					if(i % 2 == 0) printf(" ");
					printf("  ");
				}
				cnt = 0;
				printf(" ");
				for(int j = pre + 1; j <= i; j++) 
					if(isupper(line[j])) printf("%c", tolower(line[j]));
					else printf("%c", toupper(line[j]));
				pre = i;
				puts("");
			}
		}
	}
	return 0;
}
