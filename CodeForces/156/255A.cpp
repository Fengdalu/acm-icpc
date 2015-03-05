#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[3];

int main()
{
	int n;
	memset(a, 0, sizeof a);
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		int x; scanf("%d", &x);
		a[i % 3] += x;
	}
	int m = 0;	
	for(int i = 0; i < 3; i++)
		if(a[i] > a[m]) m = i; 
	if(m == 0) puts("chest");
	else if(m == 1) puts("biceps");
	else puts("back");
	return 0;
}
