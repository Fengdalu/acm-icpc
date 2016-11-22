#include <bits/stdc++.h>

const int N = 50010;
int n;
int a[N];

bool check(int x, int flag) {
	std::set<int> s;
	int pos = std::upper_bound(a, a + n, x) - a;
	for(int i = 0; i < pos; i++) s.insert(a[i]);
	for(int i = pos; i < n; i++) {
		int t = a[i];
		while(t > x) {
			t >>= 1;
		}
		while(s.find(t) != s.end() && t != 1) {
			t >>= 1;
		}
		if(s.find(t) != s.end()) return false;
		s.insert(t);
	}
	if(flag) {
		for(std::set<int>::iterator it = s.begin(); it != s.end(); it++)
			printf("%d ", *it);
	}
	return true;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", a + i);
	std::sort(a, a + n);
	int l = 1, r = a[n - 1];
	while(l < r) {
		int mid = (l + r) >> 1;
		if(check(mid, 0)) r = mid;
		else l = mid + 1;
	}
	check(l, 1);
	return 0;
}
