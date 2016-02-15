#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define X first
#define Y second

typedef pair<int, int> point;
point st, ed;
char s[50][50];
point q[2000];
int c[2000];
bool vis[50][50];

const int V1[4][2] = {
	{0, -1},
	{1, 0},
	{0, 1},
	{-1, 0}
};

const int V2[4][2] = {
	{0, -1},
	{-1, 0},
	{0, 1},
	{1, 0}
};

int walk(point st, const int V[4][2]) {
	int d;
	for(int i = 0; i < 4; i++)	{
		if(s[st.X + V[i][0]][st.Y + V[i][1]] == '.') {
			d = i;
			break;
		}
	}
	int ans = 1;
	while(s[st.X][st.Y] != 'E') {
		d = (d - 1 + 4) % 4;
		while(true)	 {
			if(s[st.X + V[d][0]][st.Y + V[d][1]] == '.' || 
				s[st.X + V[d][0]][st.Y + V[d][1]] == 'E') 
				break;
			d++;
			d %= 4;
		}
		st.X += V[d][0];
		st.Y += V[d][1];
		ans++;
	}
	return ans;
}

int cal(point st) {
	memset(vis, 0, sizeof vis);
	vis[st.X][st.Y] = true;
	int l = 0, r = 0;
	q[0] = st;
	c[0] = 1;
	while(l <= r) {
		point p = q[l];
		int cc = c[l];
		if(s[p.X][p.Y] == 'E') return c[l];
		l++;
		for(int i = 0; i < 4; i++)  {
			int x = p.X + V1[i][0];
			int y = p.Y + V1[i][1];
			if(!vis[x][y] && s[x][y] != '#') {
				vis[x][y] = true;
				++r;
				q[r] = make_pair(x, y);
				c[r] = cc + 1;
			}
		}
	}
}

int n, m;
void run() {
	scanf("%d%d", &m, &n);
	for(int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	for(int i = 0; i <= m + 1; i++) s[0][i] = s[n + 1][i] = '#';
	for(int i = 0; i <= n + 1; i++) s[i][0] = s[i][m + 1] = '#';

	int ans1 = m * n, ans2 = m * n, ans3 = m * n;
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= m; j++)
		if(s[i][j] == 'S') {
			ans1 = min(ans1, cal(make_pair(i, j)));
			ans2 = min(ans2, walk(make_pair(i, j), V1));
			ans3 = min(ans3, walk(make_pair(i, j), V2));
		}
	printf("%d %d %d\n", ans3, ans2, ans1);
}

int main() {
	int CASE;
	scanf("%d", &CASE);
	while(CASE--) run();
}
