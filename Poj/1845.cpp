#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
using namespace std;
typedef long long LL;
#define CLR clear()
#define MP(a, b) make_pair(a, b)
#define OP begin()
#define ED end()
#define AA first
#define BB second

map<LL, LL>f;
const LL MOD = 9901;

LL a, b;

LL pow(LL a, LL b)
{
	LL ans = 1;
	while(b)
	{
		if(b & 1) ans = (ans * a) % MOD;
		a = (a * a) % MOD; b >>= 1; 
	}
	return ans;
}

LL cal(LL a, LL p)
{
	if(p == 0) return 0;
	if(p & 1)  return (pow(a, p) + cal(a, p - 1)) % MOD;
	return ((1 + pow(a, p / 2)) % MOD)  * cal(a, p / 2) % MOD;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> a >> b;
	f.CLR;
	for(LL i = 2; i * i < a; i++)
	if(a % i == 0)
	{
		while(a % i == 0) { f[i]++; a /= i;}
	}
	if(a != 1) f[a]++;
	LL ans = 1LL;
	for(map<LL, LL>::iterator iter = f.OP; iter != f.ED; iter++)
	{
		iter->BB = iter->BB * b;
		ans = ans * (cal(iter->AA, iter->BB) + 1) % MOD;
	}
	cout << ans << endl;
	return 0;
}

