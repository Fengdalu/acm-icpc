#include <stdio.h>
int sum[100005];
int main()
{
	int n,x;
	int l,r,ql,qr;
	scanf("%d%d%d%d%d",&n,&l,&r,&ql,&qr);
	sum[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&x);
		sum[i] = sum[i - 1] + x;
	}
	int ans;
	for(int i = 0; i <= n; i++)
	{
		int tmp = 0;
		if(i > n - i)
			tmp += ql * (i - n + i - 1);
		if(n - i > i)
			tmp += qr * (n - i - i - 1);
		tmp += sum[i] * l;
		tmp += (sum[n] - sum[i]) * r;
		if(!i)
			ans = tmp;
		if(tmp < ans)
			ans = tmp;
	}
	printf("%d\n",ans);
}
