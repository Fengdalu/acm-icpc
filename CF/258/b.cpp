#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

int a[100010];
int main() {
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++)  scanf("%d", a + i);
    int L = 0, R = n - 1;
    while(L < n - 1 && a[L] < a[L + 1]) L++;
    while(R > 0 && a[R] > a[R - 1]) R--;
    if(L >= R) {
        puts("yes");
        puts("1 1");
        return 0;
    }
    if(L == 0 && R == n - 1) {
        for(int i = 0; i < n - 1; i++) {
            if(a[i] < a[i + 1]) {
                puts("no");
                return 0;
            }
        }
        puts("yes");
        printf("%d %d\n", 1, n);
        return 0;
    }
    if((L > 0 && a[L - 1] > a[R]) || (R < n - 1 && a[R + 1] < a[L])) {
        puts("no");
        return 0;
    }
    for(int i = L; i < R; i++) {
        if(a[i] < a[i + 1]) {
            puts("no");
            return 0;
        }
    }
    puts("yes");
    printf("%d %d\n", L + 1, 1 + R);
    return 0;
}

