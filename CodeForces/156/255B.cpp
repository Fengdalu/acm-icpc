#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
#define N 2000000

char s[N];

int main()
{
	scanf("%s", s);
	int len = strlen(s);
	int a = 0, b = 0;
	for(int i = 0; i < len; i++)
	{
		if(s[i] == 'x') a++;
		else b++;
	}
	bool flg = (a - b > 0);	
	for(int i = 0; i < abs(a - b); i++)
	{
		if(flg) putchar('x'); else putchar('y');
	}
	putchar('\n');
	return 0;
}
