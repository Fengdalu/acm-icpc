#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
    long long n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        long long m = max(max(a + b + i, b + d + i), max(a + c + i, c + d + i));
        long long g = min(min(a + b + i, b + d + i), min(a + c + i, c + d + i));
        ans += n - (m - g);
    }
    cout << ans << endl;
}
