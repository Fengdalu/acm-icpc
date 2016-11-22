#include <iostream>
#include <cstdio>
#include <queue>

const int maxn = 200010;
long long t[maxn], d[maxn];
long long ans[maxn];
int main() {
	int n, b;
	scanf("%d%d", &n, &b);
	for(int i = 0; i < n; i++) scanf("%I64d%I64d", &t[i], &d[i]);
	std::queue<std::pair<long long, long long> >q;
	int J = 1;
	long long cur = t[0];
	q.push(std::make_pair(0, d[0]));
	while(true) {
		if(q.empty() && J == n) break;
		if(!q.empty()) {
			std::pair<int, int>	p = q.front();
			ans[p.first] = cur + p.second;
			cur = cur + (long long)p.second;
			q.pop();
			while(J < n && t[J] < cur) {
				if(q.size() < b) {
					q.push(std::make_pair(J, d[J]));
					J++;
				}
				else ans[J++] = -1;
			}
		}
		else {
			q.push(std::make_pair(J, d[J]));
			cur = std::max((long long)t[J], cur);
			J++;
		}
	}
	for(int i = 0; i < n; i++) printf("%I64d ", ans[i]);
	return 0;
}
