#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a, b;
int n;

int main()
{
    scanf("%d", &n); a = b = 0; int x;
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        if(x == 5) a++; else b++;
    }
    a -= a % 9;
    if(a != 0 && b != 0) { for(int i = 0; i < a; i++) printf("5"); for(int i = 0; i < b; i++) printf("0"); }
    else if(b != 0) printf("0");
    else printf("-1");
    printf("\n");
    return 0;
}
