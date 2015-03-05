#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 5000

int f[N][N];
int a[N];
int n;

int main()
{
	scanf("%d", &n);
	if(n == 1) { puts("1"); return 0; }
	if(n == 2) { puts("2"); return 0; } 
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	if(n == 3) { if(a[0] == a[2]) puts("3"); else puts("2"); return 0; }
	memset(f, 0, sizeof f);
	for(int j = 0; j < n; j++)
	{
		int t = -1;
		for(int i = 0; i < j; i++)
		{	
			if(t == -1) f[i][j] = 2;
			else f[i][j] = f[t][i] + 1;
			if(a[i] == a[j]) t = i;  
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		int cnt = 0;
		for(int j = 0; j < n; j++)
		{	
			if(a[i] == a[j]) cnt++;
		}
		ans = max(cnt, ans);
	}
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			ans = max(ans, f[i][j]);
	printf("%d\n", ans);
	return 0;
}
