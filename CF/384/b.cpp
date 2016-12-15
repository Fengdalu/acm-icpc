#include <bits/stdc++.h>

using namespace std;
long long cal(int x) {
    long long ans = 0;
    for(int i = 0; i <= x; i++) {
        ans = ans * 2 + 1;
    }
    return ans;
}

int sol(int n, long long k) {
    long long w = cal(n - 1);
    if(k == w + 1) return n + 1;
    if(k > w) return sol(n - 1, k - w - 1);
    return sol(n - 1, k);
}

int main() {
    int n; long long k;
    cin >> n >> k;
    printf("%d\n", sol(n, k));
    return 0;
}
