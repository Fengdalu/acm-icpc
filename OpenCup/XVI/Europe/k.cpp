#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#define clr(a,b) memset(a,b,sizeof(a));
#define MP(x,y) std::make_pair(x,y)
#define PB(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FOR(x,y) for(int x = 0, __END__ = (int)(y); x < __END__; x++)
#define FORR(x,y) for(int x = 1, __END__ = (int)(y); x <= __END__; x++)
#define REP(x,z,y) for(int x = (int)(z), __END__ = (int)(y); x <= __END__; x++)
#define BB second
#define AA first
const int MAXN = 200005;
int a[MAXN];
int d[MAXN];
int del[MAXN];
int ans[MAXN];
std::vector<int> v;
void gao(int x)
{
	v.push_back(x);
	d[x] = -1;
	int t = a[x];
	if(del[a[x]]) return;
	del[a[x]] = 1;
	d[a[t]]--;
	if(d[a[t]] == 0)
		gao(a[t]);
}
int main()
{
	clr(del,0);
	v.clear();
	int n;
	scanf("%d",&n);
	FORR(i,n) ans[i] = i;
	FORR(i,2 * n) scanf("%d",&a[i]);
	clr(d,0);
	FORR(i,n) d[a[i]]++;
	REP(i,n + 1, n * 2)
	{
		if(d[i] == 0)
			gao(i);
	}
	FORR(i,n) if(!del[i]) v.push_back(i);
	FOR(i,v.size())
	{
		if(i) printf(" ");
		printf("%d", v[i]);
	}
}