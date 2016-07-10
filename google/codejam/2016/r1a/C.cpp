#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>

#define clr(a,b) memset(a,b,sizeof(a));
#define MP(x,y) std::make_pair(x,y)
#define PB(x) push_back(x)
#define all(x) x.begin(),x.end()
#define FOR(x,y) for(int x = 0, __END__ = (int)(y); x < __END__; x++)
#define FORR(x,y) for(int x = 1, __END__ = (int)(y); x <= __END__; x++)
#define REP(x,z,y) for(int x = (int)(z), __END__ = (int)(y); x <= __END__; x++)
#define BB second
#define AA first
int a[15];
int ya[15];
int p[15];
int main()
{
	int _T;
	scanf("%d",&_T);
	FORR(CAS,_T)
	{
		int n;
		scanf("%d",&n);
		int ans = 0;
		for(int i = 1; i <= n; i++)
			a[i] = i;
		for(int i = 1; i <= n; i++)
			scanf("%d",&p[i]);
		bool flag;
		int now;
		do
		{
			FORR(i,n) ya[i] = a[i];
			for(int nn = n; nn > 1; nn--)
			{
				now = 0;
				a[0] = a[nn];
				a[nn + 1] = a[0];
				flag = true;
				for(int i = 1; i <= nn; i++)
				{
					if(p[a[i]] == a[i + 1] || p[a[i]] == a[i - 1])
					{
						now++;
					}
					else
					{
						flag = false;
						break;
					}
				}
				if(flag && now > ans)
					ans = now;
			}
			
			FORR(i,n) a[i] = ya[i];
		}while(std::next_permutation(a + 1, a + n + 1));
		printf("Case #%d: %d\n", CAS, ans);
	}
}