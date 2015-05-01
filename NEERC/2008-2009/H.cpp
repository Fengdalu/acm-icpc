#include <iostream>
#include <cstdio>
using namespace std;

int n;

int main()
{
    freopen("holes.in", "r", stdin);
    freopen("holes.out", "w", stdout);
    scanf("%d", &n);
    if(n == 0) { printf("1\n"); fclose(stdout); return 0; }
    if(n == 1) { printf("0\n"); fclose(stdout); return 0; }
    if(n & 1)
    {
        printf("4");
        for(int i = 0; i < n / 2; i++) printf("8");
        printf("\n");
    }
    else
        for(int i = 0; i < n / 2; i++) printf("8");
    printf("\n");
    fclose(stdout);
    return 0;
}