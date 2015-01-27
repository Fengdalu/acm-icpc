#include <iostream>
#include <cstdio>
#include <cstring>
#define N 2000000

using namespace std;

struct point
{
    int x, y;
};

double area(point x1, point x2, point x3)
{
    return (x2.x - x1.x) * (x3.y - x1.y) - (x3.x - x1.x) * (x2.y - x1.y);
}

double cx(point a, point b, point c)
{
    return (a.x + b.x + c.x);
} 
    

double cy(point a, point b, point c)
{
    return (a.y + b.y + c.y);
} 


int T;
int n;
point f[N];

int main()
{
   scanf("%d", &T); 
   for(int ii = 0; ii < T; ii++)
   {
       scanf("%d", &n);
       for(int i = 0; i < n; i++)
            scanf("%d%d", &f[i].x, &f[i].y);
       point a = f[0]; 
       point p = f[1];
       double x = 0, y = 0;
       for(int i = 2; i < n; i++)
       { 
          double t = area(a, p, f[i]);
          x += cx(a, p, f[i]) * t;
          y += t;
          p = f[i];
       }
       printf("%.2f ", x / y / 3.0);
       
       x = 0; y = 0;
       p = f[1];
       for(int i = 2; i < n; i++)
       { 
          double t = area(a, p, f[i]);
          x += cy(a, p, f[i]) * t;
          y += t;
          p = f[i];
       }
       printf("%.2f\n", x / y / 3.0);
   }
   return 0; 
}

