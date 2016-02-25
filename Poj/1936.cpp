#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int Maxn = 200000;
char a[Maxn], b[Maxn];

int main() {
	while(~scanf("%s%s", a, b)) {
		int l1 = strlen(a), l2 = strlen(b);
		int J = 0;
		for(int i = 0; i < l2; i++) {
			if(b[i] == a[J]) J++;
			if(J == l1) break;
		}
		if(J == l1) puts("Yes");
		else puts("No");
	}
	return 0;
}
