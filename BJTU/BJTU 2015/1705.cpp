#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int T;
	int a, b, c, d, e, f, g;
	scanf("%d", &T);
	for(int ii = 0; ii < T; ii++)
	{
		scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
		int t = b - a;
		int p = max(c, d);
		p = max(p, e);
		p = max(p, f);
		int ans = t / p;
		if(t % p != 0) ans++;
		printf("Case #%d: %d\n", ii + 1, ans);
	}
	return 0;
}
