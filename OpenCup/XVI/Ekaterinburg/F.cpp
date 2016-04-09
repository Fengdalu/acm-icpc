#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <bitset>
#include <deque>
#include <set>
#include <vector>
using namespace std;

const int maxn = 500;
const int maxm = 1000000;

int ind[maxn];
int to[maxm], nt[maxm];
int dfn[maxn], low[maxn];
int color[maxn];
int vis[maxn];
int vis1[maxn];
int pre[maxn];
int num;
int ncnt;
stack<int>s;
stack<pair<int, int> >ans, e;
vector<int>g[maxn];
int cnt;
int n, m;

void add(int a, int b) {
    to[cnt] = b;
    nt[cnt] = ind[a];
    ind[a] = cnt++;
}

void tarjan(int x) {
    if(dfn[x]) return;
    low[x] = dfn[x] = ++num;
    vis[x] = true;
    s.push(x);
    for(int k = ind[x]; k != -1; k = nt[k]) {
        tarjan(to[k]);
        if(vis[to[k]]) low[x] = min(low[x], low[to[k]]);
    }
    if(dfn[x] == low[x]) {
		deque<int>q1;	
        while(true) {
            int p = s.top();
			q1.push_back(p);
            s.pop();
            color[p] = ncnt;
            vis[p] = false;
            if(p == x) { 
				break;
			}
        }
        ncnt++;
		if(q1.size() - 1) {
			ans.push(make_pair(q1.back(), q1.front()));
			while(q1.size() - 1) {
				int x = q1.front();
				q1.pop_front();
				ans.push(make_pair(x, q1.front()));
			}
		}
    }
}

bool dfs(int x, const int& target) {
	if(x == target) return true;
	for(int i = 0; i < g[x].size(); i++)
		if(dfs(g[x][i], target)) return true;
	return false;
}

int main() {
    scanf("%d%d", &n, &m);
    memset(ind, -1, sizeof ind);
	cnt = 0;
	for(int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		e.push(make_pair(x, y));
		add(x, y);
	}
	num = 0;
	memset(dfn, 0, sizeof dfn);
	for(int i = 1; i <= n; i++) tarjan(i);

	while(e.size()) {
		pair<int, int> ab = e.top();
		e.pop();
		int a = ab.first, b = ab.second;
		if(color[a] == color[b]) continue;
		memset(vis, 0, sizeof vis);
		if(!dfs(color[a], color[b]))  {
			g[color[a]].push_back(color[b]);
			ans.push(make_pair(a, b));
		}
	}
	printf("%d %d\n", n, ans.size());
	while(ans.size()) {
		int a = ans.top().first, b = ans.top().second;
		printf("%d %d\n", a, b);
		ans.pop();
	}
    return 0;
}
