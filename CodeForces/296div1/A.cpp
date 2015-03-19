#include <iostream>
#include <cstdio>
#include <set>
#include <cstring>
using namespace std;
#define AA first()
#define BB second()
#define OP begin()
#define ED end()
#define CLR clear()
#define N 200010
#define LL long long

int w, h, n;
set<int>a, b;
set<int>f1, f2;
int q1[N], q2[N];
int f[N];
int x;
char s[10];
LL ans[N];

int main()
{
	ios::sync_with_stdio(false);
	cin >> w >> h >> n;
	a.CLR; b.CLR;
	a.insert(h); a.insert(0);
	b.insert(w); b.insert(0);
	for(int i = 0; i < n; i++)	
	{
		cin >> s >> x;
		if(!strcmp(s, "H")) { a.insert(x); q1[i] = 1; }
		else { b.insert(x); q1[i] = 0; }
		q2[i] = x;	
	}
	f1.CLR; f2.CLR;
		
	int tmp, x;
	for(set<int>::iterator iter = a.OP; iter != a.ED; iter++)
	{
		if(iter == a.OP) tmp = *iter;
		else { x = *iter; f1.insert(x - tmp); tmp = x;}
	}
	
	for(set<int>::iterator iter = b.OP; iter != b.ED; iter++)
	{
		if(iter == b.OP) tmp = *iter;
		else { x = *iter; f2.insert(x - tmp); tmp = x;}
	}

	for(int i = n - 1; i >= 0; i--)	
	{
		int t1 = *(--f1.ED), t2 = *(--f2.ED);
		ans[i] = (LL)t1 * t2; 
		if(q1[i])
		{
			int p1 = *(--a.find(q2[i])), p2 = *(++a.find(q2[i]));
			f1.erase(q2[i] - p1); 
			f1.erase(p2 - q2[i]);
			f1.insert(p2 - p1);
			a.erase(q2[i]);
		}
		else 
		{
			int p1 = *(--b.find(q2[i])), p2 = *(++b.find(q2[i]));
			f2.erase(q2[i] - p1); 
			f2.erase(p2 - q2[i]);
			f2.insert(p2 - p1);
			b.erase(q2[i]);
		}
	}
	for(int i = 0; i < n; i++)
		cout << ans[i] << endl;
	return 0;
}
