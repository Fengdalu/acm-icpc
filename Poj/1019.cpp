#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
#define N 40000
#define NAME ""
#define VER 1
#define LL long long 

LL BC(int x)
{
	int C = 0;
	while(x)
	{
		x /= 10; C++;
	}
	return C;
}

LL a[N];
LL f[N];
void gen()
{
	LL num = 1;
	a[1] = 1;
	for(int i = 2; i <= N; i++)
		a[i] = a[i - 1] + BC(i);
	f[1] = 1;
	for(int i = 2; i <= N; i++)
		f[i] = f[i - 1] + a[i];
}

LL x;
char s[100];

int main()
{	
	gen();
	int T;
	scanf("%d", &T);
	for(int ii = 0; ii < T; ii++)
	{
	scanf("%I64d", &x);
	int k = 1;
	while(f[k] <= x)
		k++;
	if(f[k - 1] == x) printf("%d\n", (k - 1) % 10); 
	else
	{
		LL pos = f[k - 1];
		int n = 1;
		while(true)
		{
			LL p = BC(n);
			if(pos + p < x) pos += p;
			else 
			{
				sprintf(s, "%d", n);
				printf("%c\n", s[x - pos - 1]);
				break;
			}
			n++;
		}
	}
	}
	return 0;
}
