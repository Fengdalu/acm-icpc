#include <stdio.h>
#include <algorithm>

int n;
const int MAXN = 300005;
int a[MAXN];
int k;

int main()
{
	scanf("%d%d",&n,&k);
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	std::sort(a,a + n);
	int upmax = a[0];
	int downmin = 2;
	int flag;
	int *it;
	for(int tmp = upmax; tmp >= 2; tmp--)
	{
		flag = 1;
		it = a;
		for(int j = tmp; j <= a[n - 1] + tmp; j += tmp)
		{
			//if(j == tmp) printf("CHK %d\n",tmp);
			it = std::lower_bound(it, a + n, j);
			if(it == a) continue;
			//printf("\tFIND %d\n", *(it - 1));
			else if(*(it - 1) % tmp > k)
			{
				flag = 0;
				break;
			}
		}
		if(flag)
		{
			printf("%d\n",tmp);
			return 0;
		}
	}
	puts("1");
	return 0;
}
close
