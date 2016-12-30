#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int left = 4 * 60 -  k;
    int t = 1;
    while(t * 5 <= left) {
        left -= t * 5;
        t++;
    }
    printf("%d\n", min(n, t - 1));
    return 0;
}
