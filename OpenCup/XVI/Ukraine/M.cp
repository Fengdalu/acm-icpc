#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>

#define cmax(a,b) a = std::max(a,b);
#define clr(a,b) memset(a,b,sizeof (a))
#define FOR(i,x) for(int i = 0, CC__END__CC = (int)(x); i < CC__END__CC; i++)
#define FORR(i,x) for(int i = 1, CC__END__CC = (int)(x); i <= CC__END__CC; i++)
#define REP(i,y,x) for(int i = (int)(y), CC__END__CC = (int)(x); i <= CC__END__CC; i++)

struct node
{
	long long a[8];	
}a[30005];
int b[30005];
int cmp(struct node A, struct node B)
{
	FOR(i,8)
	{
		if(A.a[i] < B.a[i]) return 1;
		if(A.a[i] > B.a[i]) return 0;
	}
	return 1;
}
int equ(int x, int y)
{
	FOR(i,8) if(a[x].a[i] != a[y].a[i]) return 0;
	return 1;
}
int CC_x;
inline void geta(int i)
{
	FOR(j,8)
	{
		scanf("%d",&CC_x);
		a[i].a[j] = CC_x;
	}
}
int n,m;
std::priority_queue<std::pair<long long, std::pair<int, long long > > > Q;
#define MP_3(x,y,z) std::make_pair(x, std::make_pair(y,z))
#define AA first
#define BA second.first
#define BB second.second
long long tmp;
long long getnum(int i, long long n)
{
	long long ret = 0;
	tmp = 1;
	for(int j = 7; j >= 0; j--)
	{
		ret += a[i].a[j] * tmp;
		tmp *= n;
	}
	return ret;
}
int main()
{
	//clr(b,0);
	scanf("%d",&n);
	FOR(i,n) geta(i);
	//std::sort(a, a + n, cmp);
	//for(int i = 1; i < n; i++) if(equ(i, i - 1)) b[i] = 1;
	//FOR(i,n){FOR(j,8) printf("%d ", a[i].a[j]);puts("");}
	scanf("%d",&m);
	while(!Q.empty()) Q.pop();
	FOR(i,n) //if(!b[i])
	{
		Q.push(MP_3(-getnum(i,1),i,1));
	}
	//long long bef = -1;
	int nowi;
	long long nown;
	long long ans;
	int tot = 0;
	while(tot < m)
	{
		ans = -Q.top().AA;
		nowi = Q.top().BA;
		nown = Q.top().BB + 1;
		Q.pop();
		Q.push(MP_3(-getnum(nowi, nown),nowi,nown));
		//std::cout << "ans = " << ans << std::endl;
		//if(ans != bef)
		{
			tot++;
			//bef = ans;
		}
	}
	std::cout << ans << std::endl;
}