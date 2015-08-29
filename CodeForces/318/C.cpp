#include <iostream>
#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
#define N 100010

int a[N];
int n;

int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}

bool chk(int x, int c)
{
    x /= c;
    while(x % 2 == 0) x /= 2;
    while(x % 3 == 0) x /= 3;
    return x == 1;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    int cc = a[0];
    for(int i = 1; i < n; i++) cc = gcd(cc, a[i]);
    bool b = true;
    for(int i = 0; i < n; i++)    {
        b &= chk(a[i], cc);
    }
    if(b) printf("Yes"); else printf("No");
    return 0;
}
