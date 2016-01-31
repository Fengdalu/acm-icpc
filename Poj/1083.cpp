#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int Maxn = 210;
const int MaxSize = 410;
int T; 
int n;
pair<int, int>c[Maxn];
int cover[MaxSize];

int main() {
	int T; 
	scanf("%d", &T);
	for(int Case = 1; Case <= T; Case++) {
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d%d", &c[i].first, &c[i].second);
		for(int i = 0; i < n; i++) if(c[i].first > c[i].second) swap(c[i].first, c[i].second);
		for(int i = 0; i < n; i++) if(c[i].first % 2 == 0) c[i].first--;
		for(int i = 0; i < n; i++) if(c[i].second % 2 == 1) c[i].second++;
		memset(cover, 0, sizeof cover);
		for(int i = 0; i < n; i++)
			for(int j = c[i].first; j <= c[i].second; j++) 
				cover[j]++;
		int ans = 1;
		for(int i = 0; i <= 400; i++) ans = max(ans, cover[i]);
		printf("%d\n", 10 * ans);
	}
	return 0;
}
