#include <iostream>
#include <cstdio>


using namespace std;

struct P
{
	double x, y;
	P(){}
	P(double a, double b) { x = a; y = b; }
	P(P a, P b){ x = b.x - a.x; y = b.y - a.y; }
};

double cha(P a, P b)
{
	return a.x * b.y - a.y * b.x;
}

P s, e, m;
double a, b, c;


int main()
{
	scanf("%lf%lf", &s.x, &s.y); 
	scanf("%lf%lf", &e.x, &e.y);
	int n;
	scanf("%d", &n);
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		scanf("%lf%lf%lf", &a, &b, &c);
		if(b == 0) m = P(0, -c / a);
		else if(a == 0) m = P(-c / b, 0);
		else m = P(0, -c / b);
		P v1(m, s); P v2(m, e); P d(-b, a);
		if(cha(d, v1) * cha(d, v2) < 0) ans++;
	}
	printf("%d", ans);
}