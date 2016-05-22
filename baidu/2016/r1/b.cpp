#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

long long f[1000][2];
long long sum[1000];
int main() {
    f[1][0] = 1;
    f[1][1] = 0;
    f[2][0] = 1;
    f[2][1] = 1;
    for(int i = 3; i < 1000; i++) {
        f[i][0] = f[i - 1][0] + f[i - 1][1];
        f[i][1] = f[i - 1][0];
    }
    int n;
    while(cin >> n) { cout << f[n][0] + f[n][1] << endl; }
}

