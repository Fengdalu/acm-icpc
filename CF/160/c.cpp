#include <cstdio>
#include <cstring>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

int q[200000], a[200000];
int m, n;

int cmp(int a, int b)
{ return a > b; }

int main()
{
	scanf("%d", &m); for(int i = 0; i < m; i++) scanf("%d", &q[i]);
	scanf("%d", &n); for(int i = 0; i < n; i++) scanf("%d", &a[i]);	
	sort(q, q + m);
	sort(a, a + n, cmp);
	
	int j = 0;
	long long sum = 0;
	while(j < n)
	{
		int dis = q[0];		
		while(j < n && dis > 0)
		{
			sum += (long long)a[j++];
			dis--;
		}
		j++; j++; 
		if(j == n) break;
	}	
	while(j < n) sum += (long long)a[j++];
	printf("%I64d\n", sum);
	return 0;
}
	