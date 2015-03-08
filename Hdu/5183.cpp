#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>
#include <cstdio>
using namespace std;
#define AA first
#define BB second
typedef long long LL;
typedef pair<int, int> PII;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define PB(x) push_back(x)
#define SZ size()
#define MP(a, b) make_pair(a, b)
#define OP begin()
#define ED end()
#define CLR clear()
#define INS(x) insert(x)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define MEM(a) memset(a, 0, sizeof a)
#define N 2000000
#define MOD 1000007

LL sum[N];
LL a[N];
LL n, k;
LL ind[MOD], nt[N], v[N];
int cnt;
LL T;

void gn(LL &x){
    char c;
    LL sgn=1;
    while(((c=getchar())<'0'||c>'9') && c!='-');
    if(c=='-')sgn=-1,x=0;else x=c-'0';
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
    x*=sgn;
}

bool find(LL x)
{
	LL p = abs(x) % MOD;
	for(int k = ind[p]; p != 0; p = nt[p]) if(v[k] == x) return true;
	return false;
}

void add(LL x)
{
	cnt++;
	LL p = abs(x) % MOD;
	v[cnt] = x;
	nt[cnt] = ind[p];
	ind[p] = cnt;
}


int main()
{
	gn(T);
	for(int ii = 0; ii < T; ii++)
	{
		bool flg = false;
		cnt = 0;		
		MEM(ind);
		gn(n); gn(k);
		printf("Case #%d: ", ii + 1);
		for(int i = 0; i < n; i++) gn(a[i]);

		a[n] = 0;
		for(int i = n - 1; i > -1; i--)
		if(i & 1) sum[i] = sum[i + 1] - a[i];
		else sum[i] = sum[i + 1] + a[i];

		for(int i = n - 1; i > -1; i--)			
		{
			if(sum[i] == k) { flg = true; break; }
			LL t;
			if(i & 1) t = sum[i] + k;
			else t = sum[i] - k;
			if(find(t)) {flg = true; break;}
			add(sum[i]);
		}
		if(flg) puts("Yes."); else puts("No.");
	}
	return 0;
}
