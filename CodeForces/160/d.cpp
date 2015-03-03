#include <cstdio>
#include <cstring>
#include <set>
#include <iostream>
#include <algorithm>
#define N 100
using namespace std;


int f[N][N];
int vis[N];
int count;
int a[N];
int p, n;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	scanf("%d", &p);
	memset(f, 0, sizeof f);
	for(int i = 1; i <= n; i++)
	{		
		for(int j = 0; j <= a[i]; j++) f[i][j] = f[i - 1][j];
		f[i][a[i]] += 1;
		for(int j = a[i] + 1; j <= p; j++)
		{
			f[i][j] = f[i - 1][j - a[i]] * 2 + f[i - 1][j];
		}
	}

	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= p; j++) cout << f[i][j] << " ";
		putchar('\n'); 
	}
			
	printf("%.4f\n", f[n][p]);
	return 0;
}