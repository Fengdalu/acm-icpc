#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

double f[11][100];
int main() {
    int n, t;
    cin >> n >> t;
    f[1][1] = t;
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= i; j++)
            f[i][j] = max(0.0, f[i - 1][j] - 1) / 2 + max(0.0, f[i - 1][j - 1] - 1) / 2;
    }
    int tot = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
        if(f[i][j] >= 1.0)
            tot ++;
    cout << tot << endl;
}
