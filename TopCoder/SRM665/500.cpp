#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

class LuckyCycle {
public:
	vector <int> getEdge(vector <int>, vector <int>, vector <int>);
};
const int N = 400;

int ind[N];
int t[N], nt[N], c[N];
int f1[N], f2[N];
int cnt;
bool vis[N];
bool m[N][N];

void add1(int a, int b, int cc)
{
	m[a][b] = true;
	t[cnt] = b;
	nt[cnt] = ind[a];
	c[cnt] = cc;
	ind[a] = cnt;
	cnt++;
}

void add(int a, int b, int c)
{
	add1(a, b, c); add1(b, a, c);
}

int rt;
vector<int> dfs(int x, int a, int b)
{
	vector<int>ans; ans.clear();
	if(vis[x]) return ans;
	vis[x] = true;	
	if(a == b + 1 && !m[rt][x]) { ans.push_back(x); ans.push_back(rt); ans.push_back(7); return ans; }
	if(a == b - 1 && !m[rt][x]) { ans.push_back(x); ans.push_back(rt); ans.push_back(4); return ans; }
	
	for(int k = ind[x]; k != -1; k = nt[k])
	if(!vis[t[k]])
	{		
		vector<int>ans = dfs(t[k], a + ((c[k] == 4) ? 1 : 0), b + ((c[k] == 7) ? 1 : 0));
		if(ans.size()) return ans;
	}
	return ans;
}

vector <int> LuckyCycle::getEdge(vector <int> edge1, vector <int> edge2, vector <int> weight) {
	cnt = 0;
	memset(ind, -1, sizeof ind);
	memset(m, 0, sizeof m);
	int n = 0;
	for(int i = 0; i < edge1.size(); i++)
	{
		add(edge1[i], edge2[i], weight[i]);
		n = max(n, edge1[i]);
		n = max(n, edge2[i]);
	}	
	for(int i = 1; i <= n; i++)
	{
		memset(vis, 0, sizeof vis);
		rt = i;
		vector<int> ans = dfs(i, 0, 0);				
		if(ans.size()) return ans;
	}
	
	vector<int>ans; ans.clear();
	return ans;
}


//Powered by [KawigiEdit] 2.0!