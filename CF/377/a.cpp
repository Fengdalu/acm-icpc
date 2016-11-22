#include <bits/stdc++.h>

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i < 100; i++) {
        if(i * n >= k && i * n % 10 - k == 0) {
            std::cout << i << std::endl;
            return 0;
        }
        if(i * n % 10 == 0) {
            std::cout << i << std::endl;
            return 0;
        }
    }
    return 0;
}
