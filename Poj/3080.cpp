#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[20][100];
char ans[100];
char ans1[100];
int m;

bool check(int p) {
	if(strstr(s[p], ans) != NULL) return 1;
	return 0;
}

int main() {
	int CASE;	
	scanf("%d", &CASE);
	while(CASE--) {
		scanf("%d", &m);
		for(int i = 0; i < m; i++) scanf("%s", s[i]);

		memset(ans1, 0, sizeof ans1);
		for(int i = 0; i < 60; i++) 
			for(int j = i; j < 60; j++) {
				for(int k = i; k <= j; k++) ans[k - i] = s[0][k];
				ans[j - i + 1] = 0;
				bool flag = true;
				for(int k = 1; k < m; k++) {
					flag &= check(k);
					if(!flag) break;
				}
				if(flag) {
					int l1 = strlen(ans);
					int l2 = strlen(ans1);
					if(l1 > l2 || (l1 == l2 && strcmp(ans, ans1) < 0))
						swap(ans, ans1);
				}
			}
		if(strlen(ans1) < 3) puts("no significant commonalities");
		else printf("%s\n", ans1);
	}
	return 0;
}
