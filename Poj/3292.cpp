#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 1000002;
bool check[Maxn];
int num[Maxn];
int cnt;
int ans[Maxn];

int main() {
	cnt = 0;
	for(int i = 5; i < Maxn; i += 4) {
		if(!check[i]) num[cnt++] = i;
		for(int j = 0; j < cnt && num[j] * i < Maxn; j++) {
			check[i * num[j]] = true;
		}
	}

	int tot = 0;
	for(int i = 0; i < cnt; i++)
		for(int j = i; j < cnt && (long long)num[j] * num[i] < Maxn; j++) {
			ans[tot++] = num[i] * num[j];
		}
	sort(ans, ans + tot);
	tot = unique(ans, ans + tot) - ans;
	int h;
	while(true) {
		scanf("%d", &h);
		if(!h) break;
		printf("%d %d\n", h, upper_bound(ans, ans + tot, h) - ans);
	}
	return 0;
}
