#include <stdio.h>
#include <string.h>
#include <algorithm>
#define clr(a,b) memset(a,b,sizeof(a))
long long a[60];
long long dp[320];
long long cnt[320];
long long b[60];
long long ans;
long long tot[350];
long long d[35][35];
int n;
int main()
{
	clr(cnt,0);
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
		scanf("%lld",&a[i]);
	std::sort(a + 1, a + 1 + n);
	std::reverse(a + 1, a + 1 + n);
	for(int i = 0; i <= 5; i++)
		b[i] = 1 << i;
	ans = a[1];
	cnt[1] = a[1];
	for(int i = 2; i <= n; i++)
	{
		clr(dp,-1);
		clr(tot,0);
		int maxmask = 1 << i;
		//printf("i = %d\n", i);

		//printf("ans = %lld\n", ans);
		//for(int mask = 0; mask < maxmask; mask++)
		//	printf("cnt[%d] = %lld\n", mask, cnt[mask]);
		dp[0] = 0;
		for(int mask = 1; mask < maxmask; mask++) if(cnt[mask])
		{
			for(int now = 0; now < maxmask; now++) if(dp[now] != -1)
			{
				if((now & mask) == 0 && dp[now | mask] < dp[now] + 1)
				{
					for(int k = 0; k < tot[now]; k++)
						d[now | mask][k] = d[now][k];
					tot[now | mask] = tot[now];
					d[now | mask][tot[now | mask]++] = mask;
					dp[now | mask] = dp[now] + 1;
				}
			}
		}
		//for(int mask = 0; mask < maxmask; mask++)
		//	printf("dp[%d] = %lld\n", mask, dp[mask]);
		long long maxdp = 0;
		int maxst = 0;
		for(int mask = 0; mask < maxmask; mask++)
		{
			if(maxdp < dp[mask])
			{
				maxdp = dp[mask];
				maxst = mask;
			}
		}
		//printf("maxdp = %lld\n", maxdp);
		//printf("maxst = %d\n", maxst);
		long long add = a[i] - maxdp;
		if(add < 0) add = 0;
		//printf("add = %lld\n", add);
		ans += add;
		//if(a[i] - maxdp < 0) puts("hahaha");
		for(int ii = 0; ii < tot[maxst];ii++)
		{
			if(ii >= a[i]) break;
			int st = d[maxst][ii];
			//printf("\t %lld\n", d[maxst][ii]);
			cnt[st]--;
			cnt[b[i] | st]++;
		}
		cnt[b[i]] += add;
	}
	printf("%lld\n", ans);
}
