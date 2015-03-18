#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

struct obj
{
	int t, l, v;
}a[40];
int cmp(obj a, obj b)
{
	return a.l - a.t < b.l - b.t;
}

int f[2][3000020];
int n, w;

int main()
{
	ios::sync_with_stdio(false);
	while(cin >> n >> w)
	{
		int M = 0;
		for(int i = 0; i < n; i++)
		{
			cin >> a[i].t >> a[i].v >> a[i].l;
		}
		sort(a, a + n, cmp);
		for(int i = 0; i < n; i++)
		{
			M = max(M + a[i].t, a[i].l);
		}
		memset(f, 0, sizeof f);
		int flg = -1;
		int k = 1;
		for(int i = 0; i < n; i++)
		{	
			k ^= 1;
			for(int j = 0; j < max(a[i].l, a[i].t); j++)
				f[k][j] = f[k ^ 1][j];
			for(int j = max(a[i].t, a[i].l); j <= M; j++)
			{
				f[k][j] = max(f[k ^ 1][j], f[k ^ 1][j - a[i].t] + a[i].v);
			}
			if(flg != -1) break;
		}
		for(int i = 0; i <= M; i++)
			if(f[k][i] >= w) {flg = i; break;}
		(flg != -1) ? cout << flg : cout << "zhx is naive!";
		cout << endl;
	}
	return 0;
}
