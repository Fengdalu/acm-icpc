#include <iostream>
#include <cstdio>

long long gcd(long long a, long long b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int ii = 1; ii <= T; ii++) {
        long long s1, v1, s2, v2, n;
        std::cin >> n >> s1 >> v1 >> s2 >> v2;
        long long ans = 0;
        long long tot = n % lcm(s1, s2);
        n -= tot;
        long long r = lcm(s1, s2);
        if(n >= r) {
            tot += r;
            n -= r;
        }
        if(s1 < s2) {
            std::swap(s1, s2);
            std::swap(v1, v2);
        }
        long long sum = 0;
        for(long long t = 0; t * s1 <= tot; t++) {
            sum = std::max(sum, v1 * t + (tot - t * s1) / s2 * v2);
        }
        std::cout << "Case #" << ii << ": " << sum + std::max(n / s1 * v1, n / s2 * v2) << std::endl;
    }
}