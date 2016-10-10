#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 1000000;
int a[N+10];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    int seq = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] % 2) seq++;
    }
    printf("%d\n", abs(n - seq - seq));
    return 0;
}

