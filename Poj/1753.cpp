#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct state {
	int mask;
	int num;
	state(int mask, int num): mask(mask), num(num) {}
	state(){}
};
deque<state>Q;
bool vis[1 << 20];

int flip(int x, int y) {
	int mask = 0;
	for(int i = 0; i < 4; i++) {
		int cur = 0;
		for(int j = 0; j < 4; j++) 
			if(abs(x - i) + abs(j - y) <= 1) {
				cur = cur << 1 | 1;
			}
			else cur = cur << 1;
		mask = mask << 4 | cur;
	}
	return mask;
}

int add[5][5];
void init() {
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			add[i][j] = flip(i, j);
}

void disp(int mask) {
	for(int k = 0; k < 16; k++)	{
	if(1 << k & mask) cout << 1; else cout << 0;
		if((k + 1) % 4 == 0) cout << endl;
	}
	cout << endl;
}

int main() {
	init();
		
	char buf[6];
	int ini = 0;
	for(int i = 0; i < 4; i++) {
		scanf("%s", buf);
		int cur = 0;
		for(int j = 0; j < 4; j++) 
		if(buf[j] == 'b') cur = cur << 1 | 1;
		else cur = cur << 1;
		ini = ini << 4 | cur;
	}
	memset(vis, 0, sizeof vis);
	vis[ini] = true;
	Q.push_back(state(ini, 0));
	int m = 0;
	for(int i = 0;i < 16; i++) m = m << 1 | 1;
	while(Q.size()) {
		state S = Q.front(); 
		Q.pop_front();
		if((S.mask & 65535) == 0 || (~S.mask & 65535) == 0) {
			printf("%d\n", S.num);
			return 0;
		}
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++) 
			if(!vis[add[i][j] ^ S.mask]){
				Q.push_back(state(add[i][j] ^ S.mask, S.num + 1));
				vis[add[i][j] ^ S.mask] = true;
			}
	}
	puts("Impossible");
	return 0;
}
