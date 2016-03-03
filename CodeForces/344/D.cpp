#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef unsigned long long u64;
const u64 Base = 31;

int n, m;
int cnt1, cnt2;
long long w1[200010], w2[200010];
char c1[200010], c2[200010];


u64 Hash1[200010], Hash2[200010], Hash3[200010], Hash4[200010];
u64 Pow[200010];

void Init() {
    Pow[0] = 1;
    for(int i = 1; i < 200010; i++) Pow[i] = Pow[i - 1] * Base;
}

void Init(u64* Hash, char *c, int len) {
    Hash[len] = 0;
    for(int i = len - 1; i >= 0; i--) Hash[i] = (u64)Hash[i + 1] * Base + (c[i] - 'a' + 1);
}

void Init(u64* Hash, long long *c, int len) {
	const u64 q = 1e9 + 7;
    Hash[len] = 0;
    for(int i = len - 1; i >= 0; i--) Hash[i] = (u64)Hash[i + 1] * q + (u64)(c[i]);
}

u64 Get(u64* Hash, int p, int L) {
    return Hash[p] - Hash[p + L] * Pow[L];
}

int main() {
	Init();	
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		int v; char q;
		scanf("%d-%c", &v, &q);
		if(cnt1 == 0 || c1[cnt1 - 1] != q) {
			w1[cnt1] = v;
			c1[cnt1] = q;
			cnt1++;
		}
		else w1[cnt1 - 1] += v;
	}

	for(int i = 0; i < m; i++) {
		int v; char q;
		scanf("%d-%c", &v, &q);
		if(cnt2 == 0 || c2[cnt2 - 1] != q) {
			w2[cnt2] = v;
			c2[cnt2] = q;
			cnt2++;
		}
		else w2[cnt2 - 1] += v;
	}
	Init(Hash1, c1, cnt1);
	Init(Hash2, c2, cnt2);
	Init(Hash3, w1, cnt1);
	Init(Hash4, w2, cnt2);

	long long ans = 0;
	u64 tot = Get(Hash2, 0, cnt2);
	for(int i = 0; i < 1 + cnt1 - cnt2; i++) 
	if(Get(Hash1, i, cnt2) == tot) {
		if(cnt2 > 2) {
			int q = Get(Hash3, i + 1, cnt2 - 2);
			cout << q << " " << Get(Hash4, 1, cnt2 - 2) << endl;
			if(q != Get(Hash4, 1, cnt2 - 2)) continue;
		}
		int r = i + cnt2;
		if(cnt2 == 1) ans += max(0LL, w1[i] - w2[0] + 1);
		else if(w1[i] >= w2[i] && w1[r - 1] >= w2[cnt2 - 1]) ans++;
	}
	printf("%lld\n", ans);
	return 0;
}
