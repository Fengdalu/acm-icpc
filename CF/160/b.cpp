#include <cstdio>
#include <cstring>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

int a[200000];
int n, k;

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	long long sum = 0;
	int i;
	
	for(int i = 0; i < n && k; i++)
	{
		if(a[i] >= 0)break;
		else { a[i] = -a[i]; k--; }
	}
	sort(a, a + n);
	for(int i = 1; i < n; i++) sum += a[i];
	if(k & 1) sum += (-1) * a[0]; else sum += a[0];
	printf("%I64d\n", sum);
	return 0;
}
