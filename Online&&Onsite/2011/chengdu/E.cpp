#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


const int N = 30000;
const int M = 1000000;
int ind[N], id[N];
int t[M], nt[M];
int dfn[N], low[N];
int s[N];
bool vis[N];
int l;
int n;
int cnt, num, idn;
int a[N], b[N], c[N];
int v1[N], v2[N];

void add(int i, int j)
{
    cnt++;
    t[cnt] = j;
    nt[cnt] = ind[i];
    ind[i] = cnt;
}

void tarjan(int x)
{
    num++;
    dfn[x] = low[x] = num;
    s[++l] = x;
    vis[x] = true;
    for(int k = ind[x]; k != -1; k = nt[k])
    {
        if(dfn[t[k]] == 0) tarjan(t[k]);
        if(vis[t[k]]) low[x] = min(low[x], low[t[k]]);
    }
    if(dfn[x] == low[x])
    {
        idn++;
        while(true)
        {
            int tmp = s[l--];
            id[tmp] = idn;
            vis[tmp] = false;
            if(tmp == x) break;
        }
    }
}

bool chk()
{
    memset(vis, 0, sizeof vis);
    num = 0;
    idn = 0;
    l = 0;
    memset(dfn, 0, sizeof dfn);
    memset(low, 0, sizeof low);
    memset(id, 0, sizeof id);
    for(int i = 0; i < 2 * n; i++)
    {
        if(dfn[i] == 0) tarjan(i);
    }
    for(int i = 0; i < 2 * n; i++)
    {
        if(id[i] == id[i ^ 1]) return false;
    }
    return true;
}

int main() {
	int CASE;
	scanf("%d", &CASE);
	for(int T = 1; T <= CASE; T++) {
		int m;
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++) scanf("%d", &v1[i]);
		for(int i = 0; i < n; i++) v1[i]--;
		for(int i = 0; i < n; i++) v2[i] = (v1[i] + 1) % 3;
		for(int i = 0; i < n; i++) if(v1[i] > v2[i]) swap(v1[i], v2[i]);

		cnt = 0;
		memset(ind, -1, sizeof ind);
		for(int i = 0; i < m; i++) {
			int s, t, p;
			scanf("%d%d%d", &s, &t, &p);
			s--; t--;
			if(p) {
				if(v1[s] == v1[t]) {
					add(2 * s, 2 * t + 1);
					add(2 * t, 2 * s + 1);
				}
				if(v1[s] == v2[t]) {
					add(2 * s, 2 * t);
					add(2 * t + 1, 2 * s + 1);
				}
				if(v2[s] == v1[t]) {
					add(2 * s + 1, 2 * t + 1);
					add(2 * t, 2 * s);
				}
				if(v2[s] == v2[t]) {
					add(2 * s + 1, 2 * t);
					add(2 * t + 1, 2 * s);
				}
			}
			else {
				if(v1[s] != v1[t]) {
					add(2 * s, 2 * t + 1);
					add(2 * t, 2 * s + 1);
				}
				if(v1[s] != v2[t]) {
					add(2 * s, 2 * t);
					add(2 * t + 1, 2 * s + 1);
				}
				if(v2[s] != v1[t]) {
					add(2 * s + 1, 2 * t + 1);
					add(2 * t, 2 * s);
				}
				if(v2[s] != v2[t]) {
					add(2 * s + 1, 2 * t);
					add(2 * t + 1, 2 * s);
				}
			} 
		}
		if(chk()) printf("Case #%d: yes\n", T);
		else printf("Case #%d: no\n", T);
	}
	return 0;
}
