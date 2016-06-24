#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

int main() {
    ll tot = 0;
    for(ll x = -2e4; x <= 2e4; x++)
        for(ll y = -2e4; y <= 2e4; y++)
            if(x * x + y * y == 1e4 * 1e4) {
                cout << x << " " << y << endl;
            }
    return 0;
}
