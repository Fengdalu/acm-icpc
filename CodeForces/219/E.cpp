#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
#define MP(x, y) make_pair(x, y)
#define AA first
#define BB second
typedef long long LL;
typedef pair<LL, LL> PII;

const int Maxn = 150010;

int n, m, d;
LL dp[Maxn], dp1[Maxn];

int main() {
	cin >> m >> n >> d;
	memset(dp, 0, sizeof dp);
	LL cur = 1;
	while(n--) {
		LL a, b, t;
		cin >> a >> b >> t;
		LL w = (t - cur) * d;
		cur = t;

		deque<PII>q;
		int r = 1;
		for(int i = 1; i <= m; i++) {
			while(q.size() && q.front().AA < i - w) q.pop_front();
			while(r <= m && r <= i + w) {
				while(q.size() && q.back().BB <= dp[r]) {
					q.pop_back();
				}
				q.push_back(MP(r, dp[r]));
				r++;
			}
			dp1[i] = q.front().BB + b - abs(a - i);
		}
		swap(dp, dp1);
	}
	LL ans = dp[1];
	for(int i = 1; i <= m; i++) ans = max(ans, dp[i]); 
	cout << ans << endl;
}
