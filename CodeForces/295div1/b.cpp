#include <cstdio>
#include <cstring>
#include <set>
#include <iostream>
#include <algorithm>
#define MAXM 600000
#define MOD 1000000009
#define MAXN 200000

using namespace std;

struct P
{
	int x, y, n;

}pt[MAXN];

bool operator < (const P &a, const P &b)
{
	return a.n < b.n;
}

int ind[MAXN], t[MAXM], nt[MAXM];
int c[MAXN];
int BG[MAXN];
int cnt = 0, n;
int cc = 0;
set<P>s;


int cmp(P a, P b)
{
	if(a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}

void add(int a, int b)
{
	cnt++;
	t[cnt] = b;
	nt[cnt] = ind[a];
	ind[a] = cnt;
}

int find(int l, int r, int c)
{
    while(l < r - 1)
    {
        int mid = (l + r) / 2;
        if(pt[mid].x < c) l = mid;
        else r = mid;
    }
    if(pt[r].x == c) return r;
    else if(pt[l].x == c) return l;
    else return -1;
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d", &pt[i].x, &pt[i].y);
		pt[i].n = i;
	}
	sort(pt, pt + n, cmp);
	cc = 0;
	BG[cc] = 0;
	for(int i = 1; i < n; i++)
	if(pt[i].y != pt[i - 1].y) 
	{
		cc++;
		BG[cc] = i;	
	}
		
	cc++;
	BG[cc] = n;		
	cnt = 0;
	memset(c, 0, sizeof c);
	for(int i = 0; i < n; i++) ind[i] = -1;	
	
	for(int ii = 0; ii < cc - 1; ii++)
		if(pt[BG[ii]].y == pt[BG[ii + 1]].y - 1)
		for(int i = BG[ii]; i < BG[ii + 1]; i++)
		{
			int t;
			t = find(BG[ii + 1], BG[ii + 2] - 1, pt[i].x);
			if(t != -1) { add(pt[t].n, pt[i].n); c[pt[i].n]++; }
			
			t = find(BG[ii + 1], BG[ii + 2] - 1, pt[i].x + 1);
			if(t != -1) { add(pt[t].n, pt[i].n); c[pt[i].n]++; }
			
			t = find(BG[ii + 1], BG[ii + 2] - 1, pt[i].x - 1);
			if(t != -1) { add(pt[t].n, pt[i].n); c[pt[i].n]++; }
		}
		
	s.clear();
	for(int i = 0; i < n; i++)
	if(c[pt[i].n] != 1)
	{
		cout << pt[i].n << endl;
		s.insert(pt[i]);
	}
	cout << "Hehe" << endl;
	long long ans = 0;
	return 0;
	while(!s.empty())
	{
		cout << "Bg" << endl;
		set<P>::iterator p = s.begin();
		//ans = (ans * n % MOD + p->n);
		for(int k = ind[p->n]; k != -1; k = nt[k])
		{
			c[pt[t[k]].n]--;
			if(c[pt[t[k]].n] != 1 && s.find(pt[t[k]]) != s.end()) s.insert(pt[t[k]]);
		}
		s.erase(p);
		
		/*
		p = s.end() - 1;
		//ans = (ans * n % MOD + p->n);
		for(int k = ind[p->n]; k != -1; k = nt[k])
		{
			c[pt[t[k]].n]--;
			if(c[pt[t[k]].n] != 1 && s.find(pt[t[k]]) != s.end()) s.insert(pt[t[k]]);
		}
		s.erase(p);		
		*/
	}
	cout << ans << endl;
	return 0;
} 
