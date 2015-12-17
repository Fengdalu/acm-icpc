#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int ans = 1;
    for(int i = 2; i * i <= n; i++) if(n % i == 0){
        if(n % (i * i) == 0) ans = 0;
        else ans *= -1;
        while(n % i == 0) n /= i;
    }
    if(n != 1) ans *= -1;
    printf("%d\n", ans);
}
