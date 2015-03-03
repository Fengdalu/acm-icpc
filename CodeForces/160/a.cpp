#include <cstdio>
#include <cstring>
#include <set>
#include <iostream>
#include <algorithm>
#define MAXM 600000
#define MAXN 200000


char s[1000];
int n, k;

int main()
{
	scanf("%d%d", &n, &k);
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		scanf("%s", s);
		int len = strlen(s);
		int cc = 0;
		for(int j = 0; j < len; j++)			
			if(s[j] == '4' || s[j] == '7') cc++;			
		if(cc <= k) ans++;
	}
	printf("%d\n", ans);
	return 0;
} 