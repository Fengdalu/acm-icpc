#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const long long mod = 1e9 + 9LL;
const int maxk = 500;
long long f[maxk][maxk], g[maxk][maxk];
void add(long long &a, long long b) {
    a = (a + b) % mod;
}
int main() {
    int n, k;
    cin >> n >> k;
    g[0][0] = 1;
    for(int k = 0; k < n; k++) {
        memset(f, 0, sizeof f);
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n; j++) {
                add(f[i + 1][max(j, i + 1)], g[i][j]);
                add(f[i][j], g[i][j]);
                if(i) add(f[i - 1][j], g[i][j]);
            }
        swap(f, g);
    }
    cout << g[0][k] << endl;
    return 0;
}

