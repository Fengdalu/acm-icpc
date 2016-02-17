#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

const int Maxn = 10000;
bool check[Maxn];
int vis[Maxn];
vector<int>prime;

void init() {
	memset(check, 0, sizeof check);
	check[1] = true;
	for(int i = 2; i < Maxn; i++) {
		if(!check[i]) prime.push_back(i);
		for(int j = 0; j < prime.size() && i * prime[j] < Maxn; j++) {
			check[i * prime[j]] = true;
			if(i % prime[j] == 0) break;
		}
	}
}

queue<int>Q;
char buf[10];
void run() {
	int s, t;
	scanf("%d%d", &s, &t);
	memset(vis, -1, sizeof vis);
	vis[s] = 0;
	while(Q.size()) Q.pop();
	Q.push(s);
	while(Q.size()) {
		int x = Q.front();
		if(x == t) break;
		Q.pop();
		for(int i = 0; i < 4; i++) {
			sprintf(buf, "%d", x);
			for(int j = 0; j <= 9; j++) if(!(i == 0 && j == 0)){
				buf[i] = j + '0';
				int p = atoi(buf);
				if(!check[p] && vis[p] == -1) {
					Q.push(p);
					vis[p] = vis[x] + 1;
				}
			}
		}
	}
	if(vis[t] == -1) puts("Impossible");
	else printf("%d\n", vis[t]);
}

int main() {
	init();
	int CASE;
	scanf("%d", &CASE);
	while(CASE--) run();
	return 0;
}
