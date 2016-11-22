#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int p, q;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        if(x == 1) p = i;
        if(x == n) q = i;
    }
    if(p > q) swap(p, q);
    int m = max(max(q - 1, n - q), max(p - 1, n - p));
    cout << m << endl;
}
