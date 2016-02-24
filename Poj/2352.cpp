#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int Maxn = 100;
int C[Maxn][Maxn];
int f[Maxn][Maxn];

void init() {
	for(int i = 0; i < Maxn; i++) {
		C[i][0] = 1;
		for(int j = 1; j < i; j++)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		C[i][i] = 1;
	}
	for(int i = 0; i < Maxn; i++) {
		f[i][i] = 1;
		for(int j = i - 1; j >= 0; j--)
			f[i][j] = C[i][j] + f[i][j + 1];
	}

}

int cal(int x) {
	if(x == 0) return 1;
	vector<int>s;
	while(x != 0) {
		s.push_back(x % 2);
		x /= 2;
	}
	reverse(s.begin(), s.end());
	int ans = 0;

	int c = 0;
	for(int i = 1; i < s.size(); i++) {
		if(s[i]) {
			int l = max(0, (int)(s.size() + 1) / 2 - c - 1);
			ans += f[s.size() - i - 1][l];	
		}
		if(!s[i]) c++;
	}
	for(int i = 1; i <= s.size() - 1; i++) {
		ans += f[i - 1][(i + 1) / 2];
	}
	ans++;
	if(c >= (int)(s.size() + 1) / 2) ans++;
	return ans;
}

void run() {
	init();
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%d\n", cal(m) - cal(n - 1));
}

int main() {
	run();
}
