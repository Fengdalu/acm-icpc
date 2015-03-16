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
int t1[N], t2[N];
set<obj>s1, s2;

bool operator < (const obj &a, const obj &b)
{
	return a.c < b.c;
}

int main()
{
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
	t1[0] = -1;
	for(int i = 0; i < n; i++) t1[i + 1] = b[i];
	s1.clear(); s2.clear();
	for(int i = 0; i < n; i++)
		if(i - pos[b[i]] <= 0) s1.insert(f[b[i]]);
		else s2.insert(f[b[i]]);
	for(int i = 0; i < n; i++) t2[i] = -1;
	for(int i = 0; i < n; i++)
		if(i - pos[b[i]] <= 0) t2[i + n - pos[b[i]]] = b[i];
		else t2[i - pos[b[i]]] = b[i];
	/*
	for(int i = 0; i < n; i++) cout << t1[i] << " ";
	cout << endl;
	for(int i = 0; i < n; i++) cout << t2[i] << " ";
	cout << endl;
	*/
	for(int i = 0; i < n; i++)	
	{
		if()
	}
	return 0;
}

