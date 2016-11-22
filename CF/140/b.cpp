#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 200000

long long pos1[N];
long long pos2[N];
int a[N];
int n, m;

int main()
{
	memset(pos1, 0, sizeof pos1);
	memset(pos2, 0, sizeof pos2);

	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i < n; i++)
		if(pos1[a[i]] == 0) pos1[a[i]] = i + 1;
	for(int i = n - 1; i >= 0; i--)
		if(pos2[a[i]] == 0) pos2[a[i]] = n - i;
		
	long long ans1 = 0, ans2 = 0;
	scanf("%d", &m);
	for(int i = 0; i < m; i++)
	{
		int x, y; scanf("%d", &x);
		ans1 += (pos1[x] == 0) ? n : (pos1[x]);
		ans2 += (pos2[x] == 0) ? n : (pos2[x]);
	}
	printf("%I64d %I64d\n", ans1, ans2);
	return 0;
}
