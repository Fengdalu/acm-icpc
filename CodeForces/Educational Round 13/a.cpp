#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;
int main() {
    ll n, k;
    cin >> n >> k;
    cout << n + (k - n % k) << endl;
}
