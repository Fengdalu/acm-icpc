#include <bits/stdc++.h>

int f(int x) {
    int ans = 1;
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) {
            int tot = 0;
            while(x % i == 0) {
                x /= i;
                tot++;
            }
            ans *= (tot + 1);
        }
    }
    if(x > 1) ans *= 2;
    return ans;
}

int main() {
    int i = 1;
    while(true) {
        int x = (i + 1) * i / 2;
        if(f(x) > 500) {
            printf("%d\n", x);
            break;
        }
        i++;
    }
    return 0;
}
