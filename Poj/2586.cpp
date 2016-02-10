#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool vis[13];
int run() {
	long long s, d;
	if(scanf("%lld%lld", &s, &d) == -1) return 1;
	memset(vis, 0, sizeof vis);
	int Q;
	for(Q = 1; Q <= 5; Q++) 
	if(Q * d > (5 - Q) * s) break;

	for(int i = 1; i <= 8; i++) {
		int cc = 0;
		for(int j = i; j < i + 5; j++) 
			if(vis[j]) cc++;
		for(int j = i + 4; j >= i; j--)
			if(!vis[j] && cc < Q) {
				vis[j] = true;
				cc++;
			}
	}
	long long tot = 0;
	for(int i = 1; i <= 12; i++) 
	if(vis[i]) tot -= d;
	else tot += s;

	if(tot >= 0)
	printf("%lld\n", tot);
	else puts("Deficit");
	return 0;
}

int main() {
	while(run() == 0);
	return 0;
}
