#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int x; scanf("%d", &x); x--;
        ans += 1ll * x;
        if(ans & 1) printf("1"); else printf("2");
        printf("\n");
    }
    return 0;
}

