#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 1e4;
bool a[maxn];
vector<int>q;
void init() {
	for(int i = 2; i < maxn; i++) {
		if(!a[i]) q.push_back(i);
		for(int j = 0; j < q.size() && q[j] * i < maxn; j++) {
			a[q[j] * i] = true;
			if(i % q[j] == 0) break;
		}
	}
}

long long de(long long x, long long base) {
	long long tot = 0;
	long long r = 1;
	while(x) {
		tot += r * (long long)(x & 1);
		r *= base;
		x >>= 1;
	}
	return tot;
}

int main() {
	init();
	for(int i = 0, cnt = 0; cnt < 500 && i < (1 << 14); i++) {
		int c = 1 << 15 | i << 1 | 1;
		vector<int>tmp;
		for(int j = 2; j < 11; j++) {
			long long x = de(c, j);
			for(int k = 0; k < q.size(); k++) 
			if(x % (long long)q[k] == 0) {
				tmp.push_back(q[k]);
				break;
			}
		}
		if(tmp.size() == 9) {
			cnt++;
			for(int j = 15; j >= 0; j--)
			if(1 << j & c) printf("1");
			else printf("0");
			for(int j = 15; j >= 0; j--)
			if(1 << j & c) printf("1");
			else printf("0");

			for(int j = 0; j < tmp.size(); j++) printf(" %d", tmp[j]);
			puts("");
		}
	}
	return 0;
}
