#include <bits/stdc++.h>

int a[1000100];
int main() {
    int n, t; scanf("%d%d", &n, &t);
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    int pre = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] - a[i - 1] > t) {
            pre = i;
        }
    }
    std::cout << n - pre << std::endl;
    std::cout << std::endl;
    return 0;
}
