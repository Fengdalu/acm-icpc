#include <bits/stdc++.h>

#define mp std::make_pair
#define AA first
#define BB second
typedef long long ll;
typedef ll ft;
typedef std::pair<ft, ft> cp;
const int N = 1e3+100;
const int K = 10;
ft gcd(ft a, ft b) {
	if(b == 0) return a;
	return gcd(b, a % b);
}
struct point {
	ft x, y;
	void read() {  scanf("%lld%lld", &this->x, &this->y); }
	cp getk(point t) {
		cp g = mp(t.y - this->y, t.x - this->x);
		ft d = gcd(g.AA, g.BB);
		if(d) g.AA /= d; g.BB /= d;
		return g;
	}

	ft dis(point t) {
		return std::abs(t.y - this->y) + std::abs(t.x - this->x);
	}
} pt[N], a[K];
std::map<cp, std::vector<int> > f[K];
bool vis[N];
bool f[N];
point O;

int cmp(int a, int b) {
	return O.dis(pt[a]) < O.dis(pt[b]);
}

int main() {
	int n, k;
	scanf("%d%d", &k, &n);
	for(int i = 0; i < k; i++) a[i].read();
	for(int i = 0; i < n; i++) pt[i].read();
	for(int i = 0; i < k; i++) {
		for(int j = 0; j < n; j++)
			f[i][a[i].getk(pt[j])].push_back(j);
	}
	for(int i = 0; i < k; i++) {
		O = a[i];
		for(auto &tmp : f[i]) {
			std::sort(tmp.BB.begin(), tmp.BB.end(), cmp);
		}
	}
	std::vector<int> index(k);
	for(int i = 0; i < k; i++) index[i] = i;
	do {
		for(int i = 0; i < n; i++) if(!f[i]) {
			std::queue<int> kill;
		}
	} while(std::next_permutation(index.begin(), index.end()));
}
