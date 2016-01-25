#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define N 600
#define PB(x) push_back(x)
#define SZ size()

int n;
bool g[N][N];
char s[N];
bool vis[N];
vector<int>Q;

void dfs(int x, int m) {
	if(vis[x]) return;
	vis[x] = true;
	if(!m)	{
		Q.PB(x);		
		for(int i = 1; i <= n; i++) if(g[x][i]) dfs(i, 1);
	}
	else {
		for(int i = 1; i <= n; i++) if(g[x][i]) dfs(i, 0);
		Q.PB(x);
	}
}

int k;

int main() {
	scanf("%d%d", &n, &k);	
	for(int i = 1; i <= n; i++){
		scanf("%s", s);	
		for(int j = 0; j < n; j++) if(s[j] == '1') g[i][j + 1] = 1;
		else g[i][j + 1] = 0;
	}
	dfs(1, 0);
	for(int i = 0; i < Q.SZ; i++) printf("%d ", Q[i]);
	return 0;
}
