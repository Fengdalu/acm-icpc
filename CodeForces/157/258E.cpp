#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define LL long long
#define N 200000
#define M 200000
#define PB(x) push_back(x)
#define SZ size()


struct obj
{
	int a, b;
	int l, r;
	int s, add;
}T[N];

vector<int>IND[N];
int n, m;
int ind[N], t[M], nt[M];
int st[N], ed[N];
int ans[N];
int cnt, cnt1;
int time;

void add(int a, int b)
{
	cnt++;
	t[cnt] = b;
	nt[cnt] = ind[a];
	ind[a] = cnt;
}

void BD(int x, int xx)
{		
	time++;
	st[x] = time;
	for(int i = 0; i < IND[x].SZ; i++)
	if(xx != IND[x][i])
	{
		add(x, IND[x][i]);
		BD(IND[x][i], x);
	}
	ed[x] = time;
}

int MT(int a, int b)
{
	int rt = ++cnt1;
	T[rt].a = a; T[rt].b = b;
	T[rt].s = T[rt].add = 0;
	T[rt].l = T[rt].r = 0;
	if(a < b)
	{
		int m = (a + b) >> 1;
		T[rt].l = MT(a, m);
		T[rt].r = MT(m + 1, b);
	}
	return rt;
} 

void update(int rt)
{
	if(T[rt].add) { T[rt].s = (T[rt].b - T[rt].a + 1); return;} 
	T[rt].s = 0;
	int l = T[rt].l, r = T[rt].r;
	if(l && r) T[rt].s = T[l].s + T[r].s;
}

void draw(int rt, int c)
{	
	T[rt].add += c;
	update(rt);
}


void inc(int rt, int a, int b, int c)
{	
	if(a <= T[rt].a && T[rt].b <= b) draw(rt, c);
	else 
	{
		int m = (T[rt].a + T[rt].b) >> 1;
		if(a <= m) inc(T[rt].l, a, b, c);
		if(b > m) inc(T[rt].r, a, b, c);
		update(rt);
	}
}

void dfs(int x)
{			
	for(int i = 0; i < IND[x].SZ; i++)
	{
		inc(1, st[x], ed[x], 1);
		inc(1, st[IND[x][i]], ed[IND[x][i]], 1);
	}
	ans[x] = T[1].s;
	for(int k = ind[x]; k != -1; k = nt[k])
	{
		dfs(t[k]);
	}
	for(int i = 0; i < IND[x].SZ; i++)
	{
		inc(1, st[x], ed[x], -1);
		inc(1, st[IND[x][i]], ed[IND[x][i]], -1);
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) IND[i].clear();
	for(int i = 1; i < n; i++) 
	{
		int x, y;
		scanf("%d%d", &x, &y);
		IND[y].PB(x); IND[x].PB(y);
	}
	for(int i = 1; i <= n; i++) ind[i] = -1;

	time = 0; cnt = 0;
	BD(1, -1);
	cnt1 = 0;
	int rt = MT(1, n);
	for(int i = 1; i <= n; i++) IND[i].clear();
	for(int i = 1; i <= m; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		IND[x].PB(y); IND[y].PB(x);
	}
	memset(ans, 0, sizeof ans);
	dfs(1);
	for(int i = 1; i <= n; i++) printf("%d ", ans[i] - (ans[i] != 0));
	putchar('\n');
	return 0;
}
