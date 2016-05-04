#include <stdio.h>
#include <math.h>
int main()
{
	double s2 = sqrt(2.0);
	double d;
	scanf("%lf",&d);
	double ans;
	ans = s2 * d;
	if(d > 0.99999)
	{
		int tmp = (int) d;
		if(ans < tmp + 1)
		{
			ans = tmp + 1;
		}
	} 
	printf("%.12f\n", ans);
}