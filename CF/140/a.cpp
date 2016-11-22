#include <iostream>
#include <cstdio>
using namespace std;

struct obj
{
	int x, y;
	obj(){};
	obj(int a, int b) { x = a; y = b; }
	obj operator - (const obj& b)
	{
		return obj(x - b.x, y - b.y);
	}
}a, b, c;

long long operator * (const obj &a, const obj &b)
{
	return (long long)b.y * a.x - (long long)a.y * b.x;
}


int main()
{
	scanf("%d%d", &a.x, &a.y);
	scanf("%d%d", &b.x, &b.y);
	scanf("%d%d", &c.x, &c.y);
	obj x = b - a; 
	obj y = c - b; 
	long long t = x * y;
	if(t == 0) puts("TOWARDS");
	if(t > 0) puts("LEFT");
	if(t < 0) puts("RIGHT" );
	return 0;
}
