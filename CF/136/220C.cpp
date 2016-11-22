#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <cmath>
using namespace std;
#define N 100010

struct obj
{
	int c; int v;
}f[N];
int pos[N];

int n; 
int a[N], b[N];
multiset<obj>s1, s2;

bool operator < (const obj &a, const obj &b)
{
	if(a.v == b.v) return a.c < b.c;
	return a.v < b.v;
}

int main()
{
	//freopen("test.in", "r", stdin);
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) pos[a[i]] = i;
	for(int i = 0; i < n; i++) cin >> b[i];
	for(int i = 0; i < n; i++) 
	{ 
		int x = i - pos[b[i]]; 
		f[b[i]].c = b[i]; 
		f[b[i]].v = abs(x);
	}
	for(int i = 0; i < n; i++)
		if(i - pos[b[i]] <= 0) s1.insert(f[b[i]]);
		else s2.insert(f[b[i]]);

	int tmp = 0;
	int inf = n + 1;
	for(int i = 0; i < n; i++)
	{
		/*
		for(set<obj>::iterator iter = s1.begin(); iter != s1.end(); iter++)
		{
			cout << iter->c << " " << iter->v << endl;
		}
		cout << endl; 

		for(set<obj>::iterator iter = s2.begin(); iter != s2.end(); iter++)
		{
			cout << iter->c << " " << iter->v << endl;
		}
		*/
		int x = (!s1.empty()) ? s1.begin()->v + tmp : inf;
		int y = (!s2.empty()) ? s2.begin()->v - tmp : inf;
		tmp++;
		cout << min(x, y) << endl;
		int p = b[i];
		s1.erase(f[p]);
		s2.erase(f[p]);
		f[p].v = tmp + n - pos[p] - 1;
		s2.insert(f[p]);
		if(!s2.empty())
		{
			while(!s2.empty() && (s2.begin()->v) == tmp)
			{
				int p = s2.begin()->c;
				s2.erase(f[p]);
				f[p].v = -tmp;
				s1.insert(f[p]);
			}
		}
		//cout << endl;
	}
}
