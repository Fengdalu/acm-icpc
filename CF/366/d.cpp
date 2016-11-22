#include <bits/stdc++.h>


const int N = 2e5+100;
int p[N];
int fa[N];
std::vector<int> q[N];

int find(int x) {
	if(fa[x] == x) return fa[x];
	return fa[x] = find(fa[x]);
}

int main() {
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", p + i);
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= n; i++) fa[find(p[i])] = find(i);
	for(int i = 1; i <= n; i++) q[find(i)].push_back(i);

	std::vector<int> bros;
	std::vector<int> bb; 
	for(int i = 1; i <= n; i++) if(find(i) == i) {
		int bro = -1;
		for(int j = 0; j < q[i].size(); j++)
			if(p[q[i][j]] == q[i][j]) bro = q[i][j];
		if(bro != -1)
			bros.push_back(bro);
		if(bro == -1) {
			int dh = q[i][0], mm = q[i][0];
			do {
				dh = p[dh];
				mm = p[mm]; mm = p[mm];
			} while(dh != mm);
			bb.push_back(dh);
		}
	}
	int ans = 0;
	if(bros.size()) {
		int RT = bros[0];
		for(int i = 1; i < bros.size(); i++) p[bros[i]] = RT, ans++;
		for(int i = 0; i < bb.size(); i++) p[bb[i]] = RT, ans++;
	}
	else {
		int RT = bb[0];
		ans++;
		p[RT] = RT;
		for(int i = 1; i < bb.size(); i++) p[bb[i]] = RT, ans++;
	}
	printf("%d\n", ans);
	for(int i = 1; i <= n; i++) printf("%d ", p[i]);
	return 0;
}

