#include <bits/stdc++.h>

int qpow(int a, int b) {
    int ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % 10;
        a = (a * a) % 10;
        b >>= 1;
    }
    return ans;
}

int main() {
    int n; scanf("%d", &n);
    printf("%d\n", qpow(1378, n));
    return 0;
}
