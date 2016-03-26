#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define SZ size()
#define OP begin()
#define ED end()
#define BG begin()
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
#define SQ(x) ((x)*(x))
#define NAME ""

#define Maxn 101111
#define Maxm 201111

set<PII> S;
set<PII> :: iterator IT, JT;
vector<int> a, b;
int deg[Maxn], p[Maxn];
queue<int> que;
int belong[Maxn];
vector<PII> g;
int used[Maxn];
int fa[Maxn];
int n, m;
struct node {
	int u, v, next;
}e[Maxm], e1[Maxm], e2[Maxm];
int tot, tot1, tot2, last[Maxn], last1[Maxn], last2[Maxn];

void adde(int u, int v) {
	e[tot].u = u; e[tot].v = v; e[tot].next = last[u]; last[u] = tot++;
	deg[v]++;
}
void adde1(int u, int v) {
	e1[tot1].u = u; e1[tot1].v = v; e1[tot1].next = last1[u]; last1[u] = tot1++;
}

void adde2(int u, int v) {
	e2[tot2].u = u; e2[tot2].v = v; e2[tot2].next = last2[u]; last2[u] = tot2++;
}
int getfa(int x) {
	if(fa[x] == x) return x;
	else return (fa[x] = getfa(fa[x]));
}

int main() {
	int i,j,n,m;
	//freopen(NAME".in", "r", stdin);
	//freopen(NAME".out", "w", stdout);
	int k, l, u, v, w;
	while(scanf("%d", &n) != EOF) {
		a.clear();
		for(i = 0; i < n; ++i) {
			scanf("%d", &w);
			a.PB(w);
		}
		scanf("%d", &m);
		tot1 = 0;
		for(i = 0; i <= n; ++i) last1[i] = -1;
		for(i = 0; i < m; ++i) {
			scanf("%d%d", &u, &v);
			--u; --v;
			adde1(u, v);
			adde1(v, u);
		}
		for(i = 0; i < n; ++i) fa[i] = i;
		for(i = 0; i < n; ++i) {
			g.clear();
			g.PB(MP(a[i], i));
			for(j = last1[i]; j != -1; j = e1[j].next) {
				v = e1[j].v; u = e1[j].u;
				g.PB(MP(a[v], v));
			}
			sort(g.BG, g.ED);
			for(j = 0; j < g.SZ; ++j) {
				for(k = j; k < g.SZ && g[j].AA == g[k].AA; ++k) {
					u = g[j].BB; v = g[k].BB;
					u = getfa(u);
					v = getfa(v);
					if(u != v) {
						if(u < v) fa[v] = u;
						else fa[u] = v;
					}
				}
			}
		}
		tot2 = tot = 0;
		for(i = 0; i < n; ++i) last2[i] = last[i] = -1;
		for(i = 0; i < n; ++i) {
			S.clear();
			u = getfa(i);
			S.insert(MP(a[u], u));
			for(j = last1[i]; j != -1; j = e1[j].next) {
				v = e1[j].v;
				u = getfa(v);
				S.insert(MP(a[u], u));
			}
			JT = S.BG;
			++JT;
			for(IT = S.BG; IT != S.ED; ++IT, ++JT) {
				if(JT == S.ED) break;
				adde((IT->second), (JT->second));
				adde2((JT->second), (IT->second));
			}
		}
		while(!que.empty()) que.pop();
		for(i = 0; i < n; ++i) {
			if(getfa(i) == i) {
				if(deg[i] == 0) {
					que.push(i);
					p[i] = 1;
				}
			}
		}
		while(!que.empty()) {
			u = que.front(); que.pop();
			w = 0;
			for(j = last2[u]; j != -1; j = e2[j].next) {
				v = e2[j].v;
				cmax(w, p[v]);
			}
			p[u] = w + 1;
			for(j = last[u]; j != -1; j = e[j].next) {
				v = e[j].v;
				deg[v]--;
				if(deg[v] == 0) {
					que.push(v);
				}
			}
		}
		LL sum = 0;
		for(i = 0; i < n; ++i) {
			sum += p[getfa(i)];
		}
		cout << sum << endl;

	}
	return 0;
}
