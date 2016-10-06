#include <bits/stdc++.h>

const int N = 2e5+10;
const int M = 6e5;

int fa[N];
int cnt;
int op[M], ed[M];
std::pair<int, int> e[N][2];
int ax[M], ay[M];
int ds, dt, s, t;
int flag;
int n, m;

int deg(int x) {
	return 1ll * (e[x][0] != std::make_pair(0, 0)) + 1ll * (e[x][1] != std::make_pair(0, 0));
}

int find(int x) { if(fa[x] == x) return x; return fa[x] = find(fa[x]);}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) scanf("%d%d", op + i, ed + i);
	scanf("%d%d%d%d", &s, &t, &ds, &dt);
	memset(e, 0, sizeof e);
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 0; i < m; i++) {
		int u = op[i], v = ed[i];
		if(u == s && v == t) {flag = true; continue;}
		if(v == s && u == t) {flag = true; continue;}
		if(u == s || u == t || v == s || v == t) continue;
		if(find(u) == find(v)) continue;
		fa[find(u)] = find(v);
		ax[cnt] = u; ay[cnt] = v;
		cnt++;
	}
	for(int i = 0; i < m; i++) {
		int u = op[i], v = ed[i];
		if(u == s && v == t) flag = true;
		if(v == s && u == t) flag = true;
		if(u == s || u == t || v == s || v == t) {
			int p, q;
			if(u == s || u == t) p = u, q = v;
			else p = v, q = u;
			e[find(q)][p == s ? 0 : 1] = std::make_pair(u, v);
		}
	}

	int ss = 0, st = 0;
	for(int i = 1; i <= n; i++) if(find(i) == i && i != s && i != t) {
		if(deg(i) == 0) {
			puts("No");
			exit(0);
		}
		if(deg(i) == 1) {
			if(e[i][0] != std::make_pair(0, 0)) {
				ax[cnt] = e[i][0].first;
				ay[cnt] = e[i][0].second;
				cnt++;
				ss++;
			}
			else {
				ax[cnt] = e[i][1].first;
				ay[cnt] = e[i][1].second;
				cnt++;
				st++;
			}
		}
	}
	if(ss > ds || st > dt) {
		puts("No");
		exit(0);
	}
	int ccc = 0;
	for(int i = 1; i <= n; i++) if(find(i) == i && deg(i) == 2 && i != s && i != t) {
		if(ccc == 0) {
			ccc = 1;
			ax[cnt] = e[i][0].first; ay[cnt] = e[i][0].second; cnt++;
			ax[cnt] = e[i][1].first; ay[cnt] = e[i][1].second; cnt++;
			ss++; st++;
		}
		else {
			if(ds - ss < dt - st) {
				ax[cnt] = e[i][1].first; ay[cnt] = e[i][1].second; cnt++;
				st++;
			}
			else {
				ax[cnt] = e[i][0].first; ay[cnt] = e[i][0].second; cnt++;
				ss++;
			}
		}
	}
	if(ccc == 0) {
		if(!flag) {
			puts("No");
			exit(0);
		}
		ax[cnt] = s;
		ay[cnt] = t;
		cnt++;
		ss++; st++;
	}
	if(ss > ds || st > dt) {
		puts("No");
		exit(0);
	}
	printf("Yes\n");
	for(int i = 0; i < cnt; i++) printf("%d %d\n", ax[i], ay[i]);
	return 0;
}
