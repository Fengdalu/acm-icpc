#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

vector<int>f;
const int Maxn = 1001000;
bool vis[Maxn];
char s[1000];
int b;

void init() {
	memset(vis, 0, sizeof vis);
	for(int i = 2; i < Maxn; i++) {
		if(!vis[i]) f.push_back(i);
		for(int j = 0; j < f.size(); j++) {
			if(i * f[j] > Maxn) break;
			vis[i * f[j]] = true;
			if(i % f[j] == 0) break;
		}
	}
}

int run() {
	scanf("%s%d", s, &b);
	if(!strcmp(s, "0") && b == 0) return 0;
	int len = strlen(s);
	for(int i = 0; f[i] < b; i++) {
		int mod = 0;
		long long cnt = 0;
		for(int j = 0; j < len; j++) {
			mod = mod * 10LL;
			if(cnt == 2) {
				mod %= f[i];
				cnt = 0;
			}
			else cnt++;
			mod += s[j] - '0';
		}
		mod %= f[i];
		if(mod == 0) {
			printf("BAD %d\n", f[i]);
			return 1;
		}
	}
	puts("GOOD");
	return 1;
}

int main() {
	init();
	while(run());
}

