#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
    int n;
    cin >> n;
    if(n <= 2) cout << 0 << " " << n << endl;
    else cout << (n / 7) * 2 + int(n % 7 > 5)<< " " << (n / 7 * 2) + min(n % 7, 2);
}
