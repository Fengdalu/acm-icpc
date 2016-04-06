#include <stdio.h>
#include <stdlib.h>
int l;
const int MAXN = 100005;
long long a[MAXN];
long long cnt[MAXN];
int chk(long long n, long long k, long long p)
{
	if(k == 0LL) return 0;
	if(k > n) return 0;
	long long tmp = n / k;
	long long yu = n % k;
	if(p < tmp) return 0;
	if(p == tmp && yu) return 0;
	//if(p * k < n) return 0;
	return 1;
}
void tryto(int i, long long sumn, long long sumcnt)
{
	//printf("try %d %lld %lld\n", i, sumn, sumcnt);
	if(a[i] <= 2LL) return;
	//sumn -= a[i] - 1;
	sumn += 1LL;
	if(chk(sumn, sumcnt, a[i] - 1LL) == 0) return;
	int tot = i + 1;
	cnt[i]--;
	if(cnt[i] == 0) tot = i;
	int isleft = 0;
	long long left;
	long long maxl = 1;
	long long maxa = a[i] - 1;
	long long cnt1;
	sumn -= sumcnt;
	cnt1 = sumcnt;
	maxl += sumn / (maxa - 1);
	cnt1 -= maxl - 1;
	sumn %= maxa - 1;
	if(sumn)
	{
		isleft = 1;
		left = sumn + 1;
		cnt1 -= 1;
	}
	//printf("tot = %d\n",tot);
	cnt[tot] = maxl;
	a[tot++] = maxa;
	//printf("maxa = %lld\n", maxa);
	if(isleft)
	{
		cnt[tot] = 1;
		a[tot++] = left;
	}
	if(cnt1)
	{
		cnt[tot] = cnt1;
		a[tot++] = 1;
	}
	printf("%d\n",tot);
	for(int j = 0; j < tot; j++)
		printf("%lld %lld\n", cnt[j], a[j]);
	exit(0);
}
int main()
{
    freopen("next-partition-rle.in","r",stdin);
    freopen("next-partition-rle.out","w",stdout);
	scanf("%d",&l);
	for(int i = 0; i < l; i++)
		scanf("%lld%lld",&cnt[i],&a[i]);
	long long sumn = 0;
	long long sumcnt = 0;
	for(int i = l - 1; i >= 0; i--)
	{
		tryto(i,sumn, sumcnt);
		sumcnt += cnt[i];
		sumn += cnt[i] * a[i];
	}
	puts("-1");
}