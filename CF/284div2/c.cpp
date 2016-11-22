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

double cal(double a, double b, double c, P s)
{
	if(a == 0) return -c / b - s.y;
	else return (-c - a * s.x) / b - s.y;
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
		double L = cal(a, b, c, s);
		double R = cal(a, b, c, e);
		if(L * R < 0) ans++;
	}
	printf("%d", ans);
}