#include <bits/stdc++.h>

int main() {
    int N = 2e6+1;
    std::vector<int>primes;
    std::vector<bool> vis(N, 1);
    for(int i = 2; i < N; i++) {
        if(vis[i]) primes.push_back(i);
        for(int j = 0; j < primes.size() && primes[j] * i < N; j++) {
            vis[primes[j] * i] = false;
            if(i % primes[j] == 0) break;
        }
    }
    printf("%lld\n", std::accumulate(primes.begin(), primes.end(), 0ll));
    return 0;
}
