#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 5000010;

int tmp[N], f[N];
int tt[10];
int n, k;

int select(int a, int b)
{
	if(a == b) return tmp[a];
	int g = (b - a + 1) / 5 + (((b - a + 1) % 5) != 0);
	for(int i = 0; i < g; i++)
	{
		int l = a + i * 5, r = min(a + (i + 1) * 5 - 1, b);
		for(int j = l; j <= r; j++)
			tt[j - l] = tmp[j];
		sort(tt, tt + (r - l + 1));
		tmp[a + i] = tt[(r - l) / 2];
	}
	return select(a, a + g - 1);
}

int find(int a, int b, int k)
{
	if(a == b) return f[k];
	for(int i = a; i <= b; i++) tmp[i] = f[i];
	int l = a, r = b;
	int x = select(a, b);
	while(l < r)
	{
		while(f[l] > x) l++;
		while(f[r] < x) r--;
		if(l < r)
		{
			swap(f[l], f[r]);
			l++; r--;
		}
	}
	if(k == l) return f[k];
	if(k > l) return find(l + 1, b, k);
	return find(a, l - 1, k);
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> f[i];
	cout << find(0, n - 1, k - 1) << endl;
	return 0;
}
