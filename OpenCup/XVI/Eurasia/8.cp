#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define clr(a,b) memset(a,b,sizeof a)
const int MAXN = 50004;
int n;
int f[MAXN];
int g[MAXN];
std::vector<std::pair<int, int> > v;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int x,y;
	v.clear();
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d",&x,&y);
		v.push_back(std::make_pair(x,y));
	}
	sort(v.begin(), v.end());
	clr(f,-1);
	clr(g,-1);
	f[0] = g[0] = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = m - v[i].second; j >= 0; j--) if(g[j] != -1)
			g[j + v[i].second] = std::max(g[j], g[j + v[i].second]);
		for(int j = m - v[i].second; j >= 0; j--) if(f[j] != -1)
			g[j + v[i].second] = std::max(f[j] + 1, g[j + v[i].second]);
		if(i == n - 1 || (i + 1 < n && v[i].first != v[i + 1].first))
		{
			for(int j = 0; j <= m; j++)
				f[j] = g[j];
		}
	}
	if(~f[m]) printf("%d\n", f[m]);
	else printf("Impossible\n");
	return 0;
}