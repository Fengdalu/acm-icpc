#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

char *s = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int main()
{
	freopen("building.in", "r", stdin);
	freopen("building.out", "w", stdout);

	int n;
	cin >> n;
	printf("%d %d %d\n", n, n, n);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			putchar(s[j]);
		putchar('\n');
		for(int j = 1; j < n; j++)
		{
			for(int k = 0; k < n; k++)
				putchar(s[i]);
			putchar('\n');
		}
		putchar('\n');
	}
	fclose(stdout);
	return 0;
}