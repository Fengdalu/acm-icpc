#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;
#define PB(x) push_back(x)
#define SZ size()
#define BG begin()
#define ED end()
#define N 5000

vector<int>f[N];
vector<int>s;
int a[N];
int n, ans;

int cal(const vector<int> a, const vector<int> b)
{		
	bool flg;
	int pos;
	int i = 0, j = 0;
	if(a[0] < b[0]) { i++; flg = 1; pos = a[0]; } else { j++; flg = 0; pos = b[0]; }
	int ans = 0;
	while(i < a.SZ && j < b.SZ)
	{
		//cout << i << " " << j << " " << pos << endl;
		if(flg)
		{
			while(j < b.SZ && b[j] < pos) j++;
			pos = b[j];
			ans++;
		}
		else
		{
			while(i < a.SZ && a[i] < pos) i++;
			pos = a[i];
			ans++;
		}
		flg ^= 1;
	}
	//cout << ans << endl;
	return max(ans, 2);
}

int main()
{
	//freopen("test.in", "r", stdin);
	scanf("%d", &n);
	if(n == 2) { puts("2"); return 0; }
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; i++)
		s.PB(a[i]);
	sort(s.BG, s.ED);
	int size = unique(s.BG, s.ED) - s.BG;
	for(int i = size; i < s.SZ; i++)
		s.erase(s.BG + i);
	for(int i = 0; i < s.SZ; i++)		
		f[i].clear();
	for(int i = 0; i < n; i++)
		f[lower_bound(s.BG, s.BG + size, a[i]) - s.BG].PB(i);
	for(int i = 0; i < size; i++) ans = max(ans, (int)f[i].SZ);
	for(int i = 0; i < size; i++)	
		for(int j = 0; j < size; j++)
		if(i != j)
		{
			ans = max(ans, cal(f[i], f[j]));
		}
	cout << ans << endl;
}
