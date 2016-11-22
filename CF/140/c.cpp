#include <iostream>
#include <cstdio>
using namespace std;
#define LL long long 

LL n, m;

LL pow(LL x, LL c)
{
	LL ans = 1LL;	
	while(c)
	{ 
		if(c & 1) ans = (ans * x) % m;
		x = (x * x) % m;
		c >>= 1LL;
	}
	return ans;
}

LL cal(LL p)
{
	if(p == 0) return 0;
	if(p == 1LL) return 4LL;
	if(p & 1LL) return (pow(4LL, p) + cal(p - 1LL)) % m;
	else return ((pow(4LL, p / 2LL) + 1LL) % m * cal(p / 2LL)) % m;
}

int main()
{
	scanf("%I64d%I64d", &n, &m);
	cout << (pow(3LL, n) + (m - 1)) % m << endl;
	return 0;
}
