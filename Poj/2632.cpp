#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

const int direct[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
const int Maxn = 200;
struct bot {
	int x, y;
	int d;
}bots[Maxn];

int f[Maxn][Maxn];
int n, m;
int r, c;
map<char, int>V;

void init() {
	V['N'] = 0;
	V['E'] = 1;
	V['S'] = 2;
	V['W'] = 3;
}

void run() {
	init();
	memset(f, -1, sizeof f);
	scanf("%d%d", &r, &c);
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		int x, y;
		char buf[3];
		scanf("%d%d%s", &x, &y, buf);
		bots[i].x = x;
		bots[i].y = y;
		bots[i].d = V[buf[0]];
		f[x][y] = i + 1;
	}
	bool flag = false;
	for(int i = 0; i < m; i++) {
		int id;
		char buf[3], act;
		int times;
		scanf("%d%s%d", &id, buf, &times);
		if(flag) continue;
		act = buf[0];
		if(act == 'L') {
			bots[id - 1].d = ((bots[id - 1].d - times) % 4 + 4) % 4;
		}
		else if(act == 'R') {
			bots[id - 1].d = (bots[id - 1].d + times) % 4;
		}
		else {
			for(int j = 0; j < times; j++) {
				bot &b = bots[id - 1];
				f[b.x][b.y] = -1;
				b.x += direct[b.d][0];
				b.y += direct[b.d][1];
				if(b.x == 0 || b.x > r || b.y == 0 || b.y > c) {
						printf("Robot %d crashes into the wall\n", id);
						flag = true;
						break;
				}
				if(~f[b.x][b.y]) {
					printf("Robot %d crashes into robot %d\n", id, f[b.x][b.y]);
					flag = true;
					break;
				}
				f[b.x][b.y] = id;
			}
		}
	}
	if(!flag)
	puts("OK");
}

int main() {
	int CASE;
	scanf("%d", &CASE);
	while(CASE--) run();
	return 0;	
}
