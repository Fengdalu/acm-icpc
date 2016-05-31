#include <stdio.h>
#include <algorithm>
int n;
int m;
int a[2005][2005];
int b[2005][2005];
long long try1()
{
	long long ret = -1;
	int flag;
	int bin;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			b[i][j] = a[i][j];
	bin = b[0][0] & 1;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			if(b[i][j] == 0)
			{
				if(i - 1 >= 0)
					b[i][j] = b[i - 1][j] + 1;
				if(b[i][j] == 0 && j - 1 >= 0)
					b[i][j] = b[i][j - 1] + 2;
				else
					if(j - 1 >= 0 && b[i][j - 1] + 2 > b[i][j])
						b[i][j] = b[i][j - 1] + 2;
			}
		bin ^= 1;
	}
	flag = 1;
	long long now = 0;
	bin = b[0][0] & 1;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			now += b[i][j];
			if(i - 1 >= 0 && b[i - 1][j] >= b[i][j])
				flag = 0;
			if(j - 1 >= 0 && b[i][j - 1] >= b[i][j])
				flag = 0;
			if((b[i][j] & 1) != bin)
				flag = 0;
		}
		bin ^= 1;
	}
	if(flag) ret = now;
	return ret;
}

long long try2()
{
	long long ret = -1;
	int flag;
	int bin;
	std::swap(n,m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			b[i][j] = a[j][i];
	bin = b[0][0] & 1;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			if(b[i][j] == 0)
			{
				if(i - 1 >= 0)
					b[i][j] = b[i - 1][j] + 1;
				if(b[i][j] == 0 && j - 1 >= 0)
					b[i][j] = b[i][j - 1] + 2;
				else
					if(j - 1 >= 0 && b[i][j - 1] + 2 > b[i][j])
						b[i][j] = b[i][j - 1] + 2;
			}
		bin ^= 1;
	}
	flag = 1;
	long long now = 0;
	bin = b[0][0] & 1;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			now += b[i][j];
			if(i - 1 >= 0 && b[i - 1][j] >= b[i][j])
				flag = 0;
			if(j - 1 >= 0 && b[i][j - 1] >= b[i][j])
				flag = 0;
			if((b[i][j] & 1) != bin)
				flag = 0;
		}
		bin ^= 1;
	}
	if(flag) ret = now;
	std::swap(n,m);
	return ret;
}
void tepan()
{
	if(a[0][0] == 0) a[0][0] = 1;
	for(int i = 0; i < m; i++)
		if(a[0][i] == 0) a[0][i] = a[0][i - 1] + 1;
	for(int i = 1; i < m; i++)
		if(a[0][i] <= a[0][i - 1])
		{
			puts("-1");
			return;
		}
	long long sum = 0;
	for(int i = 0; i < m; i++)
		sum += a[0][i];
	printf("%lld\n", sum);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d",&a[i][j]);
	if(n == 1)
	{
		tepan();
		return 0;
	}
	if(m == 1)
	{
		std::swap(n,m);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				a[i][j] = a[j][i];
		tepan();
		return 0;
	}
	long long ans = -1;
	long long tmp;
	int flag = 0;
	if(a[0][0] == 0)
		flag = 1;
	if(flag)
	{
		a[0][0] = 1;
		tmp = try1(); if(ans == -1) ans = tmp; else if(tmp != -1 && tmp < ans) ans = tmp;
		tmp = try2(); if(ans == -1) ans = tmp; else if(tmp != -1 && tmp < ans) ans = tmp;
		a[0][0] = 2;
		tmp = try1(); if(ans == -1) ans = tmp; else if(tmp != -1 && tmp < ans) ans = tmp;
		tmp = try2(); if(ans == -1) ans = tmp; else if(tmp != -1 && tmp < ans) ans = tmp;
	}
	else
	{
		tmp = try1(); if(ans == -1) ans = tmp; else if(tmp != -1 && tmp < ans) ans = tmp;
		tmp = try2(); if(ans == -1) ans = tmp; else if(tmp != -1 && tmp < ans) ans = tmp;
	}
	printf("%lld\n", ans);
	return 0;
}