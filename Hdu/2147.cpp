#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        if(n % 3 != 0) printf("Kiki\n");
        else printf("Cici\n");
    }
    return 0;
}
