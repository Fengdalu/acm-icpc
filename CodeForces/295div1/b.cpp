#include <cstdio>
#include <cstring>
#include <set>
#include <iostream>
#include <algorithm>
#define MAXM 600000
#define MAXN 200000

using namespace std;

struct P
{
	int x, y, id;
	int down[3], up[3];
}pt[MAXN];

struct cmp
{
	bool operator() (const int &a, const int &b)
	{
		return pt[a].id - pt[b].id;
	}
};

int BG[MAXN];
int cnt = 0, n;
int cc = 0;
set<int, cmp>s;

bool only(int x)
{
	P &p = pt[x];
	int num = 0;
	for(int i = 0; i < 3; i++) if(p.down[i] != -1) num++;
	if(num == 1) return true;
	return false;
}

bool can(int x)
{
	P &p = pt[x];
	for(int i = 0; i < 3; i++)
		if(only(p.up[i])) return false;
	return true;
}


int cmp(P a, P b)
{
	if(a.y == b.y) return a.x < b.x;
	return a.y > b.y;
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

void link(int up, int down)
{
	P &u = pt[up], &d = pt[down];
	for(int i = 0; i < 3; i++) if(u.down[i] == -1) { u.down[i] = down; break; }
	for(int i = 0; i < 3; i++) if(d.up[i] == -1) { d.up[i] = up; break; }
}

void unlink(int up, int down)
{
	P &d = pt[down], &u = pt[up];
	for(int i = 0; i < 3; i++) if(d.up[i] == up) { d.up[i] = -1; break; }
	for(int i = 0; i < 3; i++) if(d.down[i] == down) { d.down[i] = -1; break; }
}

void del(int x)
{
	P &p = pt[x];
	for(int i = 0; i < 3; i++)
	if(p.down[i] != -1)
	{
		int d = p.down[i];
		unlink(x, d);
		if(can(d)) { s.insert(d); }
	}
}

void gen()
{
	for(int ii = 0; ii < cc; ii++)
	if(pt[BG[ii]].y == pt[BG[ii + 1]].y + 1)		
	{
		int l = BG[ii + 1], r = BG[ii + 2] - 1;
		for(int i = BG[ii]; i < BG[ii + 1]; i++)
		{
			int x, t;
			x = pt[i].x;
			t = find(l, r, x);
			if(t != -1) link(i, t);
			
			x = pt[i].x;
			t = find(l, r, x + 1);
			if(t != -1) link(i, t);
			
			x = pt[i].x;
			t = find(l, r, x - 1);
			if(t != -1) link(i, t);
		}
	}
}

void operator << (ostream& out, const P& p)
{
	out << "id: " << p.id << endl;
	out << "x: " << p.x << ", y: " << p.y << endl;
	out << "To: " << endl;
	for(int i = 0; i < 3; i++) 
	if(p.down[i] != -1) out << p.down[i] << endl;
	out << endl;
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d", &pt[i].x, &pt[i].y);
		for(int j = 0; j < 3; j++) pt[i].up[j] = pt[i].down[j] = -1;
		pt[i].id = i;
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
	gen();
	s.clear();
	//for(int i = 0; i < n; i++) cout << pt[i];
	for(int i = 0; i < n; i++)
		if(can(i)) 
		{
			s.insert(i);
		}
	
	long long ans = 0;
	long long MOD = 1000000009;
	
	
	while(!s.empty())
	{
		int t;
		
		t = *s.begin();
		s.erase(s.begin()); 
		del(t);
		ans = (ans * n + pt[t].id) % MOD;		
	
	
		t = *(--s.end());
		s.erase(--s.end()); 
		del(t);
		ans = (ans * n + pt[t].id) % MOD;				
	}
	printf("%I64d\n", ans);
	
	return 0;
} 
