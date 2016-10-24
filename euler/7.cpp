#include <bits/stdc++.h>

int main() {
    int N = 1e7;
    std::vector<int>primes;
    std::vector<bool> vis(N, 1);
    for(int i = 2; i < N; i++) {
        if(vis[i]) primes.push_back(i);
        for(int j = 0; j < primes.size() && primes[j] * i < N; j++) {
            vis[primes[j] * i] = false;
            if(i % primes[j] == 0) break;
        }
    }
    printf("%d\n", primes[5]);
    printf("%d\n", primes[10001 - 1]);
    return 0;
}
