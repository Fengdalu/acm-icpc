#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char f[200][200];
int s[200][200];

int r, c;
int run() {
	int x, y;
	scanf("%d%d%d", &r, &c, &y);
	if(r == 0 && c == 0 && y == 0) return 1;
	for(int i = 0; i < r; i++) scanf("%s", f[i]);
	x = 0;
	y--;
	int cnt = 0;
	memset(s, -1, sizeof s);
	while(true) {
		s[x][y] = cnt++;
		if(f[x][y] == 'N') x--;
		else if(f[x][y] == 'S') x++;
		else if(f[x][y] == 'E') y++;
		else if(f[x][y] == 'W') y--;
		if(x < 0 || x == r || y < 0 || y == c) {
			printf("%d step(s) to exit\n", cnt);
			return 0;
		}
		if(s[x][y] != -1) {
			printf("%d step(s) before a loop of %d step(s)\n", s[x][y], cnt  - s[x][y]);
			return 0;
		}
	}
}

int main() {
	while(!run());
	return 0;
}
