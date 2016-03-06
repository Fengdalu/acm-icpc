#include <iostream>
#include <cstdio>
#include <cstring>

const int Maxn = 20;
char c[Maxn];
int x[Maxn], y[Maxn];
char buf[10];
int n, x0, y0;
const int V[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const int V1[8][3][2] = {
	{{1, 0}, {1, 0}, {0, 1}},
	{{1, 0}, {1, 0}, {0, -1}},
	{{-1, 0}, {-1, 0}, {0, 1}},
	{{-1, 0}, {-1, 0}, {0, -1}},
	{{0, 1}, {0, 1}, {1, 0}},
	{{0, 1}, {0, 1}, {-1, 0}},
	{{0, -1}, {0, -1}, {1, 0}},
	{{0, -1}, {0, -1}, {-1, 0}},
};
bool s[20][20];

int main() {
	while(std::cin >> n >> x0 >> y0) {
		if(!n && !x0 && !y0) break;
		memset(s, 0, sizeof s);
		for(int i = 0; i < n; i++) {
			std::cin >> buf >> x[i] >> y[i];
			s[x[i]][y[i]] = true;
			c[i] = buf[0];
		}
		bool deal = false;
		for(int i = 0; i < 4; i++) {
			int xp = x0 + V[i][0];
			int yp = y0 + V[i][1];

			if(xp < 1 || xp > 3 || yp < 4 || yp > 6) continue;
			bool pre = s[xp][yp];
			s[xp][yp] = false;
			bool flag = true;
			for(int j = 0; j < n; j++) {
				if(c[j] == 'G') {
					if(y[j] == yp) {
						bool go = true;
						int l = xp, r = x[j];
						if(l > r) std::swap(l, r);
						for(int j = l + 1; j < r; j++) {
							if(s[j][yp]) go = false;
						}
						if(go) flag = false;
					}
				}
				if(xp == x[j] && yp == y[j]) continue;
			    if(c[j] == 'R') {
					for(int k = 0; k < 4; k++) {
						int a = x[j];
						int b = y[j];
						while(1 <= a && a <= 10 && 1 <= b && b <= 9) {
							a += V[k][0];
							b += V[k][1];
							if(s[a][b]) break;
							if(a == xp && b == yp) flag = false;
						}
					}
				}
				if(c[j] == 'H') {
					for(int k = 0; k < 8; k++) {
						int a = x[j];
						int b = y[j];
						int pass = true;
						for(int p = 0; p < 3; p++) {
							a += V1[k][p][0];
							b += V1[k][p][1];
							if(a < 1 || a > 10 || b < 1 || b > 9) {
								pass = false;
								break;
							}
							if(p == 0 && s[a][b]) pass = false;
						}
						if(pass && a == xp && b == yp) flag = false;
					}
				}
				if(c[j] == 'C') {
					for(int k = 0; k < 4; k++) {
						int a = x[j];
						int b = y[j];
						int c = 0;
						while(1 <= a && a <= 10 && 1 <= b && b <= 9) {
							a += V[k][0];
							b += V[k][1];
							if(s[a][b]) c++;
							if(c > 1) break;
							if(c == 1) {
								if(a == xp && b == yp) flag = false;
							}
						}
					}
				}
			}
			s[xp][yp] = pre;
			deal |= flag;
		}
		if(deal) puts("NO");
		else puts("YES");
	}
	return 0;
}
