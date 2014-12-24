#include <iostream>
#include <cstdio>

using namespace std;


int main()
{
	int n, x;
	int ans = 0;
	scanf("%d%d", &n, &x);
	int l, r;
	int pre = 1;
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d", &l, &r);
		int t = (l - pre) / x;
		ans += t * x;
		pre = r + 1;
	}
	printf("%d\n", pre - 1 - ans);
	return 0;
} 