#include <iostream>
#include <cstdio>
using namespace std;
int a, b, c;

int main()
{
	ios::sync_with_stdio(false);	
	while(cin >> a >> b >> c)
	{
	while(a--) putchar('9');
	int sum = b * 6 + c * 3;
	if(sum % 9 == 6)
	{
		if(b) b--;
		else if(c) c -= 2;
		else b = c = 0;
	}
	if(sum % 9 == 3)
	{
		if(c) c -= 1;
		else if(b) b -= 2;
		else b = c = 0;
	}
	while(b--) putchar('6');
	while(c--) putchar('3');
	putchar('\n');
	}
	return 0;
}